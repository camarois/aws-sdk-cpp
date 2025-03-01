﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/awstransfer/Transfer_EXPORTS.h>
#include <aws/awstransfer/TransferRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/awstransfer/model/Domain.h>
#include <aws/awstransfer/model/EndpointDetails.h>
#include <aws/awstransfer/model/EndpointType.h>
#include <aws/awstransfer/model/IdentityProviderDetails.h>
#include <aws/awstransfer/model/IdentityProviderType.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/awstransfer/model/ProtocolDetails.h>
#include <aws/awstransfer/model/WorkflowDetails.h>
#include <aws/awstransfer/model/Protocol.h>
#include <aws/awstransfer/model/Tag.h>
#include <utility>

namespace Aws
{
namespace Transfer
{
namespace Model
{

  /**
   */
  class AWS_TRANSFER_API CreateServerRequest : public TransferRequest
  {
  public:
    CreateServerRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "CreateServer"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The Amazon Resource Name (ARN) of the Amazon Web Services Certificate Manager
     * (ACM) certificate. Required when <code>Protocols</code> is set to
     * <code>FTPS</code>.</p> <p>To request a new public certificate, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-public.html">Request
     * a public certificate</a> in the <i> Amazon Web Services Certificate Manager User
     * Guide</i>.</p> <p>To import an existing certificate into ACM, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/import-certificate.html">Importing
     * certificates into ACM</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>To request a private certificate to use FTPS through
     * private IP addresses, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-private.html">Request
     * a private certificate</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>Certificates with the following cryptographic algorithms
     * and key sizes are supported:</p> <ul> <li> <p>2048-bit RSA (RSA_2048)</p> </li>
     * <li> <p>4096-bit RSA (RSA_4096)</p> </li> <li> <p>Elliptic Prime Curve 256 bit
     * (EC_prime256v1)</p> </li> <li> <p>Elliptic Prime Curve 384 bit
     * (EC_secp384r1)</p> </li> <li> <p>Elliptic Prime Curve 521 bit (EC_secp521r1)</p>
     * </li> </ul>  <p>The certificate must be a valid SSL/TLS X.509 version 3
     * certificate with FQDN or IP address specified and information about the
     * issuer.</p> 
     */
    inline const Aws::String& GetCertificate() const{ return m_certificate; }

    /**
     * <p>The Amazon Resource Name (ARN) of the Amazon Web Services Certificate Manager
     * (ACM) certificate. Required when <code>Protocols</code> is set to
     * <code>FTPS</code>.</p> <p>To request a new public certificate, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-public.html">Request
     * a public certificate</a> in the <i> Amazon Web Services Certificate Manager User
     * Guide</i>.</p> <p>To import an existing certificate into ACM, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/import-certificate.html">Importing
     * certificates into ACM</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>To request a private certificate to use FTPS through
     * private IP addresses, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-private.html">Request
     * a private certificate</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>Certificates with the following cryptographic algorithms
     * and key sizes are supported:</p> <ul> <li> <p>2048-bit RSA (RSA_2048)</p> </li>
     * <li> <p>4096-bit RSA (RSA_4096)</p> </li> <li> <p>Elliptic Prime Curve 256 bit
     * (EC_prime256v1)</p> </li> <li> <p>Elliptic Prime Curve 384 bit
     * (EC_secp384r1)</p> </li> <li> <p>Elliptic Prime Curve 521 bit (EC_secp521r1)</p>
     * </li> </ul>  <p>The certificate must be a valid SSL/TLS X.509 version 3
     * certificate with FQDN or IP address specified and information about the
     * issuer.</p> 
     */
    inline bool CertificateHasBeenSet() const { return m_certificateHasBeenSet; }

    /**
     * <p>The Amazon Resource Name (ARN) of the Amazon Web Services Certificate Manager
     * (ACM) certificate. Required when <code>Protocols</code> is set to
     * <code>FTPS</code>.</p> <p>To request a new public certificate, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-public.html">Request
     * a public certificate</a> in the <i> Amazon Web Services Certificate Manager User
     * Guide</i>.</p> <p>To import an existing certificate into ACM, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/import-certificate.html">Importing
     * certificates into ACM</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>To request a private certificate to use FTPS through
     * private IP addresses, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-private.html">Request
     * a private certificate</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>Certificates with the following cryptographic algorithms
     * and key sizes are supported:</p> <ul> <li> <p>2048-bit RSA (RSA_2048)</p> </li>
     * <li> <p>4096-bit RSA (RSA_4096)</p> </li> <li> <p>Elliptic Prime Curve 256 bit
     * (EC_prime256v1)</p> </li> <li> <p>Elliptic Prime Curve 384 bit
     * (EC_secp384r1)</p> </li> <li> <p>Elliptic Prime Curve 521 bit (EC_secp521r1)</p>
     * </li> </ul>  <p>The certificate must be a valid SSL/TLS X.509 version 3
     * certificate with FQDN or IP address specified and information about the
     * issuer.</p> 
     */
    inline void SetCertificate(const Aws::String& value) { m_certificateHasBeenSet = true; m_certificate = value; }

    /**
     * <p>The Amazon Resource Name (ARN) of the Amazon Web Services Certificate Manager
     * (ACM) certificate. Required when <code>Protocols</code> is set to
     * <code>FTPS</code>.</p> <p>To request a new public certificate, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-public.html">Request
     * a public certificate</a> in the <i> Amazon Web Services Certificate Manager User
     * Guide</i>.</p> <p>To import an existing certificate into ACM, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/import-certificate.html">Importing
     * certificates into ACM</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>To request a private certificate to use FTPS through
     * private IP addresses, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-private.html">Request
     * a private certificate</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>Certificates with the following cryptographic algorithms
     * and key sizes are supported:</p> <ul> <li> <p>2048-bit RSA (RSA_2048)</p> </li>
     * <li> <p>4096-bit RSA (RSA_4096)</p> </li> <li> <p>Elliptic Prime Curve 256 bit
     * (EC_prime256v1)</p> </li> <li> <p>Elliptic Prime Curve 384 bit
     * (EC_secp384r1)</p> </li> <li> <p>Elliptic Prime Curve 521 bit (EC_secp521r1)</p>
     * </li> </ul>  <p>The certificate must be a valid SSL/TLS X.509 version 3
     * certificate with FQDN or IP address specified and information about the
     * issuer.</p> 
     */
    inline void SetCertificate(Aws::String&& value) { m_certificateHasBeenSet = true; m_certificate = std::move(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the Amazon Web Services Certificate Manager
     * (ACM) certificate. Required when <code>Protocols</code> is set to
     * <code>FTPS</code>.</p> <p>To request a new public certificate, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-public.html">Request
     * a public certificate</a> in the <i> Amazon Web Services Certificate Manager User
     * Guide</i>.</p> <p>To import an existing certificate into ACM, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/import-certificate.html">Importing
     * certificates into ACM</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>To request a private certificate to use FTPS through
     * private IP addresses, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-private.html">Request
     * a private certificate</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>Certificates with the following cryptographic algorithms
     * and key sizes are supported:</p> <ul> <li> <p>2048-bit RSA (RSA_2048)</p> </li>
     * <li> <p>4096-bit RSA (RSA_4096)</p> </li> <li> <p>Elliptic Prime Curve 256 bit
     * (EC_prime256v1)</p> </li> <li> <p>Elliptic Prime Curve 384 bit
     * (EC_secp384r1)</p> </li> <li> <p>Elliptic Prime Curve 521 bit (EC_secp521r1)</p>
     * </li> </ul>  <p>The certificate must be a valid SSL/TLS X.509 version 3
     * certificate with FQDN or IP address specified and information about the
     * issuer.</p> 
     */
    inline void SetCertificate(const char* value) { m_certificateHasBeenSet = true; m_certificate.assign(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the Amazon Web Services Certificate Manager
     * (ACM) certificate. Required when <code>Protocols</code> is set to
     * <code>FTPS</code>.</p> <p>To request a new public certificate, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-public.html">Request
     * a public certificate</a> in the <i> Amazon Web Services Certificate Manager User
     * Guide</i>.</p> <p>To import an existing certificate into ACM, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/import-certificate.html">Importing
     * certificates into ACM</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>To request a private certificate to use FTPS through
     * private IP addresses, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-private.html">Request
     * a private certificate</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>Certificates with the following cryptographic algorithms
     * and key sizes are supported:</p> <ul> <li> <p>2048-bit RSA (RSA_2048)</p> </li>
     * <li> <p>4096-bit RSA (RSA_4096)</p> </li> <li> <p>Elliptic Prime Curve 256 bit
     * (EC_prime256v1)</p> </li> <li> <p>Elliptic Prime Curve 384 bit
     * (EC_secp384r1)</p> </li> <li> <p>Elliptic Prime Curve 521 bit (EC_secp521r1)</p>
     * </li> </ul>  <p>The certificate must be a valid SSL/TLS X.509 version 3
     * certificate with FQDN or IP address specified and information about the
     * issuer.</p> 
     */
    inline CreateServerRequest& WithCertificate(const Aws::String& value) { SetCertificate(value); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the Amazon Web Services Certificate Manager
     * (ACM) certificate. Required when <code>Protocols</code> is set to
     * <code>FTPS</code>.</p> <p>To request a new public certificate, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-public.html">Request
     * a public certificate</a> in the <i> Amazon Web Services Certificate Manager User
     * Guide</i>.</p> <p>To import an existing certificate into ACM, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/import-certificate.html">Importing
     * certificates into ACM</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>To request a private certificate to use FTPS through
     * private IP addresses, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-private.html">Request
     * a private certificate</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>Certificates with the following cryptographic algorithms
     * and key sizes are supported:</p> <ul> <li> <p>2048-bit RSA (RSA_2048)</p> </li>
     * <li> <p>4096-bit RSA (RSA_4096)</p> </li> <li> <p>Elliptic Prime Curve 256 bit
     * (EC_prime256v1)</p> </li> <li> <p>Elliptic Prime Curve 384 bit
     * (EC_secp384r1)</p> </li> <li> <p>Elliptic Prime Curve 521 bit (EC_secp521r1)</p>
     * </li> </ul>  <p>The certificate must be a valid SSL/TLS X.509 version 3
     * certificate with FQDN or IP address specified and information about the
     * issuer.</p> 
     */
    inline CreateServerRequest& WithCertificate(Aws::String&& value) { SetCertificate(std::move(value)); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the Amazon Web Services Certificate Manager
     * (ACM) certificate. Required when <code>Protocols</code> is set to
     * <code>FTPS</code>.</p> <p>To request a new public certificate, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-public.html">Request
     * a public certificate</a> in the <i> Amazon Web Services Certificate Manager User
     * Guide</i>.</p> <p>To import an existing certificate into ACM, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/import-certificate.html">Importing
     * certificates into ACM</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>To request a private certificate to use FTPS through
     * private IP addresses, see <a
     * href="https://docs.aws.amazon.com/acm/latest/userguide/gs-acm-request-private.html">Request
     * a private certificate</a> in the <i> Amazon Web Services Certificate Manager
     * User Guide</i>.</p> <p>Certificates with the following cryptographic algorithms
     * and key sizes are supported:</p> <ul> <li> <p>2048-bit RSA (RSA_2048)</p> </li>
     * <li> <p>4096-bit RSA (RSA_4096)</p> </li> <li> <p>Elliptic Prime Curve 256 bit
     * (EC_prime256v1)</p> </li> <li> <p>Elliptic Prime Curve 384 bit
     * (EC_secp384r1)</p> </li> <li> <p>Elliptic Prime Curve 521 bit (EC_secp521r1)</p>
     * </li> </ul>  <p>The certificate must be a valid SSL/TLS X.509 version 3
     * certificate with FQDN or IP address specified and information about the
     * issuer.</p> 
     */
    inline CreateServerRequest& WithCertificate(const char* value) { SetCertificate(value); return *this;}


    /**
     * <p>The domain of the storage system that is used for file transfers. There are
     * two domains available: Amazon Simple Storage Service (Amazon S3) and Amazon
     * Elastic File System (Amazon EFS). The default value is S3.</p>  <p>After
     * the server is created, the domain cannot be changed.</p> 
     */
    inline const Domain& GetDomain() const{ return m_domain; }

    /**
     * <p>The domain of the storage system that is used for file transfers. There are
     * two domains available: Amazon Simple Storage Service (Amazon S3) and Amazon
     * Elastic File System (Amazon EFS). The default value is S3.</p>  <p>After
     * the server is created, the domain cannot be changed.</p> 
     */
    inline bool DomainHasBeenSet() const { return m_domainHasBeenSet; }

    /**
     * <p>The domain of the storage system that is used for file transfers. There are
     * two domains available: Amazon Simple Storage Service (Amazon S3) and Amazon
     * Elastic File System (Amazon EFS). The default value is S3.</p>  <p>After
     * the server is created, the domain cannot be changed.</p> 
     */
    inline void SetDomain(const Domain& value) { m_domainHasBeenSet = true; m_domain = value; }

    /**
     * <p>The domain of the storage system that is used for file transfers. There are
     * two domains available: Amazon Simple Storage Service (Amazon S3) and Amazon
     * Elastic File System (Amazon EFS). The default value is S3.</p>  <p>After
     * the server is created, the domain cannot be changed.</p> 
     */
    inline void SetDomain(Domain&& value) { m_domainHasBeenSet = true; m_domain = std::move(value); }

    /**
     * <p>The domain of the storage system that is used for file transfers. There are
     * two domains available: Amazon Simple Storage Service (Amazon S3) and Amazon
     * Elastic File System (Amazon EFS). The default value is S3.</p>  <p>After
     * the server is created, the domain cannot be changed.</p> 
     */
    inline CreateServerRequest& WithDomain(const Domain& value) { SetDomain(value); return *this;}

    /**
     * <p>The domain of the storage system that is used for file transfers. There are
     * two domains available: Amazon Simple Storage Service (Amazon S3) and Amazon
     * Elastic File System (Amazon EFS). The default value is S3.</p>  <p>After
     * the server is created, the domain cannot be changed.</p> 
     */
    inline CreateServerRequest& WithDomain(Domain&& value) { SetDomain(std::move(value)); return *this;}


    /**
     * <p>The virtual private cloud (VPC) endpoint settings that are configured for
     * your server. When you host your endpoint within your VPC, you can make it
     * accessible only to resources within your VPC, or you can attach Elastic IP
     * addresses and make it accessible to clients over the internet. Your VPC's
     * default security groups are automatically assigned to your endpoint.</p>
     */
    inline const EndpointDetails& GetEndpointDetails() const{ return m_endpointDetails; }

    /**
     * <p>The virtual private cloud (VPC) endpoint settings that are configured for
     * your server. When you host your endpoint within your VPC, you can make it
     * accessible only to resources within your VPC, or you can attach Elastic IP
     * addresses and make it accessible to clients over the internet. Your VPC's
     * default security groups are automatically assigned to your endpoint.</p>
     */
    inline bool EndpointDetailsHasBeenSet() const { return m_endpointDetailsHasBeenSet; }

    /**
     * <p>The virtual private cloud (VPC) endpoint settings that are configured for
     * your server. When you host your endpoint within your VPC, you can make it
     * accessible only to resources within your VPC, or you can attach Elastic IP
     * addresses and make it accessible to clients over the internet. Your VPC's
     * default security groups are automatically assigned to your endpoint.</p>
     */
    inline void SetEndpointDetails(const EndpointDetails& value) { m_endpointDetailsHasBeenSet = true; m_endpointDetails = value; }

    /**
     * <p>The virtual private cloud (VPC) endpoint settings that are configured for
     * your server. When you host your endpoint within your VPC, you can make it
     * accessible only to resources within your VPC, or you can attach Elastic IP
     * addresses and make it accessible to clients over the internet. Your VPC's
     * default security groups are automatically assigned to your endpoint.</p>
     */
    inline void SetEndpointDetails(EndpointDetails&& value) { m_endpointDetailsHasBeenSet = true; m_endpointDetails = std::move(value); }

    /**
     * <p>The virtual private cloud (VPC) endpoint settings that are configured for
     * your server. When you host your endpoint within your VPC, you can make it
     * accessible only to resources within your VPC, or you can attach Elastic IP
     * addresses and make it accessible to clients over the internet. Your VPC's
     * default security groups are automatically assigned to your endpoint.</p>
     */
    inline CreateServerRequest& WithEndpointDetails(const EndpointDetails& value) { SetEndpointDetails(value); return *this;}

    /**
     * <p>The virtual private cloud (VPC) endpoint settings that are configured for
     * your server. When you host your endpoint within your VPC, you can make it
     * accessible only to resources within your VPC, or you can attach Elastic IP
     * addresses and make it accessible to clients over the internet. Your VPC's
     * default security groups are automatically assigned to your endpoint.</p>
     */
    inline CreateServerRequest& WithEndpointDetails(EndpointDetails&& value) { SetEndpointDetails(std::move(value)); return *this;}


    /**
     * <p>The type of endpoint that you want your server to use. You can choose to make
     * your server's endpoint publicly accessible (PUBLIC) or host it inside your VPC.
     * With an endpoint that is hosted in a VPC, you can restrict access to your server
     * and resources only within your VPC or choose to make it internet facing by
     * attaching Elastic IP addresses directly to it.</p>  <p> After May 19,
     * 2021, you won't be able to create a server using
     * <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web Services account if
     * your account hasn't already done so before May 19, 2021. If you have already
     * created servers with <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web
     * Services account on or before May 19, 2021, you will not be affected. After this
     * date, use <code>EndpointType</code>=<code>VPC</code>.</p> <p>For more
     * information, see
     * https://docs.aws.amazon.com/transfer/latest/userguide/create-server-in-vpc.html#deprecate-vpc-endpoint.</p>
     * <p>It is recommended that you use <code>VPC</code> as the
     * <code>EndpointType</code>. With this endpoint type, you have the option to
     * directly associate up to three Elastic IPv4 addresses (BYO IP included) with
     * your server's endpoint and use VPC security groups to restrict traffic by the
     * client's public IP address. This is not possible with <code>EndpointType</code>
     * set to <code>VPC_ENDPOINT</code>.</p> 
     */
    inline const EndpointType& GetEndpointType() const{ return m_endpointType; }

    /**
     * <p>The type of endpoint that you want your server to use. You can choose to make
     * your server's endpoint publicly accessible (PUBLIC) or host it inside your VPC.
     * With an endpoint that is hosted in a VPC, you can restrict access to your server
     * and resources only within your VPC or choose to make it internet facing by
     * attaching Elastic IP addresses directly to it.</p>  <p> After May 19,
     * 2021, you won't be able to create a server using
     * <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web Services account if
     * your account hasn't already done so before May 19, 2021. If you have already
     * created servers with <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web
     * Services account on or before May 19, 2021, you will not be affected. After this
     * date, use <code>EndpointType</code>=<code>VPC</code>.</p> <p>For more
     * information, see
     * https://docs.aws.amazon.com/transfer/latest/userguide/create-server-in-vpc.html#deprecate-vpc-endpoint.</p>
     * <p>It is recommended that you use <code>VPC</code> as the
     * <code>EndpointType</code>. With this endpoint type, you have the option to
     * directly associate up to three Elastic IPv4 addresses (BYO IP included) with
     * your server's endpoint and use VPC security groups to restrict traffic by the
     * client's public IP address. This is not possible with <code>EndpointType</code>
     * set to <code>VPC_ENDPOINT</code>.</p> 
     */
    inline bool EndpointTypeHasBeenSet() const { return m_endpointTypeHasBeenSet; }

    /**
     * <p>The type of endpoint that you want your server to use. You can choose to make
     * your server's endpoint publicly accessible (PUBLIC) or host it inside your VPC.
     * With an endpoint that is hosted in a VPC, you can restrict access to your server
     * and resources only within your VPC or choose to make it internet facing by
     * attaching Elastic IP addresses directly to it.</p>  <p> After May 19,
     * 2021, you won't be able to create a server using
     * <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web Services account if
     * your account hasn't already done so before May 19, 2021. If you have already
     * created servers with <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web
     * Services account on or before May 19, 2021, you will not be affected. After this
     * date, use <code>EndpointType</code>=<code>VPC</code>.</p> <p>For more
     * information, see
     * https://docs.aws.amazon.com/transfer/latest/userguide/create-server-in-vpc.html#deprecate-vpc-endpoint.</p>
     * <p>It is recommended that you use <code>VPC</code> as the
     * <code>EndpointType</code>. With this endpoint type, you have the option to
     * directly associate up to three Elastic IPv4 addresses (BYO IP included) with
     * your server's endpoint and use VPC security groups to restrict traffic by the
     * client's public IP address. This is not possible with <code>EndpointType</code>
     * set to <code>VPC_ENDPOINT</code>.</p> 
     */
    inline void SetEndpointType(const EndpointType& value) { m_endpointTypeHasBeenSet = true; m_endpointType = value; }

    /**
     * <p>The type of endpoint that you want your server to use. You can choose to make
     * your server's endpoint publicly accessible (PUBLIC) or host it inside your VPC.
     * With an endpoint that is hosted in a VPC, you can restrict access to your server
     * and resources only within your VPC or choose to make it internet facing by
     * attaching Elastic IP addresses directly to it.</p>  <p> After May 19,
     * 2021, you won't be able to create a server using
     * <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web Services account if
     * your account hasn't already done so before May 19, 2021. If you have already
     * created servers with <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web
     * Services account on or before May 19, 2021, you will not be affected. After this
     * date, use <code>EndpointType</code>=<code>VPC</code>.</p> <p>For more
     * information, see
     * https://docs.aws.amazon.com/transfer/latest/userguide/create-server-in-vpc.html#deprecate-vpc-endpoint.</p>
     * <p>It is recommended that you use <code>VPC</code> as the
     * <code>EndpointType</code>. With this endpoint type, you have the option to
     * directly associate up to three Elastic IPv4 addresses (BYO IP included) with
     * your server's endpoint and use VPC security groups to restrict traffic by the
     * client's public IP address. This is not possible with <code>EndpointType</code>
     * set to <code>VPC_ENDPOINT</code>.</p> 
     */
    inline void SetEndpointType(EndpointType&& value) { m_endpointTypeHasBeenSet = true; m_endpointType = std::move(value); }

    /**
     * <p>The type of endpoint that you want your server to use. You can choose to make
     * your server's endpoint publicly accessible (PUBLIC) or host it inside your VPC.
     * With an endpoint that is hosted in a VPC, you can restrict access to your server
     * and resources only within your VPC or choose to make it internet facing by
     * attaching Elastic IP addresses directly to it.</p>  <p> After May 19,
     * 2021, you won't be able to create a server using
     * <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web Services account if
     * your account hasn't already done so before May 19, 2021. If you have already
     * created servers with <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web
     * Services account on or before May 19, 2021, you will not be affected. After this
     * date, use <code>EndpointType</code>=<code>VPC</code>.</p> <p>For more
     * information, see
     * https://docs.aws.amazon.com/transfer/latest/userguide/create-server-in-vpc.html#deprecate-vpc-endpoint.</p>
     * <p>It is recommended that you use <code>VPC</code> as the
     * <code>EndpointType</code>. With this endpoint type, you have the option to
     * directly associate up to three Elastic IPv4 addresses (BYO IP included) with
     * your server's endpoint and use VPC security groups to restrict traffic by the
     * client's public IP address. This is not possible with <code>EndpointType</code>
     * set to <code>VPC_ENDPOINT</code>.</p> 
     */
    inline CreateServerRequest& WithEndpointType(const EndpointType& value) { SetEndpointType(value); return *this;}

    /**
     * <p>The type of endpoint that you want your server to use. You can choose to make
     * your server's endpoint publicly accessible (PUBLIC) or host it inside your VPC.
     * With an endpoint that is hosted in a VPC, you can restrict access to your server
     * and resources only within your VPC or choose to make it internet facing by
     * attaching Elastic IP addresses directly to it.</p>  <p> After May 19,
     * 2021, you won't be able to create a server using
     * <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web Services account if
     * your account hasn't already done so before May 19, 2021. If you have already
     * created servers with <code>EndpointType=VPC_ENDPOINT</code> in your Amazon Web
     * Services account on or before May 19, 2021, you will not be affected. After this
     * date, use <code>EndpointType</code>=<code>VPC</code>.</p> <p>For more
     * information, see
     * https://docs.aws.amazon.com/transfer/latest/userguide/create-server-in-vpc.html#deprecate-vpc-endpoint.</p>
     * <p>It is recommended that you use <code>VPC</code> as the
     * <code>EndpointType</code>. With this endpoint type, you have the option to
     * directly associate up to three Elastic IPv4 addresses (BYO IP included) with
     * your server's endpoint and use VPC security groups to restrict traffic by the
     * client's public IP address. This is not possible with <code>EndpointType</code>
     * set to <code>VPC_ENDPOINT</code>.</p> 
     */
    inline CreateServerRequest& WithEndpointType(EndpointType&& value) { SetEndpointType(std::move(value)); return *this;}


    /**
     * <p>The RSA private key as generated by the <code>ssh-keygen -N "" -m PEM -f
     * my-new-server-key</code> command.</p>  <p>If you aren't planning to
     * migrate existing users from an existing SFTP-enabled server to a new server,
     * don't update the host key. Accidentally changing a server's host key can be
     * disruptive.</p>  <p>For more information, see <a
     * href="https://docs.aws.amazon.com/transfer/latest/userguide/edit-server-config.html#configuring-servers-change-host-key">Change
     * the host key for your SFTP-enabled server</a> in the <i>Amazon Web Services
     * Transfer Family User Guide</i>.</p>
     */
    inline const Aws::String& GetHostKey() const{ return m_hostKey; }

    /**
     * <p>The RSA private key as generated by the <code>ssh-keygen -N "" -m PEM -f
     * my-new-server-key</code> command.</p>  <p>If you aren't planning to
     * migrate existing users from an existing SFTP-enabled server to a new server,
     * don't update the host key. Accidentally changing a server's host key can be
     * disruptive.</p>  <p>For more information, see <a
     * href="https://docs.aws.amazon.com/transfer/latest/userguide/edit-server-config.html#configuring-servers-change-host-key">Change
     * the host key for your SFTP-enabled server</a> in the <i>Amazon Web Services
     * Transfer Family User Guide</i>.</p>
     */
    inline bool HostKeyHasBeenSet() const { return m_hostKeyHasBeenSet; }

    /**
     * <p>The RSA private key as generated by the <code>ssh-keygen -N "" -m PEM -f
     * my-new-server-key</code> command.</p>  <p>If you aren't planning to
     * migrate existing users from an existing SFTP-enabled server to a new server,
     * don't update the host key. Accidentally changing a server's host key can be
     * disruptive.</p>  <p>For more information, see <a
     * href="https://docs.aws.amazon.com/transfer/latest/userguide/edit-server-config.html#configuring-servers-change-host-key">Change
     * the host key for your SFTP-enabled server</a> in the <i>Amazon Web Services
     * Transfer Family User Guide</i>.</p>
     */
    inline void SetHostKey(const Aws::String& value) { m_hostKeyHasBeenSet = true; m_hostKey = value; }

    /**
     * <p>The RSA private key as generated by the <code>ssh-keygen -N "" -m PEM -f
     * my-new-server-key</code> command.</p>  <p>If you aren't planning to
     * migrate existing users from an existing SFTP-enabled server to a new server,
     * don't update the host key. Accidentally changing a server's host key can be
     * disruptive.</p>  <p>For more information, see <a
     * href="https://docs.aws.amazon.com/transfer/latest/userguide/edit-server-config.html#configuring-servers-change-host-key">Change
     * the host key for your SFTP-enabled server</a> in the <i>Amazon Web Services
     * Transfer Family User Guide</i>.</p>
     */
    inline void SetHostKey(Aws::String&& value) { m_hostKeyHasBeenSet = true; m_hostKey = std::move(value); }

    /**
     * <p>The RSA private key as generated by the <code>ssh-keygen -N "" -m PEM -f
     * my-new-server-key</code> command.</p>  <p>If you aren't planning to
     * migrate existing users from an existing SFTP-enabled server to a new server,
     * don't update the host key. Accidentally changing a server's host key can be
     * disruptive.</p>  <p>For more information, see <a
     * href="https://docs.aws.amazon.com/transfer/latest/userguide/edit-server-config.html#configuring-servers-change-host-key">Change
     * the host key for your SFTP-enabled server</a> in the <i>Amazon Web Services
     * Transfer Family User Guide</i>.</p>
     */
    inline void SetHostKey(const char* value) { m_hostKeyHasBeenSet = true; m_hostKey.assign(value); }

    /**
     * <p>The RSA private key as generated by the <code>ssh-keygen -N "" -m PEM -f
     * my-new-server-key</code> command.</p>  <p>If you aren't planning to
     * migrate existing users from an existing SFTP-enabled server to a new server,
     * don't update the host key. Accidentally changing a server's host key can be
     * disruptive.</p>  <p>For more information, see <a
     * href="https://docs.aws.amazon.com/transfer/latest/userguide/edit-server-config.html#configuring-servers-change-host-key">Change
     * the host key for your SFTP-enabled server</a> in the <i>Amazon Web Services
     * Transfer Family User Guide</i>.</p>
     */
    inline CreateServerRequest& WithHostKey(const Aws::String& value) { SetHostKey(value); return *this;}

    /**
     * <p>The RSA private key as generated by the <code>ssh-keygen -N "" -m PEM -f
     * my-new-server-key</code> command.</p>  <p>If you aren't planning to
     * migrate existing users from an existing SFTP-enabled server to a new server,
     * don't update the host key. Accidentally changing a server's host key can be
     * disruptive.</p>  <p>For more information, see <a
     * href="https://docs.aws.amazon.com/transfer/latest/userguide/edit-server-config.html#configuring-servers-change-host-key">Change
     * the host key for your SFTP-enabled server</a> in the <i>Amazon Web Services
     * Transfer Family User Guide</i>.</p>
     */
    inline CreateServerRequest& WithHostKey(Aws::String&& value) { SetHostKey(std::move(value)); return *this;}

    /**
     * <p>The RSA private key as generated by the <code>ssh-keygen -N "" -m PEM -f
     * my-new-server-key</code> command.</p>  <p>If you aren't planning to
     * migrate existing users from an existing SFTP-enabled server to a new server,
     * don't update the host key. Accidentally changing a server's host key can be
     * disruptive.</p>  <p>For more information, see <a
     * href="https://docs.aws.amazon.com/transfer/latest/userguide/edit-server-config.html#configuring-servers-change-host-key">Change
     * the host key for your SFTP-enabled server</a> in the <i>Amazon Web Services
     * Transfer Family User Guide</i>.</p>
     */
    inline CreateServerRequest& WithHostKey(const char* value) { SetHostKey(value); return *this;}


    /**
     * <p>Required when <code>IdentityProviderType</code> is set to
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>. Accepts an array
     * containing all of the information required to use a directory in
     * <code>AWS_DIRECTORY_SERVICE</code> or invoke a customer-supplied authentication
     * API, including the API Gateway URL. Not required when
     * <code>IdentityProviderType</code> is set to <code>SERVICE_MANAGED</code>.</p>
     */
    inline const IdentityProviderDetails& GetIdentityProviderDetails() const{ return m_identityProviderDetails; }

    /**
     * <p>Required when <code>IdentityProviderType</code> is set to
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>. Accepts an array
     * containing all of the information required to use a directory in
     * <code>AWS_DIRECTORY_SERVICE</code> or invoke a customer-supplied authentication
     * API, including the API Gateway URL. Not required when
     * <code>IdentityProviderType</code> is set to <code>SERVICE_MANAGED</code>.</p>
     */
    inline bool IdentityProviderDetailsHasBeenSet() const { return m_identityProviderDetailsHasBeenSet; }

    /**
     * <p>Required when <code>IdentityProviderType</code> is set to
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>. Accepts an array
     * containing all of the information required to use a directory in
     * <code>AWS_DIRECTORY_SERVICE</code> or invoke a customer-supplied authentication
     * API, including the API Gateway URL. Not required when
     * <code>IdentityProviderType</code> is set to <code>SERVICE_MANAGED</code>.</p>
     */
    inline void SetIdentityProviderDetails(const IdentityProviderDetails& value) { m_identityProviderDetailsHasBeenSet = true; m_identityProviderDetails = value; }

    /**
     * <p>Required when <code>IdentityProviderType</code> is set to
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>. Accepts an array
     * containing all of the information required to use a directory in
     * <code>AWS_DIRECTORY_SERVICE</code> or invoke a customer-supplied authentication
     * API, including the API Gateway URL. Not required when
     * <code>IdentityProviderType</code> is set to <code>SERVICE_MANAGED</code>.</p>
     */
    inline void SetIdentityProviderDetails(IdentityProviderDetails&& value) { m_identityProviderDetailsHasBeenSet = true; m_identityProviderDetails = std::move(value); }

    /**
     * <p>Required when <code>IdentityProviderType</code> is set to
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>. Accepts an array
     * containing all of the information required to use a directory in
     * <code>AWS_DIRECTORY_SERVICE</code> or invoke a customer-supplied authentication
     * API, including the API Gateway URL. Not required when
     * <code>IdentityProviderType</code> is set to <code>SERVICE_MANAGED</code>.</p>
     */
    inline CreateServerRequest& WithIdentityProviderDetails(const IdentityProviderDetails& value) { SetIdentityProviderDetails(value); return *this;}

    /**
     * <p>Required when <code>IdentityProviderType</code> is set to
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>. Accepts an array
     * containing all of the information required to use a directory in
     * <code>AWS_DIRECTORY_SERVICE</code> or invoke a customer-supplied authentication
     * API, including the API Gateway URL. Not required when
     * <code>IdentityProviderType</code> is set to <code>SERVICE_MANAGED</code>.</p>
     */
    inline CreateServerRequest& WithIdentityProviderDetails(IdentityProviderDetails&& value) { SetIdentityProviderDetails(std::move(value)); return *this;}


    /**
     * <p>Specifies the mode of authentication for a server. The default value is
     * <code>SERVICE_MANAGED</code>, which allows you to store and access user
     * credentials within the Amazon Web Services Transfer Family service.</p> <p>Use
     * <code>AWS_DIRECTORY_SERVICE</code> to provide access to Active Directory groups
     * in Amazon Web Services Managed Active Directory or Microsoft Active Directory in
     * your on-premises environment or in Amazon Web Services using AD Connectors. This
     * option also requires you to provide a Directory ID using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>API_GATEWAY</code> value to integrate with an identity provider of your
     * choosing. The <code>API_GATEWAY</code> setting requires you to provide an API
     * Gateway endpoint URL to call for authentication using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>AWS_LAMBDA</code> value to directly use a Lambda function as your identity
     * provider. If you choose this value, you must specify the ARN for the lambda
     * function in the <code>Function</code> parameter for the
     * <code>IdentityProviderDetails</code> data type.</p>
     */
    inline const IdentityProviderType& GetIdentityProviderType() const{ return m_identityProviderType; }

    /**
     * <p>Specifies the mode of authentication for a server. The default value is
     * <code>SERVICE_MANAGED</code>, which allows you to store and access user
     * credentials within the Amazon Web Services Transfer Family service.</p> <p>Use
     * <code>AWS_DIRECTORY_SERVICE</code> to provide access to Active Directory groups
     * in Amazon Web Services Managed Active Directory or Microsoft Active Directory in
     * your on-premises environment or in Amazon Web Services using AD Connectors. This
     * option also requires you to provide a Directory ID using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>API_GATEWAY</code> value to integrate with an identity provider of your
     * choosing. The <code>API_GATEWAY</code> setting requires you to provide an API
     * Gateway endpoint URL to call for authentication using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>AWS_LAMBDA</code> value to directly use a Lambda function as your identity
     * provider. If you choose this value, you must specify the ARN for the lambda
     * function in the <code>Function</code> parameter for the
     * <code>IdentityProviderDetails</code> data type.</p>
     */
    inline bool IdentityProviderTypeHasBeenSet() const { return m_identityProviderTypeHasBeenSet; }

    /**
     * <p>Specifies the mode of authentication for a server. The default value is
     * <code>SERVICE_MANAGED</code>, which allows you to store and access user
     * credentials within the Amazon Web Services Transfer Family service.</p> <p>Use
     * <code>AWS_DIRECTORY_SERVICE</code> to provide access to Active Directory groups
     * in Amazon Web Services Managed Active Directory or Microsoft Active Directory in
     * your on-premises environment or in Amazon Web Services using AD Connectors. This
     * option also requires you to provide a Directory ID using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>API_GATEWAY</code> value to integrate with an identity provider of your
     * choosing. The <code>API_GATEWAY</code> setting requires you to provide an API
     * Gateway endpoint URL to call for authentication using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>AWS_LAMBDA</code> value to directly use a Lambda function as your identity
     * provider. If you choose this value, you must specify the ARN for the lambda
     * function in the <code>Function</code> parameter for the
     * <code>IdentityProviderDetails</code> data type.</p>
     */
    inline void SetIdentityProviderType(const IdentityProviderType& value) { m_identityProviderTypeHasBeenSet = true; m_identityProviderType = value; }

    /**
     * <p>Specifies the mode of authentication for a server. The default value is
     * <code>SERVICE_MANAGED</code>, which allows you to store and access user
     * credentials within the Amazon Web Services Transfer Family service.</p> <p>Use
     * <code>AWS_DIRECTORY_SERVICE</code> to provide access to Active Directory groups
     * in Amazon Web Services Managed Active Directory or Microsoft Active Directory in
     * your on-premises environment or in Amazon Web Services using AD Connectors. This
     * option also requires you to provide a Directory ID using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>API_GATEWAY</code> value to integrate with an identity provider of your
     * choosing. The <code>API_GATEWAY</code> setting requires you to provide an API
     * Gateway endpoint URL to call for authentication using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>AWS_LAMBDA</code> value to directly use a Lambda function as your identity
     * provider. If you choose this value, you must specify the ARN for the lambda
     * function in the <code>Function</code> parameter for the
     * <code>IdentityProviderDetails</code> data type.</p>
     */
    inline void SetIdentityProviderType(IdentityProviderType&& value) { m_identityProviderTypeHasBeenSet = true; m_identityProviderType = std::move(value); }

    /**
     * <p>Specifies the mode of authentication for a server. The default value is
     * <code>SERVICE_MANAGED</code>, which allows you to store and access user
     * credentials within the Amazon Web Services Transfer Family service.</p> <p>Use
     * <code>AWS_DIRECTORY_SERVICE</code> to provide access to Active Directory groups
     * in Amazon Web Services Managed Active Directory or Microsoft Active Directory in
     * your on-premises environment or in Amazon Web Services using AD Connectors. This
     * option also requires you to provide a Directory ID using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>API_GATEWAY</code> value to integrate with an identity provider of your
     * choosing. The <code>API_GATEWAY</code> setting requires you to provide an API
     * Gateway endpoint URL to call for authentication using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>AWS_LAMBDA</code> value to directly use a Lambda function as your identity
     * provider. If you choose this value, you must specify the ARN for the lambda
     * function in the <code>Function</code> parameter for the
     * <code>IdentityProviderDetails</code> data type.</p>
     */
    inline CreateServerRequest& WithIdentityProviderType(const IdentityProviderType& value) { SetIdentityProviderType(value); return *this;}

    /**
     * <p>Specifies the mode of authentication for a server. The default value is
     * <code>SERVICE_MANAGED</code>, which allows you to store and access user
     * credentials within the Amazon Web Services Transfer Family service.</p> <p>Use
     * <code>AWS_DIRECTORY_SERVICE</code> to provide access to Active Directory groups
     * in Amazon Web Services Managed Active Directory or Microsoft Active Directory in
     * your on-premises environment or in Amazon Web Services using AD Connectors. This
     * option also requires you to provide a Directory ID using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>API_GATEWAY</code> value to integrate with an identity provider of your
     * choosing. The <code>API_GATEWAY</code> setting requires you to provide an API
     * Gateway endpoint URL to call for authentication using the
     * <code>IdentityProviderDetails</code> parameter.</p> <p>Use the
     * <code>AWS_LAMBDA</code> value to directly use a Lambda function as your identity
     * provider. If you choose this value, you must specify the ARN for the lambda
     * function in the <code>Function</code> parameter for the
     * <code>IdentityProviderDetails</code> data type.</p>
     */
    inline CreateServerRequest& WithIdentityProviderType(IdentityProviderType&& value) { SetIdentityProviderType(std::move(value)); return *this;}


    /**
     * <p>Specifies the Amazon Resource Name (ARN) of the Amazon Web Services Identity
     * and Access Management (IAM) role that allows a server to turn on Amazon
     * CloudWatch logging for Amazon S3 or Amazon EFS events. When set, user activity
     * can be viewed in your CloudWatch logs.</p>
     */
    inline const Aws::String& GetLoggingRole() const{ return m_loggingRole; }

    /**
     * <p>Specifies the Amazon Resource Name (ARN) of the Amazon Web Services Identity
     * and Access Management (IAM) role that allows a server to turn on Amazon
     * CloudWatch logging for Amazon S3 or Amazon EFS events. When set, user activity
     * can be viewed in your CloudWatch logs.</p>
     */
    inline bool LoggingRoleHasBeenSet() const { return m_loggingRoleHasBeenSet; }

    /**
     * <p>Specifies the Amazon Resource Name (ARN) of the Amazon Web Services Identity
     * and Access Management (IAM) role that allows a server to turn on Amazon
     * CloudWatch logging for Amazon S3 or Amazon EFS events. When set, user activity
     * can be viewed in your CloudWatch logs.</p>
     */
    inline void SetLoggingRole(const Aws::String& value) { m_loggingRoleHasBeenSet = true; m_loggingRole = value; }

    /**
     * <p>Specifies the Amazon Resource Name (ARN) of the Amazon Web Services Identity
     * and Access Management (IAM) role that allows a server to turn on Amazon
     * CloudWatch logging for Amazon S3 or Amazon EFS events. When set, user activity
     * can be viewed in your CloudWatch logs.</p>
     */
    inline void SetLoggingRole(Aws::String&& value) { m_loggingRoleHasBeenSet = true; m_loggingRole = std::move(value); }

    /**
     * <p>Specifies the Amazon Resource Name (ARN) of the Amazon Web Services Identity
     * and Access Management (IAM) role that allows a server to turn on Amazon
     * CloudWatch logging for Amazon S3 or Amazon EFS events. When set, user activity
     * can be viewed in your CloudWatch logs.</p>
     */
    inline void SetLoggingRole(const char* value) { m_loggingRoleHasBeenSet = true; m_loggingRole.assign(value); }

    /**
     * <p>Specifies the Amazon Resource Name (ARN) of the Amazon Web Services Identity
     * and Access Management (IAM) role that allows a server to turn on Amazon
     * CloudWatch logging for Amazon S3 or Amazon EFS events. When set, user activity
     * can be viewed in your CloudWatch logs.</p>
     */
    inline CreateServerRequest& WithLoggingRole(const Aws::String& value) { SetLoggingRole(value); return *this;}

    /**
     * <p>Specifies the Amazon Resource Name (ARN) of the Amazon Web Services Identity
     * and Access Management (IAM) role that allows a server to turn on Amazon
     * CloudWatch logging for Amazon S3 or Amazon EFS events. When set, user activity
     * can be viewed in your CloudWatch logs.</p>
     */
    inline CreateServerRequest& WithLoggingRole(Aws::String&& value) { SetLoggingRole(std::move(value)); return *this;}

    /**
     * <p>Specifies the Amazon Resource Name (ARN) of the Amazon Web Services Identity
     * and Access Management (IAM) role that allows a server to turn on Amazon
     * CloudWatch logging for Amazon S3 or Amazon EFS events. When set, user activity
     * can be viewed in your CloudWatch logs.</p>
     */
    inline CreateServerRequest& WithLoggingRole(const char* value) { SetLoggingRole(value); return *this;}


    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed after the user authenticates.</p>  <p>The SFTP protocol does not
     * support post-authentication display banners.</p> 
     */
    inline const Aws::String& GetPostAuthenticationLoginBanner() const{ return m_postAuthenticationLoginBanner; }

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed after the user authenticates.</p>  <p>The SFTP protocol does not
     * support post-authentication display banners.</p> 
     */
    inline bool PostAuthenticationLoginBannerHasBeenSet() const { return m_postAuthenticationLoginBannerHasBeenSet; }

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed after the user authenticates.</p>  <p>The SFTP protocol does not
     * support post-authentication display banners.</p> 
     */
    inline void SetPostAuthenticationLoginBanner(const Aws::String& value) { m_postAuthenticationLoginBannerHasBeenSet = true; m_postAuthenticationLoginBanner = value; }

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed after the user authenticates.</p>  <p>The SFTP protocol does not
     * support post-authentication display banners.</p> 
     */
    inline void SetPostAuthenticationLoginBanner(Aws::String&& value) { m_postAuthenticationLoginBannerHasBeenSet = true; m_postAuthenticationLoginBanner = std::move(value); }

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed after the user authenticates.</p>  <p>The SFTP protocol does not
     * support post-authentication display banners.</p> 
     */
    inline void SetPostAuthenticationLoginBanner(const char* value) { m_postAuthenticationLoginBannerHasBeenSet = true; m_postAuthenticationLoginBanner.assign(value); }

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed after the user authenticates.</p>  <p>The SFTP protocol does not
     * support post-authentication display banners.</p> 
     */
    inline CreateServerRequest& WithPostAuthenticationLoginBanner(const Aws::String& value) { SetPostAuthenticationLoginBanner(value); return *this;}

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed after the user authenticates.</p>  <p>The SFTP protocol does not
     * support post-authentication display banners.</p> 
     */
    inline CreateServerRequest& WithPostAuthenticationLoginBanner(Aws::String&& value) { SetPostAuthenticationLoginBanner(std::move(value)); return *this;}

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed after the user authenticates.</p>  <p>The SFTP protocol does not
     * support post-authentication display banners.</p> 
     */
    inline CreateServerRequest& WithPostAuthenticationLoginBanner(const char* value) { SetPostAuthenticationLoginBanner(value); return *this;}


    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed before the user authenticates. For example, the following banner
     * displays details about using the system.</p> <p> <code>This system is for the
     * use of authorized users only. Individuals using this computer system without
     * authority, or in excess of their authority, are subject to having all of their
     * activities on this system monitored and recorded by system personnel.</code>
     * </p>
     */
    inline const Aws::String& GetPreAuthenticationLoginBanner() const{ return m_preAuthenticationLoginBanner; }

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed before the user authenticates. For example, the following banner
     * displays details about using the system.</p> <p> <code>This system is for the
     * use of authorized users only. Individuals using this computer system without
     * authority, or in excess of their authority, are subject to having all of their
     * activities on this system monitored and recorded by system personnel.</code>
     * </p>
     */
    inline bool PreAuthenticationLoginBannerHasBeenSet() const { return m_preAuthenticationLoginBannerHasBeenSet; }

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed before the user authenticates. For example, the following banner
     * displays details about using the system.</p> <p> <code>This system is for the
     * use of authorized users only. Individuals using this computer system without
     * authority, or in excess of their authority, are subject to having all of their
     * activities on this system monitored and recorded by system personnel.</code>
     * </p>
     */
    inline void SetPreAuthenticationLoginBanner(const Aws::String& value) { m_preAuthenticationLoginBannerHasBeenSet = true; m_preAuthenticationLoginBanner = value; }

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed before the user authenticates. For example, the following banner
     * displays details about using the system.</p> <p> <code>This system is for the
     * use of authorized users only. Individuals using this computer system without
     * authority, or in excess of their authority, are subject to having all of their
     * activities on this system monitored and recorded by system personnel.</code>
     * </p>
     */
    inline void SetPreAuthenticationLoginBanner(Aws::String&& value) { m_preAuthenticationLoginBannerHasBeenSet = true; m_preAuthenticationLoginBanner = std::move(value); }

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed before the user authenticates. For example, the following banner
     * displays details about using the system.</p> <p> <code>This system is for the
     * use of authorized users only. Individuals using this computer system without
     * authority, or in excess of their authority, are subject to having all of their
     * activities on this system monitored and recorded by system personnel.</code>
     * </p>
     */
    inline void SetPreAuthenticationLoginBanner(const char* value) { m_preAuthenticationLoginBannerHasBeenSet = true; m_preAuthenticationLoginBanner.assign(value); }

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed before the user authenticates. For example, the following banner
     * displays details about using the system.</p> <p> <code>This system is for the
     * use of authorized users only. Individuals using this computer system without
     * authority, or in excess of their authority, are subject to having all of their
     * activities on this system monitored and recorded by system personnel.</code>
     * </p>
     */
    inline CreateServerRequest& WithPreAuthenticationLoginBanner(const Aws::String& value) { SetPreAuthenticationLoginBanner(value); return *this;}

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed before the user authenticates. For example, the following banner
     * displays details about using the system.</p> <p> <code>This system is for the
     * use of authorized users only. Individuals using this computer system without
     * authority, or in excess of their authority, are subject to having all of their
     * activities on this system monitored and recorded by system personnel.</code>
     * </p>
     */
    inline CreateServerRequest& WithPreAuthenticationLoginBanner(Aws::String&& value) { SetPreAuthenticationLoginBanner(std::move(value)); return *this;}

    /**
     * <p>Specify a string to display when users connect to a server. This string is
     * displayed before the user authenticates. For example, the following banner
     * displays details about using the system.</p> <p> <code>This system is for the
     * use of authorized users only. Individuals using this computer system without
     * authority, or in excess of their authority, are subject to having all of their
     * activities on this system monitored and recorded by system personnel.</code>
     * </p>
     */
    inline CreateServerRequest& WithPreAuthenticationLoginBanner(const char* value) { SetPreAuthenticationLoginBanner(value); return *this;}


    /**
     * <p>Specifies the file transfer protocol or protocols over which your file
     * transfer protocol client can connect to your server's endpoint. The available
     * protocols are:</p> <ul> <li> <p> <code>SFTP</code> (Secure Shell (SSH) File
     * Transfer Protocol): File transfer over SSH</p> </li> <li> <p> <code>FTPS</code>
     * (File Transfer Protocol Secure): File transfer with TLS encryption</p> </li>
     * <li> <p> <code>FTP</code> (File Transfer Protocol): Unencrypted file
     * transfer</p> </li> </ul>  <p>If you select <code>FTPS</code>, you must
     * choose a certificate stored in Amazon Web Services Certificate Manager (ACM)
     * which is used to identify your server when clients connect to it over FTPS.</p>
     * <p>If <code>Protocol</code> includes either <code>FTP</code> or
     * <code>FTPS</code>, then the <code>EndpointType</code> must be <code>VPC</code>
     * and the <code>IdentityProviderType</code> must be
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>.</p> <p>If
     * <code>Protocol</code> includes <code>FTP</code>, then
     * <code>AddressAllocationIds</code> cannot be associated.</p> <p>If
     * <code>Protocol</code> is set only to <code>SFTP</code>, the
     * <code>EndpointType</code> can be set to <code>PUBLIC</code> and the
     * <code>IdentityProviderType</code> can be set to
     * <code>SERVICE_MANAGED</code>.</p> 
     */
    inline const Aws::Vector<Protocol>& GetProtocols() const{ return m_protocols; }

    /**
     * <p>Specifies the file transfer protocol or protocols over which your file
     * transfer protocol client can connect to your server's endpoint. The available
     * protocols are:</p> <ul> <li> <p> <code>SFTP</code> (Secure Shell (SSH) File
     * Transfer Protocol): File transfer over SSH</p> </li> <li> <p> <code>FTPS</code>
     * (File Transfer Protocol Secure): File transfer with TLS encryption</p> </li>
     * <li> <p> <code>FTP</code> (File Transfer Protocol): Unencrypted file
     * transfer</p> </li> </ul>  <p>If you select <code>FTPS</code>, you must
     * choose a certificate stored in Amazon Web Services Certificate Manager (ACM)
     * which is used to identify your server when clients connect to it over FTPS.</p>
     * <p>If <code>Protocol</code> includes either <code>FTP</code> or
     * <code>FTPS</code>, then the <code>EndpointType</code> must be <code>VPC</code>
     * and the <code>IdentityProviderType</code> must be
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>.</p> <p>If
     * <code>Protocol</code> includes <code>FTP</code>, then
     * <code>AddressAllocationIds</code> cannot be associated.</p> <p>If
     * <code>Protocol</code> is set only to <code>SFTP</code>, the
     * <code>EndpointType</code> can be set to <code>PUBLIC</code> and the
     * <code>IdentityProviderType</code> can be set to
     * <code>SERVICE_MANAGED</code>.</p> 
     */
    inline bool ProtocolsHasBeenSet() const { return m_protocolsHasBeenSet; }

    /**
     * <p>Specifies the file transfer protocol or protocols over which your file
     * transfer protocol client can connect to your server's endpoint. The available
     * protocols are:</p> <ul> <li> <p> <code>SFTP</code> (Secure Shell (SSH) File
     * Transfer Protocol): File transfer over SSH</p> </li> <li> <p> <code>FTPS</code>
     * (File Transfer Protocol Secure): File transfer with TLS encryption</p> </li>
     * <li> <p> <code>FTP</code> (File Transfer Protocol): Unencrypted file
     * transfer</p> </li> </ul>  <p>If you select <code>FTPS</code>, you must
     * choose a certificate stored in Amazon Web Services Certificate Manager (ACM)
     * which is used to identify your server when clients connect to it over FTPS.</p>
     * <p>If <code>Protocol</code> includes either <code>FTP</code> or
     * <code>FTPS</code>, then the <code>EndpointType</code> must be <code>VPC</code>
     * and the <code>IdentityProviderType</code> must be
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>.</p> <p>If
     * <code>Protocol</code> includes <code>FTP</code>, then
     * <code>AddressAllocationIds</code> cannot be associated.</p> <p>If
     * <code>Protocol</code> is set only to <code>SFTP</code>, the
     * <code>EndpointType</code> can be set to <code>PUBLIC</code> and the
     * <code>IdentityProviderType</code> can be set to
     * <code>SERVICE_MANAGED</code>.</p> 
     */
    inline void SetProtocols(const Aws::Vector<Protocol>& value) { m_protocolsHasBeenSet = true; m_protocols = value; }

    /**
     * <p>Specifies the file transfer protocol or protocols over which your file
     * transfer protocol client can connect to your server's endpoint. The available
     * protocols are:</p> <ul> <li> <p> <code>SFTP</code> (Secure Shell (SSH) File
     * Transfer Protocol): File transfer over SSH</p> </li> <li> <p> <code>FTPS</code>
     * (File Transfer Protocol Secure): File transfer with TLS encryption</p> </li>
     * <li> <p> <code>FTP</code> (File Transfer Protocol): Unencrypted file
     * transfer</p> </li> </ul>  <p>If you select <code>FTPS</code>, you must
     * choose a certificate stored in Amazon Web Services Certificate Manager (ACM)
     * which is used to identify your server when clients connect to it over FTPS.</p>
     * <p>If <code>Protocol</code> includes either <code>FTP</code> or
     * <code>FTPS</code>, then the <code>EndpointType</code> must be <code>VPC</code>
     * and the <code>IdentityProviderType</code> must be
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>.</p> <p>If
     * <code>Protocol</code> includes <code>FTP</code>, then
     * <code>AddressAllocationIds</code> cannot be associated.</p> <p>If
     * <code>Protocol</code> is set only to <code>SFTP</code>, the
     * <code>EndpointType</code> can be set to <code>PUBLIC</code> and the
     * <code>IdentityProviderType</code> can be set to
     * <code>SERVICE_MANAGED</code>.</p> 
     */
    inline void SetProtocols(Aws::Vector<Protocol>&& value) { m_protocolsHasBeenSet = true; m_protocols = std::move(value); }

    /**
     * <p>Specifies the file transfer protocol or protocols over which your file
     * transfer protocol client can connect to your server's endpoint. The available
     * protocols are:</p> <ul> <li> <p> <code>SFTP</code> (Secure Shell (SSH) File
     * Transfer Protocol): File transfer over SSH</p> </li> <li> <p> <code>FTPS</code>
     * (File Transfer Protocol Secure): File transfer with TLS encryption</p> </li>
     * <li> <p> <code>FTP</code> (File Transfer Protocol): Unencrypted file
     * transfer</p> </li> </ul>  <p>If you select <code>FTPS</code>, you must
     * choose a certificate stored in Amazon Web Services Certificate Manager (ACM)
     * which is used to identify your server when clients connect to it over FTPS.</p>
     * <p>If <code>Protocol</code> includes either <code>FTP</code> or
     * <code>FTPS</code>, then the <code>EndpointType</code> must be <code>VPC</code>
     * and the <code>IdentityProviderType</code> must be
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>.</p> <p>If
     * <code>Protocol</code> includes <code>FTP</code>, then
     * <code>AddressAllocationIds</code> cannot be associated.</p> <p>If
     * <code>Protocol</code> is set only to <code>SFTP</code>, the
     * <code>EndpointType</code> can be set to <code>PUBLIC</code> and the
     * <code>IdentityProviderType</code> can be set to
     * <code>SERVICE_MANAGED</code>.</p> 
     */
    inline CreateServerRequest& WithProtocols(const Aws::Vector<Protocol>& value) { SetProtocols(value); return *this;}

    /**
     * <p>Specifies the file transfer protocol or protocols over which your file
     * transfer protocol client can connect to your server's endpoint. The available
     * protocols are:</p> <ul> <li> <p> <code>SFTP</code> (Secure Shell (SSH) File
     * Transfer Protocol): File transfer over SSH</p> </li> <li> <p> <code>FTPS</code>
     * (File Transfer Protocol Secure): File transfer with TLS encryption</p> </li>
     * <li> <p> <code>FTP</code> (File Transfer Protocol): Unencrypted file
     * transfer</p> </li> </ul>  <p>If you select <code>FTPS</code>, you must
     * choose a certificate stored in Amazon Web Services Certificate Manager (ACM)
     * which is used to identify your server when clients connect to it over FTPS.</p>
     * <p>If <code>Protocol</code> includes either <code>FTP</code> or
     * <code>FTPS</code>, then the <code>EndpointType</code> must be <code>VPC</code>
     * and the <code>IdentityProviderType</code> must be
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>.</p> <p>If
     * <code>Protocol</code> includes <code>FTP</code>, then
     * <code>AddressAllocationIds</code> cannot be associated.</p> <p>If
     * <code>Protocol</code> is set only to <code>SFTP</code>, the
     * <code>EndpointType</code> can be set to <code>PUBLIC</code> and the
     * <code>IdentityProviderType</code> can be set to
     * <code>SERVICE_MANAGED</code>.</p> 
     */
    inline CreateServerRequest& WithProtocols(Aws::Vector<Protocol>&& value) { SetProtocols(std::move(value)); return *this;}

    /**
     * <p>Specifies the file transfer protocol or protocols over which your file
     * transfer protocol client can connect to your server's endpoint. The available
     * protocols are:</p> <ul> <li> <p> <code>SFTP</code> (Secure Shell (SSH) File
     * Transfer Protocol): File transfer over SSH</p> </li> <li> <p> <code>FTPS</code>
     * (File Transfer Protocol Secure): File transfer with TLS encryption</p> </li>
     * <li> <p> <code>FTP</code> (File Transfer Protocol): Unencrypted file
     * transfer</p> </li> </ul>  <p>If you select <code>FTPS</code>, you must
     * choose a certificate stored in Amazon Web Services Certificate Manager (ACM)
     * which is used to identify your server when clients connect to it over FTPS.</p>
     * <p>If <code>Protocol</code> includes either <code>FTP</code> or
     * <code>FTPS</code>, then the <code>EndpointType</code> must be <code>VPC</code>
     * and the <code>IdentityProviderType</code> must be
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>.</p> <p>If
     * <code>Protocol</code> includes <code>FTP</code>, then
     * <code>AddressAllocationIds</code> cannot be associated.</p> <p>If
     * <code>Protocol</code> is set only to <code>SFTP</code>, the
     * <code>EndpointType</code> can be set to <code>PUBLIC</code> and the
     * <code>IdentityProviderType</code> can be set to
     * <code>SERVICE_MANAGED</code>.</p> 
     */
    inline CreateServerRequest& AddProtocols(const Protocol& value) { m_protocolsHasBeenSet = true; m_protocols.push_back(value); return *this; }

    /**
     * <p>Specifies the file transfer protocol or protocols over which your file
     * transfer protocol client can connect to your server's endpoint. The available
     * protocols are:</p> <ul> <li> <p> <code>SFTP</code> (Secure Shell (SSH) File
     * Transfer Protocol): File transfer over SSH</p> </li> <li> <p> <code>FTPS</code>
     * (File Transfer Protocol Secure): File transfer with TLS encryption</p> </li>
     * <li> <p> <code>FTP</code> (File Transfer Protocol): Unencrypted file
     * transfer</p> </li> </ul>  <p>If you select <code>FTPS</code>, you must
     * choose a certificate stored in Amazon Web Services Certificate Manager (ACM)
     * which is used to identify your server when clients connect to it over FTPS.</p>
     * <p>If <code>Protocol</code> includes either <code>FTP</code> or
     * <code>FTPS</code>, then the <code>EndpointType</code> must be <code>VPC</code>
     * and the <code>IdentityProviderType</code> must be
     * <code>AWS_DIRECTORY_SERVICE</code> or <code>API_GATEWAY</code>.</p> <p>If
     * <code>Protocol</code> includes <code>FTP</code>, then
     * <code>AddressAllocationIds</code> cannot be associated.</p> <p>If
     * <code>Protocol</code> is set only to <code>SFTP</code>, the
     * <code>EndpointType</code> can be set to <code>PUBLIC</code> and the
     * <code>IdentityProviderType</code> can be set to
     * <code>SERVICE_MANAGED</code>.</p> 
     */
    inline CreateServerRequest& AddProtocols(Protocol&& value) { m_protocolsHasBeenSet = true; m_protocols.push_back(std::move(value)); return *this; }


    /**
     * <p>The protocol settings that are configured for your server.</p> <p> Use the
     * <code>PassiveIp</code> parameter to indicate passive mode (for FTP and FTPS
     * protocols). Enter a single dotted-quad IPv4 address, such as the external IP
     * address of a firewall, router, or load balancer. </p> <p>Use the
     * <code>TlsSessionResumptionMode</code> parameter to determine whether or not your
     * Transfer server resumes recent, negotiated sessions through a unique session
     * ID.</p>
     */
    inline const ProtocolDetails& GetProtocolDetails() const{ return m_protocolDetails; }

    /**
     * <p>The protocol settings that are configured for your server.</p> <p> Use the
     * <code>PassiveIp</code> parameter to indicate passive mode (for FTP and FTPS
     * protocols). Enter a single dotted-quad IPv4 address, such as the external IP
     * address of a firewall, router, or load balancer. </p> <p>Use the
     * <code>TlsSessionResumptionMode</code> parameter to determine whether or not your
     * Transfer server resumes recent, negotiated sessions through a unique session
     * ID.</p>
     */
    inline bool ProtocolDetailsHasBeenSet() const { return m_protocolDetailsHasBeenSet; }

    /**
     * <p>The protocol settings that are configured for your server.</p> <p> Use the
     * <code>PassiveIp</code> parameter to indicate passive mode (for FTP and FTPS
     * protocols). Enter a single dotted-quad IPv4 address, such as the external IP
     * address of a firewall, router, or load balancer. </p> <p>Use the
     * <code>TlsSessionResumptionMode</code> parameter to determine whether or not your
     * Transfer server resumes recent, negotiated sessions through a unique session
     * ID.</p>
     */
    inline void SetProtocolDetails(const ProtocolDetails& value) { m_protocolDetailsHasBeenSet = true; m_protocolDetails = value; }

    /**
     * <p>The protocol settings that are configured for your server.</p> <p> Use the
     * <code>PassiveIp</code> parameter to indicate passive mode (for FTP and FTPS
     * protocols). Enter a single dotted-quad IPv4 address, such as the external IP
     * address of a firewall, router, or load balancer. </p> <p>Use the
     * <code>TlsSessionResumptionMode</code> parameter to determine whether or not your
     * Transfer server resumes recent, negotiated sessions through a unique session
     * ID.</p>
     */
    inline void SetProtocolDetails(ProtocolDetails&& value) { m_protocolDetailsHasBeenSet = true; m_protocolDetails = std::move(value); }

    /**
     * <p>The protocol settings that are configured for your server.</p> <p> Use the
     * <code>PassiveIp</code> parameter to indicate passive mode (for FTP and FTPS
     * protocols). Enter a single dotted-quad IPv4 address, such as the external IP
     * address of a firewall, router, or load balancer. </p> <p>Use the
     * <code>TlsSessionResumptionMode</code> parameter to determine whether or not your
     * Transfer server resumes recent, negotiated sessions through a unique session
     * ID.</p>
     */
    inline CreateServerRequest& WithProtocolDetails(const ProtocolDetails& value) { SetProtocolDetails(value); return *this;}

    /**
     * <p>The protocol settings that are configured for your server.</p> <p> Use the
     * <code>PassiveIp</code> parameter to indicate passive mode (for FTP and FTPS
     * protocols). Enter a single dotted-quad IPv4 address, such as the external IP
     * address of a firewall, router, or load balancer. </p> <p>Use the
     * <code>TlsSessionResumptionMode</code> parameter to determine whether or not your
     * Transfer server resumes recent, negotiated sessions through a unique session
     * ID.</p>
     */
    inline CreateServerRequest& WithProtocolDetails(ProtocolDetails&& value) { SetProtocolDetails(std::move(value)); return *this;}


    /**
     * <p>Specifies the name of the security policy that is attached to the server.</p>
     */
    inline const Aws::String& GetSecurityPolicyName() const{ return m_securityPolicyName; }

    /**
     * <p>Specifies the name of the security policy that is attached to the server.</p>
     */
    inline bool SecurityPolicyNameHasBeenSet() const { return m_securityPolicyNameHasBeenSet; }

    /**
     * <p>Specifies the name of the security policy that is attached to the server.</p>
     */
    inline void SetSecurityPolicyName(const Aws::String& value) { m_securityPolicyNameHasBeenSet = true; m_securityPolicyName = value; }

    /**
     * <p>Specifies the name of the security policy that is attached to the server.</p>
     */
    inline void SetSecurityPolicyName(Aws::String&& value) { m_securityPolicyNameHasBeenSet = true; m_securityPolicyName = std::move(value); }

    /**
     * <p>Specifies the name of the security policy that is attached to the server.</p>
     */
    inline void SetSecurityPolicyName(const char* value) { m_securityPolicyNameHasBeenSet = true; m_securityPolicyName.assign(value); }

    /**
     * <p>Specifies the name of the security policy that is attached to the server.</p>
     */
    inline CreateServerRequest& WithSecurityPolicyName(const Aws::String& value) { SetSecurityPolicyName(value); return *this;}

    /**
     * <p>Specifies the name of the security policy that is attached to the server.</p>
     */
    inline CreateServerRequest& WithSecurityPolicyName(Aws::String&& value) { SetSecurityPolicyName(std::move(value)); return *this;}

    /**
     * <p>Specifies the name of the security policy that is attached to the server.</p>
     */
    inline CreateServerRequest& WithSecurityPolicyName(const char* value) { SetSecurityPolicyName(value); return *this;}


    /**
     * <p>Key-value pairs that can be used to group and search for servers.</p>
     */
    inline const Aws::Vector<Tag>& GetTags() const{ return m_tags; }

    /**
     * <p>Key-value pairs that can be used to group and search for servers.</p>
     */
    inline bool TagsHasBeenSet() const { return m_tagsHasBeenSet; }

    /**
     * <p>Key-value pairs that can be used to group and search for servers.</p>
     */
    inline void SetTags(const Aws::Vector<Tag>& value) { m_tagsHasBeenSet = true; m_tags = value; }

    /**
     * <p>Key-value pairs that can be used to group and search for servers.</p>
     */
    inline void SetTags(Aws::Vector<Tag>&& value) { m_tagsHasBeenSet = true; m_tags = std::move(value); }

    /**
     * <p>Key-value pairs that can be used to group and search for servers.</p>
     */
    inline CreateServerRequest& WithTags(const Aws::Vector<Tag>& value) { SetTags(value); return *this;}

    /**
     * <p>Key-value pairs that can be used to group and search for servers.</p>
     */
    inline CreateServerRequest& WithTags(Aws::Vector<Tag>&& value) { SetTags(std::move(value)); return *this;}

    /**
     * <p>Key-value pairs that can be used to group and search for servers.</p>
     */
    inline CreateServerRequest& AddTags(const Tag& value) { m_tagsHasBeenSet = true; m_tags.push_back(value); return *this; }

    /**
     * <p>Key-value pairs that can be used to group and search for servers.</p>
     */
    inline CreateServerRequest& AddTags(Tag&& value) { m_tagsHasBeenSet = true; m_tags.push_back(std::move(value)); return *this; }


    /**
     * <p>Specifies the workflow ID for the workflow to assign and the execution role
     * used for executing the workflow.</p>
     */
    inline const WorkflowDetails& GetWorkflowDetails() const{ return m_workflowDetails; }

    /**
     * <p>Specifies the workflow ID for the workflow to assign and the execution role
     * used for executing the workflow.</p>
     */
    inline bool WorkflowDetailsHasBeenSet() const { return m_workflowDetailsHasBeenSet; }

    /**
     * <p>Specifies the workflow ID for the workflow to assign and the execution role
     * used for executing the workflow.</p>
     */
    inline void SetWorkflowDetails(const WorkflowDetails& value) { m_workflowDetailsHasBeenSet = true; m_workflowDetails = value; }

    /**
     * <p>Specifies the workflow ID for the workflow to assign and the execution role
     * used for executing the workflow.</p>
     */
    inline void SetWorkflowDetails(WorkflowDetails&& value) { m_workflowDetailsHasBeenSet = true; m_workflowDetails = std::move(value); }

    /**
     * <p>Specifies the workflow ID for the workflow to assign and the execution role
     * used for executing the workflow.</p>
     */
    inline CreateServerRequest& WithWorkflowDetails(const WorkflowDetails& value) { SetWorkflowDetails(value); return *this;}

    /**
     * <p>Specifies the workflow ID for the workflow to assign and the execution role
     * used for executing the workflow.</p>
     */
    inline CreateServerRequest& WithWorkflowDetails(WorkflowDetails&& value) { SetWorkflowDetails(std::move(value)); return *this;}

  private:

    Aws::String m_certificate;
    bool m_certificateHasBeenSet;

    Domain m_domain;
    bool m_domainHasBeenSet;

    EndpointDetails m_endpointDetails;
    bool m_endpointDetailsHasBeenSet;

    EndpointType m_endpointType;
    bool m_endpointTypeHasBeenSet;

    Aws::String m_hostKey;
    bool m_hostKeyHasBeenSet;

    IdentityProviderDetails m_identityProviderDetails;
    bool m_identityProviderDetailsHasBeenSet;

    IdentityProviderType m_identityProviderType;
    bool m_identityProviderTypeHasBeenSet;

    Aws::String m_loggingRole;
    bool m_loggingRoleHasBeenSet;

    Aws::String m_postAuthenticationLoginBanner;
    bool m_postAuthenticationLoginBannerHasBeenSet;

    Aws::String m_preAuthenticationLoginBanner;
    bool m_preAuthenticationLoginBannerHasBeenSet;

    Aws::Vector<Protocol> m_protocols;
    bool m_protocolsHasBeenSet;

    ProtocolDetails m_protocolDetails;
    bool m_protocolDetailsHasBeenSet;

    Aws::String m_securityPolicyName;
    bool m_securityPolicyNameHasBeenSet;

    Aws::Vector<Tag> m_tags;
    bool m_tagsHasBeenSet;

    WorkflowDetails m_workflowDetails;
    bool m_workflowDetailsHasBeenSet;
  };

} // namespace Model
} // namespace Transfer
} // namespace Aws
