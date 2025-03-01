/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/core/auth/AWSAuthSigner.h>

#include <aws/core/auth/AWSCredentialsProvider.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/http/HttpRequest.h>
#include <aws/core/http/HttpResponse.h>
#include <aws/core/http/URI.h>
#include <aws/core/utils/DateTime.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/utils/Outcome.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/logging/LogMacros.h>
#include <aws/core/utils/memory/AWSMemory.h>
#include <aws/core/utils/crypto/Sha256.h>
#include <aws/core/utils/crypto/Sha256HMAC.h>
#include <aws/core/utils/stream/PreallocatedStreamBuf.h>
#include <aws/core/utils/event/EventMessage.h>
#include <aws/core/utils/event/EventHeader.h>

#include <aws/crt/auth/Credentials.h>
#include <aws/crt/http/HttpRequestResponse.h>

#include <cstdio>
#include <iomanip>
#include <math.h>
#include <cstring>

using namespace Aws;
using namespace Aws::Client;
using namespace Aws::Auth;
using namespace Aws::Http;
using namespace Aws::Utils;
using namespace Aws::Utils::Logging;

static const char* EQ = "=";
static const char* AWS_HMAC_SHA256 = "AWS4-HMAC-SHA256";
static const char* EVENT_STREAM_CONTENT_SHA256 = "STREAMING-AWS4-HMAC-SHA256-EVENTS";
static const char* EVENT_STREAM_PAYLOAD = "AWS4-HMAC-SHA256-PAYLOAD";
static const char* AWS4_REQUEST = "aws4_request";
static const char* SIGNED_HEADERS = "SignedHeaders";
static const char* CREDENTIAL = "Credential";
static const char* NEWLINE = "\n";
static const char* X_AMZ_SIGNED_HEADERS = "X-Amz-SignedHeaders";
static const char* X_AMZ_ALGORITHM = "X-Amz-Algorithm";
static const char* X_AMZ_CREDENTIAL = "X-Amz-Credential";
static const char* UNSIGNED_PAYLOAD = "UNSIGNED-PAYLOAD";
static const char* STREAMING_UNSIGNED_PAYLOAD_TRAILER = "STREAMING-UNSIGNED-PAYLOAD-TRAILER";
static const char* X_AMZ_SIGNATURE = "X-Amz-Signature";
static const char* X_AMZN_TRACE_ID = "x-amzn-trace-id";
static const char* X_AMZ_CONTENT_SHA256 = "x-amz-content-sha256";
static const char* USER_AGENT = "user-agent";
static const char* SIGNING_KEY = "AWS4";
static const char* SIMPLE_DATE_FORMAT_STR = "%Y%m%d";
static const char* EMPTY_STRING_SHA256 = "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855";

static const char v4LogTag[] = "AWSAuthV4Signer";
static const char v4AsymmetricLogTag[] = "AWSAuthSymmetricV4Signer";
static const char v4StreamingLogTag[] = "AWSAuthEventStreamV4Signer";

namespace Aws
{
    namespace Auth
    {
        const char SIGNATURE[] = "Signature";
        const char SIGV4_SIGNER[] = "SignatureV4";
        const char ASYMMETRIC_SIGV4_SIGNER[] = "AsymmetricSignatureV4";
        const char EVENTSTREAM_SIGV4_SIGNER[] = "EventStreamSignatureV4";
        const char EVENTSTREAM_SIGNATURE_HEADER[] = ":chunk-signature";
        const char EVENTSTREAM_DATE_HEADER[] = ":date";
        const char NULL_SIGNER[] = "NullSigner";
    }
}

static Aws::String CanonicalizeRequestSigningString(HttpRequest& request, bool urlEscapePath)
{
    request.CanonicalizeRequest();
    Aws::StringStream signingStringStream;
    signingStringStream << HttpMethodMapper::GetNameForHttpMethod(request.GetMethod());

    URI uriCpy = request.GetUri();
    // Many AWS services do not decode the URL before calculating SignatureV4 on their end.
    // This results in the signature getting calculated with a double encoded URL.
    // That means we have to double encode it here for the signature to match on the service side.
    if(urlEscapePath)
    {
        // RFC3986 is how we encode the URL before sending it on the wire.
        uriCpy.SetPath(uriCpy.GetURLEncodedPathRFC3986());
        // However, SignatureV4 uses this URL encoding scheme
        signingStringStream << NEWLINE << uriCpy.GetURLEncodedPath() << NEWLINE;
    }
    else
    {
        // For the services that DO decode the URL first; we don't need to double encode it.
        signingStringStream << NEWLINE << uriCpy.GetURLEncodedPath() << NEWLINE;
    }

    if (request.GetQueryString().find('=') != std::string::npos)
    {
        signingStringStream << request.GetQueryString().substr(1) << NEWLINE;
    }
    else if (request.GetQueryString().size() > 1)
    {
        signingStringStream << request.GetQueryString().substr(1) << "=" << NEWLINE;
    }
    else
    {
        signingStringStream << NEWLINE;
    }

    return signingStringStream.str();
}

static Http::HeaderValueCollection CanonicalizeHeaders(Http::HeaderValueCollection&& headers)
{
    Http::HeaderValueCollection canonicalHeaders;
    for (const auto& header : headers)
    {
        auto trimmedHeaderName = StringUtils::Trim(header.first.c_str());
        auto trimmedHeaderValue = StringUtils::Trim(header.second.c_str());

        //multiline gets converted to line1,line2,etc...
        auto headerMultiLine = StringUtils::SplitOnLine(trimmedHeaderValue);
        Aws::String headerValue = headerMultiLine.size() == 0 ? "" : headerMultiLine[0];

        if (headerMultiLine.size() > 1)
        {
            for(size_t i = 1; i < headerMultiLine.size(); ++i)
            {
                headerValue += " ";
                headerValue += StringUtils::Trim(headerMultiLine[i].c_str());
            }
        }

        //duplicate spaces need to be converted to one.
        Aws::String::iterator new_end =
            std::unique(headerValue.begin(), headerValue.end(),
                [=](char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); }
        );
        headerValue.erase(new_end, headerValue.end());

        canonicalHeaders[trimmedHeaderName] = headerValue;
    }

    return canonicalHeaders;
}

AWSAuthV4Signer::AWSAuthV4Signer(const std::shared_ptr<Auth::AWSCredentialsProvider>& credentialsProvider, const char* serviceName,
    const Aws::String& region, PayloadSigningPolicy signingPolicy, bool urlEscapePath, AWSSigningAlgorithm signingAlgorithm) :
    m_includeSha256HashHeader(true),
    m_signingAlgorithm(signingAlgorithm),
    m_credentialsProvider(credentialsProvider),
    m_serviceName(serviceName),
    m_region(region),
    m_hash(Aws::MakeUnique<Aws::Utils::Crypto::Sha256>(v4LogTag)),
    m_HMAC(Aws::MakeUnique<Aws::Utils::Crypto::Sha256HMAC>(v4LogTag)),
    m_unsignedHeaders({USER_AGENT, X_AMZN_TRACE_ID}),
    m_payloadSigningPolicy(signingPolicy),
    m_urlEscapePath(urlEscapePath)
{
    //go ahead and warm up the signing cache.
    ComputeHash(credentialsProvider->GetAWSCredentials().GetAWSSecretKey(), DateTime::CalculateGmtTimestampAsString(SIMPLE_DATE_FORMAT_STR), region, m_serviceName);
}

AWSAuthV4Signer::~AWSAuthV4Signer()
{
    // empty destructor in .cpp file to keep from needing the implementation of (AWSCredentialsProvider, Sha256, Sha256HMAC) in the header file
}

bool AWSAuthV4Signer::SignRequestWithSigV4a(Aws::Http::HttpRequest& request, const char* region, const char* serviceName,
    bool signBody, long long expirationTimeInSeconds, Aws::Crt::Auth::SignatureType signatureType) const
{
    AWSCredentials credentials = m_credentialsProvider->GetAWSCredentials();
    auto crtCredentials = Aws::MakeShared<Aws::Crt::Auth::Credentials>(v4AsymmetricLogTag,
        Aws::Crt::ByteCursorFromCString(credentials.GetAWSAccessKeyId().c_str()),
        Aws::Crt::ByteCursorFromCString(credentials.GetAWSSecretKey().c_str()),
        Aws::Crt::ByteCursorFromCString(credentials.GetSessionToken().c_str()),
        credentials.GetExpiration().Seconds());

    Aws::Crt::Auth::AwsSigningConfig awsSigningConfig;
    awsSigningConfig.SetSigningAlgorithm(static_cast<Aws::Crt::Auth::SigningAlgorithm>(AWSSigningAlgorithm::ASYMMETRIC_SIGV4));
    awsSigningConfig.SetSignatureType(signatureType);
    awsSigningConfig.SetRegion(region);
    awsSigningConfig.SetService(serviceName);
    awsSigningConfig.SetSigningTimepoint(GetSigningTimestamp().UnderlyingTimestamp());
    awsSigningConfig.SetUseDoubleUriEncode(m_urlEscapePath);
    awsSigningConfig.SetShouldNormalizeUriPath(true);
    awsSigningConfig.SetOmitSessionToken(false);
    awsSigningConfig.SetShouldSignHeaderUserData(reinterpret_cast<void*>(const_cast<Aws::Set<Aws::String>*>(&m_unsignedHeaders)));
    awsSigningConfig.SetShouldSignHeaderCallback([](const Aws::Crt::ByteCursor *name, void *user_data) {
        Aws::Set<Aws::String>* unsignedHeaders = static_cast<Aws::Set<Aws::String>*>(user_data);
        Aws::String headerKey(reinterpret_cast<const char*>(name->ptr), name->len);
        return unsignedHeaders->find(Aws::Utils::StringUtils::ToLower(headerKey.c_str())) == unsignedHeaders->cend();
    });
    if (signatureType == Aws::Crt::Auth::SignatureType::HttpRequestViaHeaders)
    {
        Aws::String payloadHash(UNSIGNED_PAYLOAD);
        if(signBody || request.GetUri().GetScheme() != Http::Scheme::HTTPS)
        {
            if (!request.GetContentBody())
            {
                AWS_LOGSTREAM_DEBUG(v4AsymmetricLogTag, "Using cached empty string sha256 " << EMPTY_STRING_SHA256 << " because payload is empty.");
                payloadHash = EMPTY_STRING_SHA256;
            }
            else
            {
                // The hash will be calculated from the payload during siging.
                payloadHash = {};
            }
        }
        else
        {
            AWS_LOGSTREAM_DEBUG(v4AsymmetricLogTag, "Note: Http payloads are not being signed. signPayloads=" << signBody
                    << " http scheme=" << Http::SchemeMapper::ToString(request.GetUri().GetScheme()));
        }
        awsSigningConfig.SetSignedBodyValue(payloadHash.c_str());
        awsSigningConfig.SetSignedBodyHeader(m_includeSha256HashHeader ? Aws::Crt::Auth::SignedBodyHeaderType::XAmzContentSha256 : Aws::Crt::Auth::SignedBodyHeaderType::None);
    }
    else if (signatureType == Aws::Crt::Auth::SignatureType::HttpRequestViaQueryParams)
    {
        if (ServiceRequireUnsignedPayload(serviceName))
        {
            awsSigningConfig.SetSignedBodyValue(UNSIGNED_PAYLOAD);
        }
        else
        {
            awsSigningConfig.SetSignedBodyValue(EMPTY_STRING_SHA256);
        }
    }
    else
    {
        AWS_LOGSTREAM_ERROR(v4AsymmetricLogTag, "The signature type should be either \"HttpRequestViaHeaders\" or \"HttpRequestViaQueryParams\"");
        return false;
    }
    awsSigningConfig.SetExpirationInSeconds(static_cast<uint64_t>(expirationTimeInSeconds));
    awsSigningConfig.SetCredentials(crtCredentials);

    std::shared_ptr<Aws::Crt::Http::HttpRequest> crtHttpRequest = request.ToCrtHttpRequest();

    auto sigv4HttpRequestSigner = Aws::MakeShared<Aws::Crt::Auth::Sigv4HttpRequestSigner>(v4AsymmetricLogTag);
    bool success = true;
    sigv4HttpRequestSigner->SignRequest(crtHttpRequest, awsSigningConfig,
        [&request, &success, signatureType](const std::shared_ptr<Aws::Crt::Http::HttpRequest>& signedCrtHttpRequest, int errorCode) {
            success = (errorCode == AWS_ERROR_SUCCESS);
            if (success)
            {
                if (signatureType == Aws::Crt::Auth::SignatureType::HttpRequestViaHeaders)
                {
                    for (size_t i = 0; i < signedCrtHttpRequest->GetHeaderCount(); i++)
                    {
                        Aws::Crt::Optional<Aws::Crt::Http::HttpHeader> httpHeader = signedCrtHttpRequest->GetHeader(i);
                        request.SetHeaderValue(Aws::String(reinterpret_cast<const char*>(httpHeader->name.ptr), httpHeader->name.len),
                            Aws::String(reinterpret_cast<const char*>(httpHeader->value.ptr), httpHeader->value.len));
                    }
                }
                else if (signatureType == Aws::Crt::Auth::SignatureType::HttpRequestViaQueryParams)
                {
                    Aws::Http::URI newPath(reinterpret_cast<const char*>(signedCrtHttpRequest->GetPath()->ptr));
                    request.GetUri().SetQueryString(newPath.GetQueryString());
                }
                else
                {
                    AWS_LOGSTREAM_ERROR(v4AsymmetricLogTag, "No action to take when signature type is neither \"HttpRequestViaHeaders\" nor \"HttpRequestViaQueryParams\"");
                    success = false;
                }
            }
            else
            {
                AWS_LOGSTREAM_ERROR(v4AsymmetricLogTag, "Encountered internal error during signing process with AWS signature version 4 (Asymmetric):" << aws_error_str(errorCode));
            }
        }
    );
    return success;
}

bool AWSAuthV4Signer::ShouldSignHeader(const Aws::String& header) const
{
    return m_unsignedHeaders.find(Aws::Utils::StringUtils::ToLower(header.c_str())) == m_unsignedHeaders.cend();
}

bool AWSAuthV4Signer::SignRequest(Aws::Http::HttpRequest& request, const char* region, const char* serviceName, bool signBody) const
{
    Aws::String signingRegion = region ? region : m_region;
    Aws::String signingServiceName = serviceName ? serviceName : m_serviceName;
    AWSCredentials credentials = m_credentialsProvider->GetAWSCredentials();

    //don't sign anonymous requests
    if (credentials.GetAWSAccessKeyId().empty() || credentials.GetAWSSecretKey().empty())
    {
        return true;
    }

    request.SetSigningAccessKey(credentials.GetAWSAccessKeyId());
    request.SetSigningRegion(signingRegion);

    Aws::String payloadHash(UNSIGNED_PAYLOAD);
    switch(m_payloadSigningPolicy)
    {
        case PayloadSigningPolicy::Always:
            signBody = true;
            break;
        case PayloadSigningPolicy::Never:
            signBody = false;
            break;
        case PayloadSigningPolicy::RequestDependent:
            // respect the request setting
        default:
            break;
    }

    if (m_signingAlgorithm == AWSSigningAlgorithm::ASYMMETRIC_SIGV4)
    {
        // Replace m_serviceName with signingServiceName after rebasing on S3 outposts.
        return SignRequestWithSigV4a(request, signingRegion.c_str(), m_serviceName.c_str(), signBody,
            0 /* expirationTimeInSeconds doesn't matter for HttpRequestViaHeaders */, Aws::Crt::Auth::SignatureType::HttpRequestViaHeaders);
    }

    if (!credentials.GetSessionToken().empty())
    {
        request.SetAwsSessionToken(credentials.GetSessionToken());
    }

    if(signBody || request.GetUri().GetScheme() != Http::Scheme::HTTPS)
    {
        payloadHash = ComputePayloadHash(request);
        if (payloadHash.empty())
        {
            return false;
        }
        if (request.GetRequestHash().second != nullptr)
        {
            Aws::String checksumHeaderKey = Aws::String("x-amz-checksum-") + request.GetRequestHash().first;
            Aws::String checksumHeaderValue = HashingUtils::Base64Encode(request.GetRequestHash().second->Calculate(*(request.GetContentBody())).GetResult());
            request.SetHeaderValue(checksumHeaderKey, checksumHeaderValue);
            request.SetRequestHash("", nullptr);
        }
    }
    else
    {
        AWS_LOGSTREAM_DEBUG(v4LogTag, "Note: Http payloads are not being signed. signPayloads=" << signBody
                << " http scheme=" << Http::SchemeMapper::ToString(request.GetUri().GetScheme()));
        if (request.GetRequestHash().second != nullptr)
        {
            payloadHash = STREAMING_UNSIGNED_PAYLOAD_TRAILER;
            Aws::String trailerHeaderValue = Aws::String("x-amz-checksum-") + request.GetRequestHash().first;
            request.SetHeaderValue(Http::AWS_TRAILER_HEADER, trailerHeaderValue);
            request.SetTransferEncoding(CHUNKED_VALUE);
            request.SetHeaderValue(Http::CONTENT_ENCODING_HEADER, Http::AWS_CHUNKED_VALUE);
            request.SetHeaderValue(Http::DECODED_CONTENT_LENGTH_HEADER, request.GetHeaderValue(Http::CONTENT_LENGTH_HEADER));
            request.DeleteHeader(Http::CONTENT_LENGTH_HEADER);
        }
    }

    if(m_includeSha256HashHeader)
    {
        request.SetHeaderValue(X_AMZ_CONTENT_SHA256, payloadHash);
    }

    //calculate date header to use in internal signature (this also goes into date header).
    DateTime now = GetSigningTimestamp();
    Aws::String dateHeaderValue = now.ToGmtString(DateFormat::ISO_8601_BASIC);
    request.SetHeaderValue(AWS_DATE_HEADER, dateHeaderValue);

    Aws::StringStream headersStream;
    Aws::StringStream signedHeadersStream;

    for (const auto& header : CanonicalizeHeaders(request.GetHeaders()))
    {
        if(ShouldSignHeader(header.first))
        {
            headersStream << header.first.c_str() << ":" << header.second.c_str() << NEWLINE;
            signedHeadersStream << header.first.c_str() << ";";
        }
    }

    Aws::String canonicalHeadersString = headersStream.str();
    AWS_LOGSTREAM_DEBUG(v4LogTag, "Canonical Header String: " << canonicalHeadersString);

    //calculate signed headers parameter
    Aws::String signedHeadersValue = signedHeadersStream.str();
    //remove that last semi-colon
    if (!signedHeadersValue.empty())
    {
        signedHeadersValue.pop_back();
    }

    AWS_LOGSTREAM_DEBUG(v4LogTag, "Signed Headers value:" << signedHeadersValue);

    //generate generalized canonicalized request string.
    Aws::String canonicalRequestString = CanonicalizeRequestSigningString(request, m_urlEscapePath);

    //append v4 stuff to the canonical request string.
    canonicalRequestString.append(canonicalHeadersString);
    canonicalRequestString.append(NEWLINE);
    canonicalRequestString.append(signedHeadersValue);
    canonicalRequestString.append(NEWLINE);
    canonicalRequestString.append(payloadHash);

    AWS_LOGSTREAM_DEBUG(v4LogTag, "Canonical Request String: " << canonicalRequestString);

    //now compute sha256 on that request string
    auto hashResult = m_hash->Calculate(canonicalRequestString);
    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4LogTag, "Failed to hash (sha256) request string");
        AWS_LOGSTREAM_DEBUG(v4LogTag, "The request string is: \"" << canonicalRequestString << "\"");
        return false;
    }

    auto sha256Digest = hashResult.GetResult();
    Aws::String canonicalRequestHash = HashingUtils::HexEncode(sha256Digest);
    Aws::String simpleDate = now.ToGmtString(SIMPLE_DATE_FORMAT_STR);

    Aws::String stringToSign = GenerateStringToSign(dateHeaderValue, simpleDate, canonicalRequestHash, signingRegion, signingServiceName);
    auto finalSignature = GenerateSignature(credentials, stringToSign, simpleDate, signingRegion, signingServiceName);

    Aws::StringStream ss;
    ss << AWS_HMAC_SHA256 << " " << CREDENTIAL << EQ << credentials.GetAWSAccessKeyId() << "/" << simpleDate
        << "/" << signingRegion << "/" << signingServiceName << "/" << AWS4_REQUEST << ", " << SIGNED_HEADERS << EQ
        << signedHeadersValue << ", " << SIGNATURE << EQ << finalSignature;

    auto awsAuthString = ss.str();
    AWS_LOGSTREAM_DEBUG(v4LogTag, "Signing request with: " << awsAuthString);
    request.SetAwsAuthorization(awsAuthString);
    return true;
}

bool AWSAuthV4Signer::PresignRequest(Aws::Http::HttpRequest& request, long long expirationTimeInSeconds) const
{
    return PresignRequest(request, m_region.c_str(), expirationTimeInSeconds);
}

bool AWSAuthV4Signer::PresignRequest(Aws::Http::HttpRequest& request, const char* region, long long expirationInSeconds) const
{
    return PresignRequest(request, region, m_serviceName.c_str(), expirationInSeconds);
}

bool AWSAuthV4Signer::PresignRequest(Aws::Http::HttpRequest& request, const char* region, const char* serviceName, long long expirationTimeInSeconds) const
{
    Aws::String signingRegion = region ? region : m_region;
    Aws::String signingServiceName = serviceName ? serviceName : m_serviceName;
    AWSCredentials credentials = m_credentialsProvider->GetAWSCredentials();

    //don't sign anonymous requests
    if (credentials.GetAWSAccessKeyId().empty() || credentials.GetAWSSecretKey().empty())
    {
        return true;
    }

    if (m_signingAlgorithm == AWSSigningAlgorithm::ASYMMETRIC_SIGV4)
    {
        return SignRequestWithSigV4a(request, signingRegion.c_str(), signingServiceName.c_str(), false /* signBody doesn't matter for HttpRequestViaHeaders */,
            expirationTimeInSeconds, Aws::Crt::Auth::SignatureType::HttpRequestViaQueryParams);
    }

    Aws::StringStream intConversionStream;
    intConversionStream << expirationTimeInSeconds;
    request.AddQueryStringParameter(Http::X_AMZ_EXPIRES_HEADER, intConversionStream.str());

    if (!credentials.GetSessionToken().empty())
    {
        request.AddQueryStringParameter(Http::AWS_SECURITY_TOKEN, credentials.GetSessionToken());
    }

    //calculate date header to use in internal signature (this also goes into date header).
    DateTime now = GetSigningTimestamp();
    Aws::String dateQueryValue = now.ToGmtString(DateFormat::ISO_8601_BASIC);
    request.AddQueryStringParameter(Http::AWS_DATE_HEADER, dateQueryValue);

    Aws::StringStream headersStream;
    Aws::StringStream signedHeadersStream;
    for (const auto& header : CanonicalizeHeaders(request.GetHeaders()))
    {
        if(ShouldSignHeader(header.first))
        {
            headersStream << header.first.c_str() << ":" << header.second.c_str() << NEWLINE;
            signedHeadersStream << header.first.c_str() << ";";
        }
    }

    Aws::String canonicalHeadersString = headersStream.str();
    AWS_LOGSTREAM_DEBUG(v4LogTag, "Canonical Header String: " << canonicalHeadersString);

    //calculate signed headers parameter
    Aws::String signedHeadersValue(signedHeadersStream.str());
    //remove that last semi-colon
    if (!signedHeadersValue.empty())
    {
        signedHeadersValue.pop_back();
    }

    request.AddQueryStringParameter(X_AMZ_SIGNED_HEADERS, signedHeadersValue);
    AWS_LOGSTREAM_DEBUG(v4LogTag, "Signed Headers value: " << signedHeadersValue);

    Aws::StringStream ss;
    Aws::String simpleDate = now.ToGmtString(SIMPLE_DATE_FORMAT_STR);
    ss << credentials.GetAWSAccessKeyId() << "/" << simpleDate
        << "/" << signingRegion << "/" << signingServiceName << "/" << AWS4_REQUEST;

    request.AddQueryStringParameter(X_AMZ_ALGORITHM, AWS_HMAC_SHA256);
    request.AddQueryStringParameter(X_AMZ_CREDENTIAL, ss.str());
    ss.str("");

    request.SetSigningAccessKey(credentials.GetAWSAccessKeyId());
    request.SetSigningRegion(signingRegion);

    //generate generalized canonicalized request string.
    Aws::String canonicalRequestString = CanonicalizeRequestSigningString(request, m_urlEscapePath);

    //append v4 stuff to the canonical request string.
    canonicalRequestString.append(canonicalHeadersString);
    canonicalRequestString.append(NEWLINE);
    canonicalRequestString.append(signedHeadersValue);
    canonicalRequestString.append(NEWLINE);
    if (ServiceRequireUnsignedPayload(signingServiceName))
    {
        canonicalRequestString.append(UNSIGNED_PAYLOAD);
    }
    else
    {
        canonicalRequestString.append(EMPTY_STRING_SHA256);
    }
    AWS_LOGSTREAM_DEBUG(v4LogTag, "Canonical Request String: " << canonicalRequestString);

    //now compute sha256 on that request string
    auto hashResult = m_hash->Calculate(canonicalRequestString);
    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4LogTag, "Failed to hash (sha256) request string");
        AWS_LOGSTREAM_DEBUG(v4LogTag, "The request string is: \"" << canonicalRequestString << "\"");
        return false;
    }

    auto sha256Digest = hashResult.GetResult();
    auto canonicalRequestHash = HashingUtils::HexEncode(sha256Digest);

    auto stringToSign = GenerateStringToSign(dateQueryValue, simpleDate, canonicalRequestHash, signingRegion, signingServiceName);
    auto finalSigningHash = GenerateSignature(credentials, stringToSign, simpleDate, signingRegion, signingServiceName);
    if (finalSigningHash.empty())
    {
        return false;
    }

    //add that the signature to the query string
    request.AddQueryStringParameter(X_AMZ_SIGNATURE, finalSigningHash);

    return true;
}

bool AWSAuthV4Signer::ServiceRequireUnsignedPayload(const Aws::String& serviceName) const
{
    // S3 uses a magic string (instead of the empty string) for its body hash for presigned URLs as outlined here:
    // https://docs.aws.amazon.com/AmazonS3/latest/API/sigv4-query-string-auth.html
    // this is true for PUT, POST, GET, DELETE and HEAD operations.
    // However, other services (for example RDS) implement the specification as outlined here:
    // https://docs.aws.amazon.com/general/latest/gr/sigv4-create-canonical-request.html
    // which states that body-less requests should use the empty-string SHA256 hash.
    return "s3" == serviceName || "s3-object-lambda" == serviceName;
}

Aws::String AWSAuthV4Signer::GenerateSignature(const AWSCredentials& credentials, const Aws::String& stringToSign,
        const Aws::String& simpleDate, const Aws::String& region, const Aws::String& serviceName) const
{
    auto key = ComputeHash(credentials.GetAWSSecretKey(), simpleDate, region, serviceName);
    return GenerateSignature(stringToSign, key);
}

Aws::String AWSAuthV4Signer::GenerateSignature(const Aws::String& stringToSign, const ByteBuffer& key) const
{
    AWS_LOGSTREAM_DEBUG(v4LogTag, "Final String to sign: " << stringToSign);

    Aws::StringStream ss;

    auto hashResult = m_HMAC->Calculate(ByteBuffer((unsigned char*)stringToSign.c_str(), stringToSign.length()), key);
    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4LogTag, "Unable to hmac (sha256) final string");
        AWS_LOGSTREAM_DEBUG(v4LogTag, "The final string is: \"" << stringToSign << "\"");
        return {};
    }

    //now we finally sign our request string with our hex encoded derived hash.
    auto finalSigningDigest = hashResult.GetResult();

    auto finalSigningHash = HashingUtils::HexEncode(finalSigningDigest);
    AWS_LOGSTREAM_DEBUG(v4LogTag, "Final computed signing hash: " << finalSigningHash);

    return finalSigningHash;
}

Aws::String AWSAuthV4Signer::ComputePayloadHash(Aws::Http::HttpRequest& request) const
{
    if (!request.GetContentBody())
    {
        AWS_LOGSTREAM_DEBUG(v4LogTag, "Using cached empty string sha256 " << EMPTY_STRING_SHA256 << " because payload is empty.");
        return EMPTY_STRING_SHA256;
    }

    //compute hash on payload if it exists.
    auto hashResult =  m_hash->Calculate(*request.GetContentBody());

    if(request.GetContentBody())
    {
        request.GetContentBody()->clear();
        request.GetContentBody()->seekg(0);
    }

    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4LogTag, "Unable to hash (sha256) request body");
        return {};
    }

    auto sha256Digest = hashResult.GetResult();

    Aws::String payloadHash(HashingUtils::HexEncode(sha256Digest));
    AWS_LOGSTREAM_DEBUG(v4LogTag, "Calculated sha256 " << payloadHash << " for payload.");
    return payloadHash;
}

Aws::String AWSAuthV4Signer::GenerateStringToSign(const Aws::String& dateValue, const Aws::String& simpleDate,
        const Aws::String& canonicalRequestHash, const Aws::String& region, const Aws::String& serviceName) const
{
    //generate the actual string we will use in signing the final request.
    Aws::StringStream ss;

    ss << AWS_HMAC_SHA256 << NEWLINE << dateValue << NEWLINE << simpleDate << "/" << region << "/"
        << serviceName << "/" << AWS4_REQUEST << NEWLINE << canonicalRequestHash;

    return ss.str();
}

Aws::Utils::ByteBuffer AWSAuthV4Signer::ComputeHash(const Aws::String& secretKey,
        const Aws::String& simpleDate, const Aws::String& region, const Aws::String& serviceName) const
{
    Aws::String signingKey(SIGNING_KEY);
    signingKey.append(secretKey);
    auto hashResult = m_HMAC->Calculate(ByteBuffer((unsigned char*)simpleDate.c_str(), simpleDate.length()),
            ByteBuffer((unsigned char*)signingKey.c_str(), signingKey.length()));

    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4LogTag, "Failed to HMAC (SHA256) date string \"" << simpleDate << "\"");
        return {};
    }

    auto kDate = hashResult.GetResult();
    hashResult = m_HMAC->Calculate(ByteBuffer((unsigned char*)region.c_str(), region.length()), kDate);
    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4LogTag, "Failed to HMAC (SHA256) region string \"" << region << "\"");
        return {};
    }

    auto kRegion = hashResult.GetResult();
    hashResult = m_HMAC->Calculate(ByteBuffer((unsigned char*)serviceName.c_str(), serviceName.length()), kRegion);
    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4LogTag, "Failed to HMAC (SHA256) service string \"" << m_serviceName << "\"");
        return {};
    }

    auto kService = hashResult.GetResult();
    hashResult = m_HMAC->Calculate(ByteBuffer((unsigned char*)AWS4_REQUEST, strlen(AWS4_REQUEST)), kService);
    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4LogTag, "Unable to HMAC (SHA256) request string");
        AWS_LOGSTREAM_DEBUG(v4LogTag, "The request string is: \"" << AWS4_REQUEST << "\"");
        return {};
    }
    return hashResult.GetResult();
}

AWSAuthEventStreamV4Signer::AWSAuthEventStreamV4Signer(const std::shared_ptr<Auth::AWSCredentialsProvider>&
        credentialsProvider, const char* serviceName, const Aws::String& region) :
    m_serviceName(serviceName),
    m_region(region),
    m_credentialsProvider(credentialsProvider)
{

    m_unsignedHeaders.emplace_back(X_AMZN_TRACE_ID);
    m_unsignedHeaders.emplace_back(USER_AGENT_HEADER);
}

bool AWSAuthEventStreamV4Signer::SignRequest(Aws::Http::HttpRequest& request, const char* region, const char* serviceName, bool /* signBody */) const
{
    AWSCredentials credentials = m_credentialsProvider->GetAWSCredentials();

    //don't sign anonymous requests
    if (credentials.GetAWSAccessKeyId().empty() || credentials.GetAWSSecretKey().empty())
    {
        return true;
    }

    if (!credentials.GetSessionToken().empty())
    {
        request.SetAwsSessionToken(credentials.GetSessionToken());
    }

    request.SetHeaderValue(X_AMZ_CONTENT_SHA256, EVENT_STREAM_CONTENT_SHA256);

    //calculate date header to use in internal signature (this also goes into date header).
    DateTime now = GetSigningTimestamp();
    Aws::String dateHeaderValue = now.ToGmtString(DateFormat::ISO_8601_BASIC);
    request.SetHeaderValue(AWS_DATE_HEADER, dateHeaderValue);

    Aws::StringStream headersStream;
    Aws::StringStream signedHeadersStream;

    for (const auto& header : CanonicalizeHeaders(request.GetHeaders()))
    {
        if(ShouldSignHeader(header.first))
        {
            headersStream << header.first.c_str() << ":" << header.second.c_str() << NEWLINE;
            signedHeadersStream << header.first.c_str() << ";";
        }
    }

    Aws::String canonicalHeadersString = headersStream.str();
    AWS_LOGSTREAM_DEBUG(v4StreamingLogTag, "Canonical Header String: " << canonicalHeadersString);

    //calculate signed headers parameter
    Aws::String signedHeadersValue = signedHeadersStream.str();
    //remove that last semi-colon
    if (!signedHeadersValue.empty())
    {
        signedHeadersValue.pop_back();
    }

    AWS_LOGSTREAM_DEBUG(v4StreamingLogTag, "Signed Headers value:" << signedHeadersValue);

    //generate generalized canonicalized request string.
    Aws::String canonicalRequestString = CanonicalizeRequestSigningString(request, true/* m_urlEscapePath */);

    //append v4 stuff to the canonical request string.
    canonicalRequestString.append(canonicalHeadersString);
    canonicalRequestString.append(NEWLINE);
    canonicalRequestString.append(signedHeadersValue);
    canonicalRequestString.append(NEWLINE);
    canonicalRequestString.append(EVENT_STREAM_CONTENT_SHA256);

    AWS_LOGSTREAM_DEBUG(v4StreamingLogTag, "Canonical Request String: " << canonicalRequestString);

    //now compute sha256 on that request string
    auto hashResult = m_hash.Calculate(canonicalRequestString);
    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4StreamingLogTag, "Failed to hash (sha256) request string");
        AWS_LOGSTREAM_DEBUG(v4StreamingLogTag, "The request string is: \"" << canonicalRequestString << "\"");
        return false;
    }

    auto sha256Digest = hashResult.GetResult();
    Aws::String canonicalRequestHash = HashingUtils::HexEncode(sha256Digest);
    Aws::String simpleDate = now.ToGmtString(SIMPLE_DATE_FORMAT_STR);

    Aws::String signingRegion = region ? region : m_region;
    Aws::String signingServiceName = serviceName ? serviceName : m_serviceName;
    Aws::String stringToSign = GenerateStringToSign(dateHeaderValue, simpleDate, canonicalRequestHash, signingRegion, signingServiceName);
    auto finalSignature = GenerateSignature(credentials, stringToSign, simpleDate, signingRegion, signingServiceName);

    Aws::StringStream ss;
    ss << AWS_HMAC_SHA256 << " " << CREDENTIAL << EQ << credentials.GetAWSAccessKeyId() << "/" << simpleDate
        << "/" << signingRegion << "/" << signingServiceName << "/" << AWS4_REQUEST << ", " << SIGNED_HEADERS << EQ
        << signedHeadersValue << ", " << SIGNATURE << EQ << HashingUtils::HexEncode(finalSignature);

    auto awsAuthString = ss.str();
    AWS_LOGSTREAM_DEBUG(v4StreamingLogTag, "Signing request with: " << awsAuthString);
    request.SetAwsAuthorization(awsAuthString);
    request.SetSigningAccessKey(credentials.GetAWSAccessKeyId());
    request.SetSigningRegion(signingRegion);
    return true;
}

// this works regardless if the current machine is Big/Little Endian
static void WriteBigEndian(Aws::String& str, uint64_t n)
{
    int shift = 56;
    while(shift >= 0)
    {
        str.push_back((n >> shift) & 0xFF);
        shift -= 8;
    }
}

bool AWSAuthEventStreamV4Signer::SignEventMessage(Event::Message& message, Aws::String& priorSignature) const
{
    using Event::EventHeaderValue;

    Aws::StringStream stringToSign;
    stringToSign << EVENT_STREAM_PAYLOAD << NEWLINE;
    const DateTime now = GetSigningTimestamp();
    const auto simpleDate = now.ToGmtString(SIMPLE_DATE_FORMAT_STR);
    stringToSign << now.ToGmtString(DateFormat::ISO_8601_BASIC) << NEWLINE
        <<  simpleDate << "/" << m_region << "/"
        << m_serviceName << "/aws4_request" << NEWLINE << priorSignature << NEWLINE;


    Aws::String nonSignatureHeaders;
    nonSignatureHeaders.push_back(char(sizeof(EVENTSTREAM_DATE_HEADER) - 1)); // length of the string
    nonSignatureHeaders += EVENTSTREAM_DATE_HEADER;
    nonSignatureHeaders.push_back(static_cast<char>(EventHeaderValue::EventHeaderType::TIMESTAMP)); // type of the value
    WriteBigEndian(nonSignatureHeaders, static_cast<uint64_t>(now.Millis())); // the value of the timestamp in big-endian

    auto hashOutcome = m_hash.Calculate(nonSignatureHeaders);
    if (!hashOutcome.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4StreamingLogTag, "Failed to hash (sha256) non-signature headers.");
        return false;
    }

    const auto nonSignatureHeadersHash = hashOutcome.GetResult();
    stringToSign << HashingUtils::HexEncode(nonSignatureHeadersHash) << NEWLINE;

    if (message.GetEventPayload().empty())
    {
        AWS_LOGSTREAM_WARN(v4StreamingLogTag, "Attempting to sign an empty message (no payload and no headers). "
                "It is unlikely that this is the intended behavior.");
    }
    else
    {
        // use a preallocatedStreamBuf to avoid making a copy.
        // The Hashing API requires either Aws::String or IStream as input.
        // TODO: the hashing API should be accept 'unsigned char*' as input.
        Utils::Stream::PreallocatedStreamBuf streamBuf(message.GetEventPayload().data(), message.GetEventPayload().size());
        Aws::IOStream payload(&streamBuf);
        hashOutcome = m_hash.Calculate(payload);

        if (!hashOutcome.IsSuccess())
        {
            AWS_LOGSTREAM_ERROR(v4StreamingLogTag, "Failed to hash (sha256) non-signature headers.");
            return false;
        }
        const auto payloadHash = hashOutcome.GetResult();
        stringToSign << HashingUtils::HexEncode(payloadHash);
        AWS_LOGSTREAM_DEBUG(v4StreamingLogTag, "Payload hash  - " << HashingUtils::HexEncode(payloadHash));
    }

    Utils::ByteBuffer finalSignatureDigest = GenerateSignature(m_credentialsProvider->GetAWSCredentials(), stringToSign.str(), simpleDate, m_region, m_serviceName);
    const auto finalSignature = HashingUtils::HexEncode(finalSignatureDigest);
    AWS_LOGSTREAM_DEBUG(v4StreamingLogTag, "Final computed signing hash: " << finalSignature);
    priorSignature = finalSignature;

    message.InsertEventHeader(EVENTSTREAM_DATE_HEADER, EventHeaderValue(now.Millis(), EventHeaderValue::EventHeaderType::TIMESTAMP));
    message.InsertEventHeader(EVENTSTREAM_SIGNATURE_HEADER, std::move(finalSignatureDigest));

    AWS_LOGSTREAM_INFO(v4StreamingLogTag, "Event chunk final signature - " << finalSignature);
    return true;
}

bool AWSAuthEventStreamV4Signer::ShouldSignHeader(const Aws::String& header) const
{
    return std::find(m_unsignedHeaders.cbegin(), m_unsignedHeaders.cend(), Aws::Utils::StringUtils::ToLower(header.c_str())) == m_unsignedHeaders.cend();
}

Utils::ByteBuffer AWSAuthEventStreamV4Signer::GenerateSignature(const AWSCredentials& credentials, const Aws::String& stringToSign,
        const Aws::String& simpleDate, const Aws::String& region, const Aws::String& serviceName) const
{
    Utils::Threading::ReaderLockGuard guard(m_derivedKeyLock);
    const auto& secretKey = credentials.GetAWSSecretKey();
    if (secretKey != m_currentSecretKey || simpleDate != m_currentDateStr)
    {
        guard.UpgradeToWriterLock();
        // double-checked lock to prevent updating twice
        if (m_currentDateStr != simpleDate || m_currentSecretKey != secretKey)
        {
            m_currentSecretKey = secretKey;
            m_currentDateStr = simpleDate;
            m_derivedKey = ComputeHash(m_currentSecretKey, m_currentDateStr, region, serviceName);
        }

    }
    return GenerateSignature(stringToSign, m_derivedKey);
}

Utils::ByteBuffer AWSAuthEventStreamV4Signer::GenerateSignature(const Aws::String& stringToSign, const ByteBuffer& key) const
{
    AWS_LOGSTREAM_DEBUG(v4StreamingLogTag, "Final String to sign: " << stringToSign);

    Aws::StringStream ss;

    auto hashResult = m_HMAC.Calculate(ByteBuffer((unsigned char*)stringToSign.c_str(), stringToSign.length()), key);
    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4StreamingLogTag, "Unable to hmac (sha256) final string");
        AWS_LOGSTREAM_DEBUG(v4StreamingLogTag, "The final string is: \"" << stringToSign << "\"");
        return {};
    }

    return hashResult.GetResult();
}

Aws::String AWSAuthEventStreamV4Signer::GenerateStringToSign(const Aws::String& dateValue, const Aws::String& simpleDate,
        const Aws::String& canonicalRequestHash, const Aws::String& region, const Aws::String& serviceName) const
{
    //generate the actual string we will use in signing the final request.
    Aws::StringStream ss;

    ss << AWS_HMAC_SHA256 << NEWLINE << dateValue << NEWLINE << simpleDate << "/" << region << "/"
        << serviceName << "/" << AWS4_REQUEST << NEWLINE << canonicalRequestHash;

    return ss.str();
}

Aws::Utils::ByteBuffer AWSAuthEventStreamV4Signer::ComputeHash(const Aws::String& secretKey,
        const Aws::String& simpleDate, const Aws::String& region, const Aws::String& serviceName) const
{
    Aws::String signingKey(SIGNING_KEY);
    signingKey.append(secretKey);
    auto hashResult = m_HMAC.Calculate(ByteBuffer((unsigned char*)simpleDate.c_str(), simpleDate.length()),
            ByteBuffer((unsigned char*)signingKey.c_str(), signingKey.length()));

    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4StreamingLogTag, "Failed to HMAC (SHA256) date string \"" << simpleDate << "\"");
        return {};
    }

    auto kDate = hashResult.GetResult();
    hashResult = m_HMAC.Calculate(ByteBuffer((unsigned char*)region.c_str(), region.length()), kDate);
    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4StreamingLogTag, "Failed to HMAC (SHA256) region string \"" << region << "\"");
        return {};
    }

    auto kRegion = hashResult.GetResult();
    hashResult = m_HMAC.Calculate(ByteBuffer((unsigned char*)serviceName.c_str(), serviceName.length()), kRegion);
    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4StreamingLogTag, "Failed to HMAC (SHA256) service string \"" << m_serviceName << "\"");
        return {};
    }

    auto kService = hashResult.GetResult();
    hashResult = m_HMAC.Calculate(ByteBuffer((unsigned char*)AWS4_REQUEST, strlen(AWS4_REQUEST)), kService);
    if (!hashResult.IsSuccess())
    {
        AWS_LOGSTREAM_ERROR(v4StreamingLogTag, "Unable to HMAC (SHA256) request string");
        AWS_LOGSTREAM_DEBUG(v4StreamingLogTag, "The request string is: \"" << AWS4_REQUEST << "\"");
        return {};
    }
    return hashResult.GetResult();
}
