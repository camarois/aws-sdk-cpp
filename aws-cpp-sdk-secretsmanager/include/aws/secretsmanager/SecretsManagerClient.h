﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/secretsmanager/SecretsManager_EXPORTS.h>
#include <aws/secretsmanager/SecretsManagerErrors.h>
#include <aws/core/client/AWSError.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/client/AWSClient.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/secretsmanager/model/CancelRotateSecretResult.h>
#include <aws/secretsmanager/model/CreateSecretResult.h>
#include <aws/secretsmanager/model/DeleteResourcePolicyResult.h>
#include <aws/secretsmanager/model/DeleteSecretResult.h>
#include <aws/secretsmanager/model/DescribeSecretResult.h>
#include <aws/secretsmanager/model/GetRandomPasswordResult.h>
#include <aws/secretsmanager/model/GetResourcePolicyResult.h>
#include <aws/secretsmanager/model/GetSecretValueResult.h>
#include <aws/secretsmanager/model/ListSecretVersionIdsResult.h>
#include <aws/secretsmanager/model/ListSecretsResult.h>
#include <aws/secretsmanager/model/PutResourcePolicyResult.h>
#include <aws/secretsmanager/model/PutSecretValueResult.h>
#include <aws/secretsmanager/model/RemoveRegionsFromReplicationResult.h>
#include <aws/secretsmanager/model/ReplicateSecretToRegionsResult.h>
#include <aws/secretsmanager/model/RestoreSecretResult.h>
#include <aws/secretsmanager/model/RotateSecretResult.h>
#include <aws/secretsmanager/model/StopReplicationToReplicaResult.h>
#include <aws/secretsmanager/model/UpdateSecretResult.h>
#include <aws/secretsmanager/model/UpdateSecretVersionStageResult.h>
#include <aws/secretsmanager/model/ValidateResourcePolicyResult.h>
#include <aws/core/NoResult.h>
#include <aws/core/client/AsyncCallerContext.h>
#include <aws/core/http/HttpTypes.h>
#include <future>
#include <functional>

namespace Aws
{

namespace Http
{
  class HttpClient;
  class HttpClientFactory;
} // namespace Http

namespace Utils
{
  template< typename R, typename E> class Outcome;
namespace Threading
{
  class Executor;
} // namespace Threading
} // namespace Utils

namespace Auth
{
  class AWSCredentials;
  class AWSCredentialsProvider;
} // namespace Auth

namespace Client
{
  class RetryStrategy;
} // namespace Client

namespace SecretsManager
{

namespace Model
{
        class CancelRotateSecretRequest;
        class CreateSecretRequest;
        class DeleteResourcePolicyRequest;
        class DeleteSecretRequest;
        class DescribeSecretRequest;
        class GetRandomPasswordRequest;
        class GetResourcePolicyRequest;
        class GetSecretValueRequest;
        class ListSecretVersionIdsRequest;
        class ListSecretsRequest;
        class PutResourcePolicyRequest;
        class PutSecretValueRequest;
        class RemoveRegionsFromReplicationRequest;
        class ReplicateSecretToRegionsRequest;
        class RestoreSecretRequest;
        class RotateSecretRequest;
        class StopReplicationToReplicaRequest;
        class TagResourceRequest;
        class UntagResourceRequest;
        class UpdateSecretRequest;
        class UpdateSecretVersionStageRequest;
        class ValidateResourcePolicyRequest;

        typedef Aws::Utils::Outcome<CancelRotateSecretResult, SecretsManagerError> CancelRotateSecretOutcome;
        typedef Aws::Utils::Outcome<CreateSecretResult, SecretsManagerError> CreateSecretOutcome;
        typedef Aws::Utils::Outcome<DeleteResourcePolicyResult, SecretsManagerError> DeleteResourcePolicyOutcome;
        typedef Aws::Utils::Outcome<DeleteSecretResult, SecretsManagerError> DeleteSecretOutcome;
        typedef Aws::Utils::Outcome<DescribeSecretResult, SecretsManagerError> DescribeSecretOutcome;
        typedef Aws::Utils::Outcome<GetRandomPasswordResult, SecretsManagerError> GetRandomPasswordOutcome;
        typedef Aws::Utils::Outcome<GetResourcePolicyResult, SecretsManagerError> GetResourcePolicyOutcome;
        typedef Aws::Utils::Outcome<GetSecretValueResult, SecretsManagerError> GetSecretValueOutcome;
        typedef Aws::Utils::Outcome<ListSecretVersionIdsResult, SecretsManagerError> ListSecretVersionIdsOutcome;
        typedef Aws::Utils::Outcome<ListSecretsResult, SecretsManagerError> ListSecretsOutcome;
        typedef Aws::Utils::Outcome<PutResourcePolicyResult, SecretsManagerError> PutResourcePolicyOutcome;
        typedef Aws::Utils::Outcome<PutSecretValueResult, SecretsManagerError> PutSecretValueOutcome;
        typedef Aws::Utils::Outcome<RemoveRegionsFromReplicationResult, SecretsManagerError> RemoveRegionsFromReplicationOutcome;
        typedef Aws::Utils::Outcome<ReplicateSecretToRegionsResult, SecretsManagerError> ReplicateSecretToRegionsOutcome;
        typedef Aws::Utils::Outcome<RestoreSecretResult, SecretsManagerError> RestoreSecretOutcome;
        typedef Aws::Utils::Outcome<RotateSecretResult, SecretsManagerError> RotateSecretOutcome;
        typedef Aws::Utils::Outcome<StopReplicationToReplicaResult, SecretsManagerError> StopReplicationToReplicaOutcome;
        typedef Aws::Utils::Outcome<Aws::NoResult, SecretsManagerError> TagResourceOutcome;
        typedef Aws::Utils::Outcome<Aws::NoResult, SecretsManagerError> UntagResourceOutcome;
        typedef Aws::Utils::Outcome<UpdateSecretResult, SecretsManagerError> UpdateSecretOutcome;
        typedef Aws::Utils::Outcome<UpdateSecretVersionStageResult, SecretsManagerError> UpdateSecretVersionStageOutcome;
        typedef Aws::Utils::Outcome<ValidateResourcePolicyResult, SecretsManagerError> ValidateResourcePolicyOutcome;

        typedef std::future<CancelRotateSecretOutcome> CancelRotateSecretOutcomeCallable;
        typedef std::future<CreateSecretOutcome> CreateSecretOutcomeCallable;
        typedef std::future<DeleteResourcePolicyOutcome> DeleteResourcePolicyOutcomeCallable;
        typedef std::future<DeleteSecretOutcome> DeleteSecretOutcomeCallable;
        typedef std::future<DescribeSecretOutcome> DescribeSecretOutcomeCallable;
        typedef std::future<GetRandomPasswordOutcome> GetRandomPasswordOutcomeCallable;
        typedef std::future<GetResourcePolicyOutcome> GetResourcePolicyOutcomeCallable;
        typedef std::future<GetSecretValueOutcome> GetSecretValueOutcomeCallable;
        typedef std::future<ListSecretVersionIdsOutcome> ListSecretVersionIdsOutcomeCallable;
        typedef std::future<ListSecretsOutcome> ListSecretsOutcomeCallable;
        typedef std::future<PutResourcePolicyOutcome> PutResourcePolicyOutcomeCallable;
        typedef std::future<PutSecretValueOutcome> PutSecretValueOutcomeCallable;
        typedef std::future<RemoveRegionsFromReplicationOutcome> RemoveRegionsFromReplicationOutcomeCallable;
        typedef std::future<ReplicateSecretToRegionsOutcome> ReplicateSecretToRegionsOutcomeCallable;
        typedef std::future<RestoreSecretOutcome> RestoreSecretOutcomeCallable;
        typedef std::future<RotateSecretOutcome> RotateSecretOutcomeCallable;
        typedef std::future<StopReplicationToReplicaOutcome> StopReplicationToReplicaOutcomeCallable;
        typedef std::future<TagResourceOutcome> TagResourceOutcomeCallable;
        typedef std::future<UntagResourceOutcome> UntagResourceOutcomeCallable;
        typedef std::future<UpdateSecretOutcome> UpdateSecretOutcomeCallable;
        typedef std::future<UpdateSecretVersionStageOutcome> UpdateSecretVersionStageOutcomeCallable;
        typedef std::future<ValidateResourcePolicyOutcome> ValidateResourcePolicyOutcomeCallable;
} // namespace Model

  class SecretsManagerClient;

    typedef std::function<void(const SecretsManagerClient*, const Model::CancelRotateSecretRequest&, const Model::CancelRotateSecretOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CancelRotateSecretResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::CreateSecretRequest&, const Model::CreateSecretOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateSecretResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::DeleteResourcePolicyRequest&, const Model::DeleteResourcePolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteResourcePolicyResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::DeleteSecretRequest&, const Model::DeleteSecretOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteSecretResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::DescribeSecretRequest&, const Model::DescribeSecretOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeSecretResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::GetRandomPasswordRequest&, const Model::GetRandomPasswordOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetRandomPasswordResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::GetResourcePolicyRequest&, const Model::GetResourcePolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetResourcePolicyResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::GetSecretValueRequest&, const Model::GetSecretValueOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > GetSecretValueResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::ListSecretVersionIdsRequest&, const Model::ListSecretVersionIdsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListSecretVersionIdsResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::ListSecretsRequest&, const Model::ListSecretsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListSecretsResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::PutResourcePolicyRequest&, const Model::PutResourcePolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutResourcePolicyResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::PutSecretValueRequest&, const Model::PutSecretValueOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > PutSecretValueResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::RemoveRegionsFromReplicationRequest&, const Model::RemoveRegionsFromReplicationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > RemoveRegionsFromReplicationResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::ReplicateSecretToRegionsRequest&, const Model::ReplicateSecretToRegionsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ReplicateSecretToRegionsResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::RestoreSecretRequest&, const Model::RestoreSecretOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > RestoreSecretResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::RotateSecretRequest&, const Model::RotateSecretOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > RotateSecretResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::StopReplicationToReplicaRequest&, const Model::StopReplicationToReplicaOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > StopReplicationToReplicaResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::TagResourceRequest&, const Model::TagResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > TagResourceResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::UntagResourceRequest&, const Model::UntagResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UntagResourceResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::UpdateSecretRequest&, const Model::UpdateSecretOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateSecretResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::UpdateSecretVersionStageRequest&, const Model::UpdateSecretVersionStageOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateSecretVersionStageResponseReceivedHandler;
    typedef std::function<void(const SecretsManagerClient*, const Model::ValidateResourcePolicyRequest&, const Model::ValidateResourcePolicyOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ValidateResourcePolicyResponseReceivedHandler;

  /**
   * <fullname>Amazon Web Services Secrets Manager</fullname> <p>Amazon Web Services
   * Secrets Manager provides a service to enable you to store, manage, and retrieve,
   * secrets.</p> <p>This guide provides descriptions of the Secrets Manager API. For
   * more information about using this service, see the <a
   * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/introduction.html">Amazon
   * Web Services Secrets Manager User Guide</a>.</p> <p> <b>API Version</b> </p>
   * <p>This version of the Secrets Manager API Reference documents the Secrets
   * Manager API version 2017-10-17.</p> <p> <b>Support and Feedback for Amazon Web
   * Services Secrets Manager</b> </p> <p>We welcome your feedback. Send your
   * comments to <a
   * href="mailto:awssecretsmanager-feedback@amazon.com">awssecretsmanager-feedback@amazon.com</a>,
   * or post your feedback and questions in the <a
   * href="http://forums.aws.amazon.com/forum.jspa?forumID=296">Amazon Web Services
   * Secrets Manager Discussion Forum</a>. For more information about the Amazon Web
   * Services Discussion Forums, see <a
   * href="http://forums.aws.amazon.com/help.jspa">Forums Help</a>.</p> <p>
   * <b>Logging API Requests</b> </p> <p>Amazon Web Services Secrets Manager supports
   * Amazon Web Services CloudTrail, a service that records Amazon Web Services API
   * calls for your Amazon Web Services account and delivers log files to an Amazon
   * S3 bucket. By using information that's collected by Amazon Web Services
   * CloudTrail, you can determine the requests successfully made to Secrets Manager,
   * who made the request, when it was made, and so on. For more about Amazon Web
   * Services Secrets Manager and support for Amazon Web Services CloudTrail, see <a
   * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/monitoring.html#monitoring_cloudtrail">Logging
   * Amazon Web Services Secrets Manager Events with Amazon Web Services
   * CloudTrail</a> in the <i>Amazon Web Services Secrets Manager User Guide</i>. To
   * learn more about CloudTrail, including enabling it and find your log files, see
   * the <a
   * href="https://docs.aws.amazon.com/awscloudtrail/latest/userguide/what_is_cloud_trail_top_level.html">Amazon
   * Web Services CloudTrail User Guide</a>.</p>
   */
  class AWS_SECRETSMANAGER_API SecretsManagerClient : public Aws::Client::AWSJsonClient
  {
    public:
      typedef Aws::Client::AWSJsonClient BASECLASS;

       /**
        * Initializes client to use DefaultCredentialProviderChain, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        SecretsManagerClient(const Aws::Client::ClientConfiguration& clientConfiguration = Aws::Client::ClientConfiguration());

       /**
        * Initializes client to use SimpleAWSCredentialsProvider, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        SecretsManagerClient(const Aws::Auth::AWSCredentials& credentials, const Aws::Client::ClientConfiguration& clientConfiguration = Aws::Client::ClientConfiguration());

       /**
        * Initializes client to use specified credentials provider with specified client config. If http client factory is not supplied,
        * the default http client factory will be used
        */
        SecretsManagerClient(const std::shared_ptr<Aws::Auth::AWSCredentialsProvider>& credentialsProvider,
            const Aws::Client::ClientConfiguration& clientConfiguration = Aws::Client::ClientConfiguration());

        virtual ~SecretsManagerClient();


        /**
         * <p>Turns off automatic rotation, and if a rotation is currently in progress,
         * cancels the rotation.</p> <p>To turn on automatic rotation again, call
         * <a>RotateSecret</a>.</p>  <p>If you cancel a rotation in progress, it can
         * leave the <code>VersionStage</code> labels in an unexpected state. Depending on
         * the step of the rotation in progress, you might need to remove the staging label
         * <code>AWSPENDING</code> from the partially created version, specified by the
         * <code>VersionId</code> response value. We recommend you also evaluate the
         * partially rotated new version to see if it should be deleted. You can delete a
         * version by removing all staging labels from it.</p>  <p> <b>Required
         * permissions: </b> <code>secretsmanager:CancelRotateSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/CancelRotateSecret">AWS
         * API Reference</a></p>
         */
        virtual Model::CancelRotateSecretOutcome CancelRotateSecret(const Model::CancelRotateSecretRequest& request) const;

        /**
         * <p>Turns off automatic rotation, and if a rotation is currently in progress,
         * cancels the rotation.</p> <p>To turn on automatic rotation again, call
         * <a>RotateSecret</a>.</p>  <p>If you cancel a rotation in progress, it can
         * leave the <code>VersionStage</code> labels in an unexpected state. Depending on
         * the step of the rotation in progress, you might need to remove the staging label
         * <code>AWSPENDING</code> from the partially created version, specified by the
         * <code>VersionId</code> response value. We recommend you also evaluate the
         * partially rotated new version to see if it should be deleted. You can delete a
         * version by removing all staging labels from it.</p>  <p> <b>Required
         * permissions: </b> <code>secretsmanager:CancelRotateSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/CancelRotateSecret">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CancelRotateSecretOutcomeCallable CancelRotateSecretCallable(const Model::CancelRotateSecretRequest& request) const;

        /**
         * <p>Turns off automatic rotation, and if a rotation is currently in progress,
         * cancels the rotation.</p> <p>To turn on automatic rotation again, call
         * <a>RotateSecret</a>.</p>  <p>If you cancel a rotation in progress, it can
         * leave the <code>VersionStage</code> labels in an unexpected state. Depending on
         * the step of the rotation in progress, you might need to remove the staging label
         * <code>AWSPENDING</code> from the partially created version, specified by the
         * <code>VersionId</code> response value. We recommend you also evaluate the
         * partially rotated new version to see if it should be deleted. You can delete a
         * version by removing all staging labels from it.</p>  <p> <b>Required
         * permissions: </b> <code>secretsmanager:CancelRotateSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/CancelRotateSecret">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CancelRotateSecretAsync(const Model::CancelRotateSecretRequest& request, const CancelRotateSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates a new secret. A <i>secret</i> is a set of credentials, such as a user
         * name and password, that you store in an encrypted form in Secrets Manager. The
         * secret also includes the connection information to access a database or other
         * service, which Secrets Manager doesn't encrypt. A secret in Secrets Manager
         * consists of both the protected secret data and the important information needed
         * to manage the secret.</p> <p>For information about creating a secret in the
         * console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_create-basic-secret.html">Create
         * a secret</a>.</p> <p>To create a secret, you can provide the secret value to be
         * encrypted in either the <code>SecretString</code> parameter or the
         * <code>SecretBinary</code> parameter, but not both. If you include
         * <code>SecretString</code> or <code>SecretBinary</code> then Secrets Manager
         * creates an initial secret version and automatically attaches the staging label
         * <code>AWSCURRENT</code> to it.</p> <p>If you don't specify an KMS encryption
         * key, Secrets Manager uses the Amazon Web Services managed key
         * <code>aws/secretsmanager</code>. If this key doesn't already exist in your
         * account, then Secrets Manager creates it for you automatically. All users and
         * roles in the Amazon Web Services account automatically have access to use
         * <code>aws/secretsmanager</code>. Creating <code>aws/secretsmanager</code> can
         * result in a one-time significant delay in returning the result.</p> <p>If the
         * secret is in a different Amazon Web Services account from the credentials
         * calling the API, then you can't use <code>aws/secretsmanager</code> to encrypt
         * the secret, and you must create and use a customer managed KMS key. </p> <p>
         * <b>Required permissions: </b> <code>secretsmanager:CreateSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/CreateSecret">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateSecretOutcome CreateSecret(const Model::CreateSecretRequest& request) const;

        /**
         * <p>Creates a new secret. A <i>secret</i> is a set of credentials, such as a user
         * name and password, that you store in an encrypted form in Secrets Manager. The
         * secret also includes the connection information to access a database or other
         * service, which Secrets Manager doesn't encrypt. A secret in Secrets Manager
         * consists of both the protected secret data and the important information needed
         * to manage the secret.</p> <p>For information about creating a secret in the
         * console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_create-basic-secret.html">Create
         * a secret</a>.</p> <p>To create a secret, you can provide the secret value to be
         * encrypted in either the <code>SecretString</code> parameter or the
         * <code>SecretBinary</code> parameter, but not both. If you include
         * <code>SecretString</code> or <code>SecretBinary</code> then Secrets Manager
         * creates an initial secret version and automatically attaches the staging label
         * <code>AWSCURRENT</code> to it.</p> <p>If you don't specify an KMS encryption
         * key, Secrets Manager uses the Amazon Web Services managed key
         * <code>aws/secretsmanager</code>. If this key doesn't already exist in your
         * account, then Secrets Manager creates it for you automatically. All users and
         * roles in the Amazon Web Services account automatically have access to use
         * <code>aws/secretsmanager</code>. Creating <code>aws/secretsmanager</code> can
         * result in a one-time significant delay in returning the result.</p> <p>If the
         * secret is in a different Amazon Web Services account from the credentials
         * calling the API, then you can't use <code>aws/secretsmanager</code> to encrypt
         * the secret, and you must create and use a customer managed KMS key. </p> <p>
         * <b>Required permissions: </b> <code>secretsmanager:CreateSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/CreateSecret">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateSecretOutcomeCallable CreateSecretCallable(const Model::CreateSecretRequest& request) const;

        /**
         * <p>Creates a new secret. A <i>secret</i> is a set of credentials, such as a user
         * name and password, that you store in an encrypted form in Secrets Manager. The
         * secret also includes the connection information to access a database or other
         * service, which Secrets Manager doesn't encrypt. A secret in Secrets Manager
         * consists of both the protected secret data and the important information needed
         * to manage the secret.</p> <p>For information about creating a secret in the
         * console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_create-basic-secret.html">Create
         * a secret</a>.</p> <p>To create a secret, you can provide the secret value to be
         * encrypted in either the <code>SecretString</code> parameter or the
         * <code>SecretBinary</code> parameter, but not both. If you include
         * <code>SecretString</code> or <code>SecretBinary</code> then Secrets Manager
         * creates an initial secret version and automatically attaches the staging label
         * <code>AWSCURRENT</code> to it.</p> <p>If you don't specify an KMS encryption
         * key, Secrets Manager uses the Amazon Web Services managed key
         * <code>aws/secretsmanager</code>. If this key doesn't already exist in your
         * account, then Secrets Manager creates it for you automatically. All users and
         * roles in the Amazon Web Services account automatically have access to use
         * <code>aws/secretsmanager</code>. Creating <code>aws/secretsmanager</code> can
         * result in a one-time significant delay in returning the result.</p> <p>If the
         * secret is in a different Amazon Web Services account from the credentials
         * calling the API, then you can't use <code>aws/secretsmanager</code> to encrypt
         * the secret, and you must create and use a customer managed KMS key. </p> <p>
         * <b>Required permissions: </b> <code>secretsmanager:CreateSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/CreateSecret">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateSecretAsync(const Model::CreateSecretRequest& request, const CreateSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Deletes the resource-based permission policy attached to the secret. To
         * attach a policy to a secret, use <a>PutResourcePolicy</a>.</p> <p> <b>Required
         * permissions: </b> <code>secretsmanager:DeleteResourcePolicy</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/DeleteResourcePolicy">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteResourcePolicyOutcome DeleteResourcePolicy(const Model::DeleteResourcePolicyRequest& request) const;

        /**
         * <p>Deletes the resource-based permission policy attached to the secret. To
         * attach a policy to a secret, use <a>PutResourcePolicy</a>.</p> <p> <b>Required
         * permissions: </b> <code>secretsmanager:DeleteResourcePolicy</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/DeleteResourcePolicy">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteResourcePolicyOutcomeCallable DeleteResourcePolicyCallable(const Model::DeleteResourcePolicyRequest& request) const;

        /**
         * <p>Deletes the resource-based permission policy attached to the secret. To
         * attach a policy to a secret, use <a>PutResourcePolicy</a>.</p> <p> <b>Required
         * permissions: </b> <code>secretsmanager:DeleteResourcePolicy</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/DeleteResourcePolicy">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteResourcePolicyAsync(const Model::DeleteResourcePolicyRequest& request, const DeleteResourcePolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Deletes a secret and all of its versions. You can specify a recovery window
         * during which you can restore the secret. The minimum recovery window is 7 days.
         * The default recovery window is 30 days. Secrets Manager attaches a
         * <code>DeletionDate</code> stamp to the secret that specifies the end of the
         * recovery window. At the end of the recovery window, Secrets Manager deletes the
         * secret permanently.</p> <p>For information about deleting a secret in the
         * console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_delete-secret.html">https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_delete-secret.html</a>.
         * </p> <p>Secrets Manager performs the permanent secret deletion at the end of the
         * waiting period as a background task with low priority. There is no guarantee of
         * a specific time after the recovery window for the permanent delete to occur.</p>
         * <p>At any time before recovery window ends, you can use <a>RestoreSecret</a> to
         * remove the <code>DeletionDate</code> and cancel the deletion of the secret.</p>
         * <p>In a secret scheduled for deletion, you cannot access the encrypted secret
         * value. To access that information, first cancel the deletion with
         * <a>RestoreSecret</a> and then retrieve the information.</p> <p> <b>Required
         * permissions: </b> <code>secretsmanager:DeleteSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/DeleteSecret">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteSecretOutcome DeleteSecret(const Model::DeleteSecretRequest& request) const;

        /**
         * <p>Deletes a secret and all of its versions. You can specify a recovery window
         * during which you can restore the secret. The minimum recovery window is 7 days.
         * The default recovery window is 30 days. Secrets Manager attaches a
         * <code>DeletionDate</code> stamp to the secret that specifies the end of the
         * recovery window. At the end of the recovery window, Secrets Manager deletes the
         * secret permanently.</p> <p>For information about deleting a secret in the
         * console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_delete-secret.html">https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_delete-secret.html</a>.
         * </p> <p>Secrets Manager performs the permanent secret deletion at the end of the
         * waiting period as a background task with low priority. There is no guarantee of
         * a specific time after the recovery window for the permanent delete to occur.</p>
         * <p>At any time before recovery window ends, you can use <a>RestoreSecret</a> to
         * remove the <code>DeletionDate</code> and cancel the deletion of the secret.</p>
         * <p>In a secret scheduled for deletion, you cannot access the encrypted secret
         * value. To access that information, first cancel the deletion with
         * <a>RestoreSecret</a> and then retrieve the information.</p> <p> <b>Required
         * permissions: </b> <code>secretsmanager:DeleteSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/DeleteSecret">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteSecretOutcomeCallable DeleteSecretCallable(const Model::DeleteSecretRequest& request) const;

        /**
         * <p>Deletes a secret and all of its versions. You can specify a recovery window
         * during which you can restore the secret. The minimum recovery window is 7 days.
         * The default recovery window is 30 days. Secrets Manager attaches a
         * <code>DeletionDate</code> stamp to the secret that specifies the end of the
         * recovery window. At the end of the recovery window, Secrets Manager deletes the
         * secret permanently.</p> <p>For information about deleting a secret in the
         * console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_delete-secret.html">https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_delete-secret.html</a>.
         * </p> <p>Secrets Manager performs the permanent secret deletion at the end of the
         * waiting period as a background task with low priority. There is no guarantee of
         * a specific time after the recovery window for the permanent delete to occur.</p>
         * <p>At any time before recovery window ends, you can use <a>RestoreSecret</a> to
         * remove the <code>DeletionDate</code> and cancel the deletion of the secret.</p>
         * <p>In a secret scheduled for deletion, you cannot access the encrypted secret
         * value. To access that information, first cancel the deletion with
         * <a>RestoreSecret</a> and then retrieve the information.</p> <p> <b>Required
         * permissions: </b> <code>secretsmanager:DeleteSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/DeleteSecret">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteSecretAsync(const Model::DeleteSecretRequest& request, const DeleteSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Retrieves the details of a secret. It does not include the encrypted secret
         * value. Secrets Manager only returns fields that have a value in the response.
         * </p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:DescribeSecret</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/DescribeSecret">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeSecretOutcome DescribeSecret(const Model::DescribeSecretRequest& request) const;

        /**
         * <p>Retrieves the details of a secret. It does not include the encrypted secret
         * value. Secrets Manager only returns fields that have a value in the response.
         * </p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:DescribeSecret</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/DescribeSecret">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeSecretOutcomeCallable DescribeSecretCallable(const Model::DescribeSecretRequest& request) const;

        /**
         * <p>Retrieves the details of a secret. It does not include the encrypted secret
         * value. Secrets Manager only returns fields that have a value in the response.
         * </p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:DescribeSecret</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/DescribeSecret">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeSecretAsync(const Model::DescribeSecretRequest& request, const DescribeSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Generates a random password. We recommend that you specify the maximum length
         * and include every character type that the system you are generating a password
         * for can support.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:GetRandomPassword</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/GetRandomPassword">AWS
         * API Reference</a></p>
         */
        virtual Model::GetRandomPasswordOutcome GetRandomPassword(const Model::GetRandomPasswordRequest& request) const;

        /**
         * <p>Generates a random password. We recommend that you specify the maximum length
         * and include every character type that the system you are generating a password
         * for can support.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:GetRandomPassword</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/GetRandomPassword">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::GetRandomPasswordOutcomeCallable GetRandomPasswordCallable(const Model::GetRandomPasswordRequest& request) const;

        /**
         * <p>Generates a random password. We recommend that you specify the maximum length
         * and include every character type that the system you are generating a password
         * for can support.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:GetRandomPassword</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/GetRandomPassword">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void GetRandomPasswordAsync(const Model::GetRandomPasswordRequest& request, const GetRandomPasswordResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Retrieves the JSON text of the resource-based policy document attached to the
         * secret. For more information about permissions policies attached to a secret,
         * see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access_resource-policies.html">Permissions
         * policies attached to a secret</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:GetResourcePolicy</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/GetResourcePolicy">AWS
         * API Reference</a></p>
         */
        virtual Model::GetResourcePolicyOutcome GetResourcePolicy(const Model::GetResourcePolicyRequest& request) const;

        /**
         * <p>Retrieves the JSON text of the resource-based policy document attached to the
         * secret. For more information about permissions policies attached to a secret,
         * see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access_resource-policies.html">Permissions
         * policies attached to a secret</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:GetResourcePolicy</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/GetResourcePolicy">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::GetResourcePolicyOutcomeCallable GetResourcePolicyCallable(const Model::GetResourcePolicyRequest& request) const;

        /**
         * <p>Retrieves the JSON text of the resource-based policy document attached to the
         * secret. For more information about permissions policies attached to a secret,
         * see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access_resource-policies.html">Permissions
         * policies attached to a secret</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:GetResourcePolicy</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/GetResourcePolicy">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void GetResourcePolicyAsync(const Model::GetResourcePolicyRequest& request, const GetResourcePolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Retrieves the contents of the encrypted fields <code>SecretString</code> or
         * <code>SecretBinary</code> from the specified version of a secret, whichever
         * contains content.</p> <p>We recommend that you cache your secret values by using
         * client-side caching. Caching secrets improves speed and reduces your costs. For
         * more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/retrieving-secrets.html">Cache
         * secrets for your applications</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:GetSecretValue</code>. If the secret is encrypted using a
         * customer-managed key instead of the Amazon Web Services managed key
         * <code>aws/secretsmanager</code>, then you also need <code>kms:Decrypt</code>
         * permissions for that key. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/GetSecretValue">AWS
         * API Reference</a></p>
         */
        virtual Model::GetSecretValueOutcome GetSecretValue(const Model::GetSecretValueRequest& request) const;

        /**
         * <p>Retrieves the contents of the encrypted fields <code>SecretString</code> or
         * <code>SecretBinary</code> from the specified version of a secret, whichever
         * contains content.</p> <p>We recommend that you cache your secret values by using
         * client-side caching. Caching secrets improves speed and reduces your costs. For
         * more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/retrieving-secrets.html">Cache
         * secrets for your applications</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:GetSecretValue</code>. If the secret is encrypted using a
         * customer-managed key instead of the Amazon Web Services managed key
         * <code>aws/secretsmanager</code>, then you also need <code>kms:Decrypt</code>
         * permissions for that key. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/GetSecretValue">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::GetSecretValueOutcomeCallable GetSecretValueCallable(const Model::GetSecretValueRequest& request) const;

        /**
         * <p>Retrieves the contents of the encrypted fields <code>SecretString</code> or
         * <code>SecretBinary</code> from the specified version of a secret, whichever
         * contains content.</p> <p>We recommend that you cache your secret values by using
         * client-side caching. Caching secrets improves speed and reduces your costs. For
         * more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/retrieving-secrets.html">Cache
         * secrets for your applications</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:GetSecretValue</code>. If the secret is encrypted using a
         * customer-managed key instead of the Amazon Web Services managed key
         * <code>aws/secretsmanager</code>, then you also need <code>kms:Decrypt</code>
         * permissions for that key. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/GetSecretValue">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void GetSecretValueAsync(const Model::GetSecretValueRequest& request, const GetSecretValueResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Lists the versions for a secret. </p> <p>To list the secrets in the account,
         * use <a>ListSecrets</a>.</p> <p>To get the secret value from
         * <code>SecretString</code> or <code>SecretBinary</code>, call
         * <a>GetSecretValue</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:ListSecretVersionIds</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ListSecretVersionIds">AWS
         * API Reference</a></p>
         */
        virtual Model::ListSecretVersionIdsOutcome ListSecretVersionIds(const Model::ListSecretVersionIdsRequest& request) const;

        /**
         * <p>Lists the versions for a secret. </p> <p>To list the secrets in the account,
         * use <a>ListSecrets</a>.</p> <p>To get the secret value from
         * <code>SecretString</code> or <code>SecretBinary</code>, call
         * <a>GetSecretValue</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:ListSecretVersionIds</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ListSecretVersionIds">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::ListSecretVersionIdsOutcomeCallable ListSecretVersionIdsCallable(const Model::ListSecretVersionIdsRequest& request) const;

        /**
         * <p>Lists the versions for a secret. </p> <p>To list the secrets in the account,
         * use <a>ListSecrets</a>.</p> <p>To get the secret value from
         * <code>SecretString</code> or <code>SecretBinary</code>, call
         * <a>GetSecretValue</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:ListSecretVersionIds</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ListSecretVersionIds">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void ListSecretVersionIdsAsync(const Model::ListSecretVersionIdsRequest& request, const ListSecretVersionIdsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Lists the secrets that are stored by Secrets Manager in the Amazon Web
         * Services account, not including secrets that are marked for deletion. To see
         * secrets marked for deletion, use the Secrets Manager console.</p> <p>To list the
         * versions of a secret, use <a>ListSecretVersionIds</a>.</p> <p>To get the secret
         * value from <code>SecretString</code> or <code>SecretBinary</code>, call
         * <a>GetSecretValue</a>.</p> <p>For information about finding secrets in the
         * console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_search-secret.html">Enhanced
         * search capabilities for secrets in Secrets Manager</a>.</p> <p> <b>Required
         * permissions: </b> <code>secretsmanager:ListSecrets</code>. For more information,
         * see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ListSecrets">AWS
         * API Reference</a></p>
         */
        virtual Model::ListSecretsOutcome ListSecrets(const Model::ListSecretsRequest& request) const;

        /**
         * <p>Lists the secrets that are stored by Secrets Manager in the Amazon Web
         * Services account, not including secrets that are marked for deletion. To see
         * secrets marked for deletion, use the Secrets Manager console.</p> <p>To list the
         * versions of a secret, use <a>ListSecretVersionIds</a>.</p> <p>To get the secret
         * value from <code>SecretString</code> or <code>SecretBinary</code>, call
         * <a>GetSecretValue</a>.</p> <p>For information about finding secrets in the
         * console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_search-secret.html">Enhanced
         * search capabilities for secrets in Secrets Manager</a>.</p> <p> <b>Required
         * permissions: </b> <code>secretsmanager:ListSecrets</code>. For more information,
         * see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ListSecrets">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::ListSecretsOutcomeCallable ListSecretsCallable(const Model::ListSecretsRequest& request) const;

        /**
         * <p>Lists the secrets that are stored by Secrets Manager in the Amazon Web
         * Services account, not including secrets that are marked for deletion. To see
         * secrets marked for deletion, use the Secrets Manager console.</p> <p>To list the
         * versions of a secret, use <a>ListSecretVersionIds</a>.</p> <p>To get the secret
         * value from <code>SecretString</code> or <code>SecretBinary</code>, call
         * <a>GetSecretValue</a>.</p> <p>For information about finding secrets in the
         * console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/manage_search-secret.html">Enhanced
         * search capabilities for secrets in Secrets Manager</a>.</p> <p> <b>Required
         * permissions: </b> <code>secretsmanager:ListSecrets</code>. For more information,
         * see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ListSecrets">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void ListSecretsAsync(const Model::ListSecretsRequest& request, const ListSecretsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Attaches a resource-based permission policy to a secret. A resource-based
         * policy is optional. For more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control for Secrets Manager</a> </p> <p>For information about
         * attaching a policy in the console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access_resource-based-policies.html">Attach
         * a permissions policy to a secret</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:PutResourcePolicy</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/PutResourcePolicy">AWS
         * API Reference</a></p>
         */
        virtual Model::PutResourcePolicyOutcome PutResourcePolicy(const Model::PutResourcePolicyRequest& request) const;

        /**
         * <p>Attaches a resource-based permission policy to a secret. A resource-based
         * policy is optional. For more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control for Secrets Manager</a> </p> <p>For information about
         * attaching a policy in the console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access_resource-based-policies.html">Attach
         * a permissions policy to a secret</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:PutResourcePolicy</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/PutResourcePolicy">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::PutResourcePolicyOutcomeCallable PutResourcePolicyCallable(const Model::PutResourcePolicyRequest& request) const;

        /**
         * <p>Attaches a resource-based permission policy to a secret. A resource-based
         * policy is optional. For more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control for Secrets Manager</a> </p> <p>For information about
         * attaching a policy in the console, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access_resource-based-policies.html">Attach
         * a permissions policy to a secret</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:PutResourcePolicy</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/PutResourcePolicy">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void PutResourcePolicyAsync(const Model::PutResourcePolicyRequest& request, const PutResourcePolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates a new version with a new encrypted secret value and attaches it to
         * the secret. The version can contain a new <code>SecretString</code> value or a
         * new <code>SecretBinary</code> value. </p> <p>We recommend you avoid calling
         * <code>PutSecretValue</code> at a sustained rate of more than once every 10
         * minutes. When you update the secret value, Secrets Manager creates a new version
         * of the secret. Secrets Manager removes outdated versions when there are more
         * than 100, but it does not remove versions created less than 24 hours ago. If you
         * call <code>PutSecretValue</code> more than once every 10 minutes, you create
         * more versions than Secrets Manager removes, and you will reach the quota for
         * secret versions.</p> <p>You can specify the staging labels to attach to the new
         * version in <code>VersionStages</code>. If you don't include
         * <code>VersionStages</code>, then Secrets Manager automatically moves the staging
         * label <code>AWSCURRENT</code> to this version. If this operation creates the
         * first version for the secret, then Secrets Manager automatically attaches the
         * staging label <code>AWSCURRENT</code> to it .</p> <p>If this operation moves the
         * staging label <code>AWSCURRENT</code> from another version to this version, then
         * Secrets Manager also automatically moves the staging label
         * <code>AWSPREVIOUS</code> to the version that <code>AWSCURRENT</code> was removed
         * from.</p> <p>This operation is idempotent. If a version with a
         * <code>VersionId</code> with the same value as the
         * <code>ClientRequestToken</code> parameter already exists, and you specify the
         * same secret data, the operation succeeds but does nothing. However, if the
         * secret data is different, then the operation fails because you can't modify an
         * existing version; you can only create new ones.</p> <p> <b>Required permissions:
         * </b> <code>secretsmanager:PutSecretValue</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/PutSecretValue">AWS
         * API Reference</a></p>
         */
        virtual Model::PutSecretValueOutcome PutSecretValue(const Model::PutSecretValueRequest& request) const;

        /**
         * <p>Creates a new version with a new encrypted secret value and attaches it to
         * the secret. The version can contain a new <code>SecretString</code> value or a
         * new <code>SecretBinary</code> value. </p> <p>We recommend you avoid calling
         * <code>PutSecretValue</code> at a sustained rate of more than once every 10
         * minutes. When you update the secret value, Secrets Manager creates a new version
         * of the secret. Secrets Manager removes outdated versions when there are more
         * than 100, but it does not remove versions created less than 24 hours ago. If you
         * call <code>PutSecretValue</code> more than once every 10 minutes, you create
         * more versions than Secrets Manager removes, and you will reach the quota for
         * secret versions.</p> <p>You can specify the staging labels to attach to the new
         * version in <code>VersionStages</code>. If you don't include
         * <code>VersionStages</code>, then Secrets Manager automatically moves the staging
         * label <code>AWSCURRENT</code> to this version. If this operation creates the
         * first version for the secret, then Secrets Manager automatically attaches the
         * staging label <code>AWSCURRENT</code> to it .</p> <p>If this operation moves the
         * staging label <code>AWSCURRENT</code> from another version to this version, then
         * Secrets Manager also automatically moves the staging label
         * <code>AWSPREVIOUS</code> to the version that <code>AWSCURRENT</code> was removed
         * from.</p> <p>This operation is idempotent. If a version with a
         * <code>VersionId</code> with the same value as the
         * <code>ClientRequestToken</code> parameter already exists, and you specify the
         * same secret data, the operation succeeds but does nothing. However, if the
         * secret data is different, then the operation fails because you can't modify an
         * existing version; you can only create new ones.</p> <p> <b>Required permissions:
         * </b> <code>secretsmanager:PutSecretValue</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/PutSecretValue">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::PutSecretValueOutcomeCallable PutSecretValueCallable(const Model::PutSecretValueRequest& request) const;

        /**
         * <p>Creates a new version with a new encrypted secret value and attaches it to
         * the secret. The version can contain a new <code>SecretString</code> value or a
         * new <code>SecretBinary</code> value. </p> <p>We recommend you avoid calling
         * <code>PutSecretValue</code> at a sustained rate of more than once every 10
         * minutes. When you update the secret value, Secrets Manager creates a new version
         * of the secret. Secrets Manager removes outdated versions when there are more
         * than 100, but it does not remove versions created less than 24 hours ago. If you
         * call <code>PutSecretValue</code> more than once every 10 minutes, you create
         * more versions than Secrets Manager removes, and you will reach the quota for
         * secret versions.</p> <p>You can specify the staging labels to attach to the new
         * version in <code>VersionStages</code>. If you don't include
         * <code>VersionStages</code>, then Secrets Manager automatically moves the staging
         * label <code>AWSCURRENT</code> to this version. If this operation creates the
         * first version for the secret, then Secrets Manager automatically attaches the
         * staging label <code>AWSCURRENT</code> to it .</p> <p>If this operation moves the
         * staging label <code>AWSCURRENT</code> from another version to this version, then
         * Secrets Manager also automatically moves the staging label
         * <code>AWSPREVIOUS</code> to the version that <code>AWSCURRENT</code> was removed
         * from.</p> <p>This operation is idempotent. If a version with a
         * <code>VersionId</code> with the same value as the
         * <code>ClientRequestToken</code> parameter already exists, and you specify the
         * same secret data, the operation succeeds but does nothing. However, if the
         * secret data is different, then the operation fails because you can't modify an
         * existing version; you can only create new ones.</p> <p> <b>Required permissions:
         * </b> <code>secretsmanager:PutSecretValue</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/PutSecretValue">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void PutSecretValueAsync(const Model::PutSecretValueRequest& request, const PutSecretValueResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>For a secret that is replicated to other Regions, deletes the secret replicas
         * from the Regions you specify.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:RemoveRegionsFromReplication</code>. For more information,
         * see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/RemoveRegionsFromReplication">AWS
         * API Reference</a></p>
         */
        virtual Model::RemoveRegionsFromReplicationOutcome RemoveRegionsFromReplication(const Model::RemoveRegionsFromReplicationRequest& request) const;

        /**
         * <p>For a secret that is replicated to other Regions, deletes the secret replicas
         * from the Regions you specify.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:RemoveRegionsFromReplication</code>. For more information,
         * see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/RemoveRegionsFromReplication">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::RemoveRegionsFromReplicationOutcomeCallable RemoveRegionsFromReplicationCallable(const Model::RemoveRegionsFromReplicationRequest& request) const;

        /**
         * <p>For a secret that is replicated to other Regions, deletes the secret replicas
         * from the Regions you specify.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:RemoveRegionsFromReplication</code>. For more information,
         * see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/RemoveRegionsFromReplication">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void RemoveRegionsFromReplicationAsync(const Model::RemoveRegionsFromReplicationRequest& request, const RemoveRegionsFromReplicationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Replicates the secret to a new Regions. See <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/create-manage-multi-region-secrets.html">Multi-Region
         * secrets</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:ReplicateSecretToRegions</code>. For more information, see
         * <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ReplicateSecretToRegions">AWS
         * API Reference</a></p>
         */
        virtual Model::ReplicateSecretToRegionsOutcome ReplicateSecretToRegions(const Model::ReplicateSecretToRegionsRequest& request) const;

        /**
         * <p>Replicates the secret to a new Regions. See <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/create-manage-multi-region-secrets.html">Multi-Region
         * secrets</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:ReplicateSecretToRegions</code>. For more information, see
         * <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ReplicateSecretToRegions">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::ReplicateSecretToRegionsOutcomeCallable ReplicateSecretToRegionsCallable(const Model::ReplicateSecretToRegionsRequest& request) const;

        /**
         * <p>Replicates the secret to a new Regions. See <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/create-manage-multi-region-secrets.html">Multi-Region
         * secrets</a>.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:ReplicateSecretToRegions</code>. For more information, see
         * <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ReplicateSecretToRegions">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void ReplicateSecretToRegionsAsync(const Model::ReplicateSecretToRegionsRequest& request, const ReplicateSecretToRegionsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Cancels the scheduled deletion of a secret by removing the
         * <code>DeletedDate</code> time stamp. You can access a secret again after it has
         * been restored.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:RestoreSecret</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/RestoreSecret">AWS
         * API Reference</a></p>
         */
        virtual Model::RestoreSecretOutcome RestoreSecret(const Model::RestoreSecretRequest& request) const;

        /**
         * <p>Cancels the scheduled deletion of a secret by removing the
         * <code>DeletedDate</code> time stamp. You can access a secret again after it has
         * been restored.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:RestoreSecret</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/RestoreSecret">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::RestoreSecretOutcomeCallable RestoreSecretCallable(const Model::RestoreSecretRequest& request) const;

        /**
         * <p>Cancels the scheduled deletion of a secret by removing the
         * <code>DeletedDate</code> time stamp. You can access a secret again after it has
         * been restored.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:RestoreSecret</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/RestoreSecret">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void RestoreSecretAsync(const Model::RestoreSecretRequest& request, const RestoreSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Configures and starts the asynchronous process of rotating the secret.</p>
         * <p>If you include the configuration parameters, the operation sets the values
         * for the secret and then immediately starts a rotation. If you don't include the
         * configuration parameters, the operation starts a rotation with the values
         * already stored in the secret. For more information about rotation, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/rotating-secrets.html">Rotate
         * secrets</a>.</p> <p>To configure rotation, you include the ARN of an Amazon Web
         * Services Lambda function and the schedule for the rotation. The Lambda rotation
         * function creates a new version of the secret and creates or updates the
         * credentials on the database or service to match. After testing the new
         * credentials, the function marks the new secret version with the staging label
         * <code>AWSCURRENT</code>. Then anyone who retrieves the secret gets the new
         * version. For more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/rotate-secrets_how.html">How
         * rotation works</a>.</p> <p>When rotation is successful, the
         * <code>AWSPENDING</code> staging label might be attached to the same version as
         * the <code>AWSCURRENT</code> version, or it might not be attached to any
         * version.</p> <p>If the <code>AWSPENDING</code> staging label is present but not
         * attached to the same version as <code>AWSCURRENT</code>, then any later
         * invocation of <code>RotateSecret</code> assumes that a previous rotation request
         * is still in progress and returns an error.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:RotateSecret</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. You also need
         * <code>lambda:InvokeFunction</code> permissions on the rotation function. For
         * more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/rotating-secrets-required-permissions-function.html">
         * Permissions for rotation</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/RotateSecret">AWS
         * API Reference</a></p>
         */
        virtual Model::RotateSecretOutcome RotateSecret(const Model::RotateSecretRequest& request) const;

        /**
         * <p>Configures and starts the asynchronous process of rotating the secret.</p>
         * <p>If you include the configuration parameters, the operation sets the values
         * for the secret and then immediately starts a rotation. If you don't include the
         * configuration parameters, the operation starts a rotation with the values
         * already stored in the secret. For more information about rotation, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/rotating-secrets.html">Rotate
         * secrets</a>.</p> <p>To configure rotation, you include the ARN of an Amazon Web
         * Services Lambda function and the schedule for the rotation. The Lambda rotation
         * function creates a new version of the secret and creates or updates the
         * credentials on the database or service to match. After testing the new
         * credentials, the function marks the new secret version with the staging label
         * <code>AWSCURRENT</code>. Then anyone who retrieves the secret gets the new
         * version. For more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/rotate-secrets_how.html">How
         * rotation works</a>.</p> <p>When rotation is successful, the
         * <code>AWSPENDING</code> staging label might be attached to the same version as
         * the <code>AWSCURRENT</code> version, or it might not be attached to any
         * version.</p> <p>If the <code>AWSPENDING</code> staging label is present but not
         * attached to the same version as <code>AWSCURRENT</code>, then any later
         * invocation of <code>RotateSecret</code> assumes that a previous rotation request
         * is still in progress and returns an error.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:RotateSecret</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. You also need
         * <code>lambda:InvokeFunction</code> permissions on the rotation function. For
         * more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/rotating-secrets-required-permissions-function.html">
         * Permissions for rotation</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/RotateSecret">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::RotateSecretOutcomeCallable RotateSecretCallable(const Model::RotateSecretRequest& request) const;

        /**
         * <p>Configures and starts the asynchronous process of rotating the secret.</p>
         * <p>If you include the configuration parameters, the operation sets the values
         * for the secret and then immediately starts a rotation. If you don't include the
         * configuration parameters, the operation starts a rotation with the values
         * already stored in the secret. For more information about rotation, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/rotating-secrets.html">Rotate
         * secrets</a>.</p> <p>To configure rotation, you include the ARN of an Amazon Web
         * Services Lambda function and the schedule for the rotation. The Lambda rotation
         * function creates a new version of the secret and creates or updates the
         * credentials on the database or service to match. After testing the new
         * credentials, the function marks the new secret version with the staging label
         * <code>AWSCURRENT</code>. Then anyone who retrieves the secret gets the new
         * version. For more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/rotate-secrets_how.html">How
         * rotation works</a>.</p> <p>When rotation is successful, the
         * <code>AWSPENDING</code> staging label might be attached to the same version as
         * the <code>AWSCURRENT</code> version, or it might not be attached to any
         * version.</p> <p>If the <code>AWSPENDING</code> staging label is present but not
         * attached to the same version as <code>AWSCURRENT</code>, then any later
         * invocation of <code>RotateSecret</code> assumes that a previous rotation request
         * is still in progress and returns an error.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:RotateSecret</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. You also need
         * <code>lambda:InvokeFunction</code> permissions on the rotation function. For
         * more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/rotating-secrets-required-permissions-function.html">
         * Permissions for rotation</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/RotateSecret">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void RotateSecretAsync(const Model::RotateSecretRequest& request, const RotateSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Removes the link between the replica secret and the primary secret and
         * promotes the replica to a primary secret in the replica Region.</p> <p>You must
         * call this operation from the Region in which you want to promote the replica to
         * a primary secret.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:StopReplicationToReplica</code>. For more information, see
         * <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/StopReplicationToReplica">AWS
         * API Reference</a></p>
         */
        virtual Model::StopReplicationToReplicaOutcome StopReplicationToReplica(const Model::StopReplicationToReplicaRequest& request) const;

        /**
         * <p>Removes the link between the replica secret and the primary secret and
         * promotes the replica to a primary secret in the replica Region.</p> <p>You must
         * call this operation from the Region in which you want to promote the replica to
         * a primary secret.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:StopReplicationToReplica</code>. For more information, see
         * <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/StopReplicationToReplica">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::StopReplicationToReplicaOutcomeCallable StopReplicationToReplicaCallable(const Model::StopReplicationToReplicaRequest& request) const;

        /**
         * <p>Removes the link between the replica secret and the primary secret and
         * promotes the replica to a primary secret in the replica Region.</p> <p>You must
         * call this operation from the Region in which you want to promote the replica to
         * a primary secret.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:StopReplicationToReplica</code>. For more information, see
         * <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/StopReplicationToReplica">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void StopReplicationToReplicaAsync(const Model::StopReplicationToReplicaRequest& request, const StopReplicationToReplicaResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Attaches tags to a secret. Tags consist of a key name and a value. Tags are
         * part of the secret's metadata. They are not associated with specific versions of
         * the secret. This operation appends tags to the existing list of tags.</p> <p>The
         * following restrictions apply to tags:</p> <ul> <li> <p>Maximum number of tags
         * per secret: 50</p> </li> <li> <p>Maximum key length: 127 Unicode characters in
         * UTF-8</p> </li> <li> <p>Maximum value length: 255 Unicode characters in
         * UTF-8</p> </li> <li> <p>Tag keys and values are case sensitive.</p> </li> <li>
         * <p>Do not use the <code>aws:</code> prefix in your tag names or values because
         * Amazon Web Services reserves it for Amazon Web Services use. You can't edit or
         * delete tag names or values with this prefix. Tags with this prefix do not count
         * against your tags per secret limit.</p> </li> <li> <p>If you use your tagging
         * schema across multiple services and resources, other services might have
         * restrictions on allowed characters. Generally allowed characters: letters,
         * spaces, and numbers representable in UTF-8, plus the following special
         * characters: + - = . _ : / @.</p> </li> </ul>  <p>If you use tags as
         * part of your security strategy, then adding or removing a tag can change
         * permissions. If successfully completing this operation would result in you
         * losing your permissions for this secret, then the operation is blocked and
         * returns an Access Denied error.</p>  <p> <b>Required permissions:
         * </b> <code>secretsmanager:TagResource</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/TagResource">AWS
         * API Reference</a></p>
         */
        virtual Model::TagResourceOutcome TagResource(const Model::TagResourceRequest& request) const;

        /**
         * <p>Attaches tags to a secret. Tags consist of a key name and a value. Tags are
         * part of the secret's metadata. They are not associated with specific versions of
         * the secret. This operation appends tags to the existing list of tags.</p> <p>The
         * following restrictions apply to tags:</p> <ul> <li> <p>Maximum number of tags
         * per secret: 50</p> </li> <li> <p>Maximum key length: 127 Unicode characters in
         * UTF-8</p> </li> <li> <p>Maximum value length: 255 Unicode characters in
         * UTF-8</p> </li> <li> <p>Tag keys and values are case sensitive.</p> </li> <li>
         * <p>Do not use the <code>aws:</code> prefix in your tag names or values because
         * Amazon Web Services reserves it for Amazon Web Services use. You can't edit or
         * delete tag names or values with this prefix. Tags with this prefix do not count
         * against your tags per secret limit.</p> </li> <li> <p>If you use your tagging
         * schema across multiple services and resources, other services might have
         * restrictions on allowed characters. Generally allowed characters: letters,
         * spaces, and numbers representable in UTF-8, plus the following special
         * characters: + - = . _ : / @.</p> </li> </ul>  <p>If you use tags as
         * part of your security strategy, then adding or removing a tag can change
         * permissions. If successfully completing this operation would result in you
         * losing your permissions for this secret, then the operation is blocked and
         * returns an Access Denied error.</p>  <p> <b>Required permissions:
         * </b> <code>secretsmanager:TagResource</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/TagResource">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::TagResourceOutcomeCallable TagResourceCallable(const Model::TagResourceRequest& request) const;

        /**
         * <p>Attaches tags to a secret. Tags consist of a key name and a value. Tags are
         * part of the secret's metadata. They are not associated with specific versions of
         * the secret. This operation appends tags to the existing list of tags.</p> <p>The
         * following restrictions apply to tags:</p> <ul> <li> <p>Maximum number of tags
         * per secret: 50</p> </li> <li> <p>Maximum key length: 127 Unicode characters in
         * UTF-8</p> </li> <li> <p>Maximum value length: 255 Unicode characters in
         * UTF-8</p> </li> <li> <p>Tag keys and values are case sensitive.</p> </li> <li>
         * <p>Do not use the <code>aws:</code> prefix in your tag names or values because
         * Amazon Web Services reserves it for Amazon Web Services use. You can't edit or
         * delete tag names or values with this prefix. Tags with this prefix do not count
         * against your tags per secret limit.</p> </li> <li> <p>If you use your tagging
         * schema across multiple services and resources, other services might have
         * restrictions on allowed characters. Generally allowed characters: letters,
         * spaces, and numbers representable in UTF-8, plus the following special
         * characters: + - = . _ : / @.</p> </li> </ul>  <p>If you use tags as
         * part of your security strategy, then adding or removing a tag can change
         * permissions. If successfully completing this operation would result in you
         * losing your permissions for this secret, then the operation is blocked and
         * returns an Access Denied error.</p>  <p> <b>Required permissions:
         * </b> <code>secretsmanager:TagResource</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/TagResource">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void TagResourceAsync(const Model::TagResourceRequest& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Removes specific tags from a secret.</p> <p>This operation is idempotent. If
         * a requested tag is not attached to the secret, no error is returned and the
         * secret metadata is unchanged.</p>  <p>If you use tags as part of your
         * security strategy, then removing a tag can change permissions. If successfully
         * completing this operation would result in you losing your permissions for this
         * secret, then the operation is blocked and returns an Access Denied error.</p>
         *  <p> <b>Required permissions: </b>
         * <code>secretsmanager:UntagResource</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/UntagResource">AWS
         * API Reference</a></p>
         */
        virtual Model::UntagResourceOutcome UntagResource(const Model::UntagResourceRequest& request) const;

        /**
         * <p>Removes specific tags from a secret.</p> <p>This operation is idempotent. If
         * a requested tag is not attached to the secret, no error is returned and the
         * secret metadata is unchanged.</p>  <p>If you use tags as part of your
         * security strategy, then removing a tag can change permissions. If successfully
         * completing this operation would result in you losing your permissions for this
         * secret, then the operation is blocked and returns an Access Denied error.</p>
         *  <p> <b>Required permissions: </b>
         * <code>secretsmanager:UntagResource</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/UntagResource">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::UntagResourceOutcomeCallable UntagResourceCallable(const Model::UntagResourceRequest& request) const;

        /**
         * <p>Removes specific tags from a secret.</p> <p>This operation is idempotent. If
         * a requested tag is not attached to the secret, no error is returned and the
         * secret metadata is unchanged.</p>  <p>If you use tags as part of your
         * security strategy, then removing a tag can change permissions. If successfully
         * completing this operation would result in you losing your permissions for this
         * secret, then the operation is blocked and returns an Access Denied error.</p>
         *  <p> <b>Required permissions: </b>
         * <code>secretsmanager:UntagResource</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/UntagResource">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void UntagResourceAsync(const Model::UntagResourceRequest& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Modifies the details of a secret, including metadata and the secret value. To
         * change the secret value, you can also use <a>PutSecretValue</a>.</p> <p>To
         * change the rotation configuration of a secret, use <a>RotateSecret</a>
         * instead.</p> <p>We recommend you avoid calling <code>UpdateSecret</code> at a
         * sustained rate of more than once every 10 minutes. When you call
         * <code>UpdateSecret</code> to update the secret value, Secrets Manager creates a
         * new version of the secret. Secrets Manager removes outdated versions when there
         * are more than 100, but it does not remove versions created less than 24 hours
         * ago. If you update the secret value more than once every 10 minutes, you create
         * more versions than Secrets Manager removes, and you will reach the quota for
         * secret versions.</p> <p>If you include <code>SecretString</code> or
         * <code>SecretBinary</code> to create a new secret version, Secrets Manager
         * automatically attaches the staging label <code>AWSCURRENT</code> to the new
         * version. </p> <p>If you call this operation with a <code>VersionId</code> that
         * matches an existing version's <code>ClientRequestToken</code>, the operation
         * results in an error. You can't modify an existing version, you can only create a
         * new version. To remove a version, remove all staging labels from it. See
         * <a>UpdateSecretVersionStage</a>.</p> <p>If you don't specify an KMS encryption
         * key, Secrets Manager uses the Amazon Web Services managed key
         * <code>aws/secretsmanager</code>. If this key doesn't already exist in your
         * account, then Secrets Manager creates it for you automatically. All users and
         * roles in the Amazon Web Services account automatically have access to use
         * <code>aws/secretsmanager</code>. Creating <code>aws/secretsmanager</code> can
         * result in a one-time significant delay in returning the result. </p> <p>If the
         * secret is in a different Amazon Web Services account from the credentials
         * calling the API, then you can't use <code>aws/secretsmanager</code> to encrypt
         * the secret, and you must create and use a customer managed key. </p> <p>
         * <b>Required permissions: </b> <code>secretsmanager:UpdateSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. If you use a customer managed key,
         * you must also have <code>kms:GenerateDataKey</code> and <code>kms:Decrypt</code>
         * permissions on the key. For more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/security-encryption.html">
         * Secret encryption and decryption</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/UpdateSecret">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateSecretOutcome UpdateSecret(const Model::UpdateSecretRequest& request) const;

        /**
         * <p>Modifies the details of a secret, including metadata and the secret value. To
         * change the secret value, you can also use <a>PutSecretValue</a>.</p> <p>To
         * change the rotation configuration of a secret, use <a>RotateSecret</a>
         * instead.</p> <p>We recommend you avoid calling <code>UpdateSecret</code> at a
         * sustained rate of more than once every 10 minutes. When you call
         * <code>UpdateSecret</code> to update the secret value, Secrets Manager creates a
         * new version of the secret. Secrets Manager removes outdated versions when there
         * are more than 100, but it does not remove versions created less than 24 hours
         * ago. If you update the secret value more than once every 10 minutes, you create
         * more versions than Secrets Manager removes, and you will reach the quota for
         * secret versions.</p> <p>If you include <code>SecretString</code> or
         * <code>SecretBinary</code> to create a new secret version, Secrets Manager
         * automatically attaches the staging label <code>AWSCURRENT</code> to the new
         * version. </p> <p>If you call this operation with a <code>VersionId</code> that
         * matches an existing version's <code>ClientRequestToken</code>, the operation
         * results in an error. You can't modify an existing version, you can only create a
         * new version. To remove a version, remove all staging labels from it. See
         * <a>UpdateSecretVersionStage</a>.</p> <p>If you don't specify an KMS encryption
         * key, Secrets Manager uses the Amazon Web Services managed key
         * <code>aws/secretsmanager</code>. If this key doesn't already exist in your
         * account, then Secrets Manager creates it for you automatically. All users and
         * roles in the Amazon Web Services account automatically have access to use
         * <code>aws/secretsmanager</code>. Creating <code>aws/secretsmanager</code> can
         * result in a one-time significant delay in returning the result. </p> <p>If the
         * secret is in a different Amazon Web Services account from the credentials
         * calling the API, then you can't use <code>aws/secretsmanager</code> to encrypt
         * the secret, and you must create and use a customer managed key. </p> <p>
         * <b>Required permissions: </b> <code>secretsmanager:UpdateSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. If you use a customer managed key,
         * you must also have <code>kms:GenerateDataKey</code> and <code>kms:Decrypt</code>
         * permissions on the key. For more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/security-encryption.html">
         * Secret encryption and decryption</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/UpdateSecret">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::UpdateSecretOutcomeCallable UpdateSecretCallable(const Model::UpdateSecretRequest& request) const;

        /**
         * <p>Modifies the details of a secret, including metadata and the secret value. To
         * change the secret value, you can also use <a>PutSecretValue</a>.</p> <p>To
         * change the rotation configuration of a secret, use <a>RotateSecret</a>
         * instead.</p> <p>We recommend you avoid calling <code>UpdateSecret</code> at a
         * sustained rate of more than once every 10 minutes. When you call
         * <code>UpdateSecret</code> to update the secret value, Secrets Manager creates a
         * new version of the secret. Secrets Manager removes outdated versions when there
         * are more than 100, but it does not remove versions created less than 24 hours
         * ago. If you update the secret value more than once every 10 minutes, you create
         * more versions than Secrets Manager removes, and you will reach the quota for
         * secret versions.</p> <p>If you include <code>SecretString</code> or
         * <code>SecretBinary</code> to create a new secret version, Secrets Manager
         * automatically attaches the staging label <code>AWSCURRENT</code> to the new
         * version. </p> <p>If you call this operation with a <code>VersionId</code> that
         * matches an existing version's <code>ClientRequestToken</code>, the operation
         * results in an error. You can't modify an existing version, you can only create a
         * new version. To remove a version, remove all staging labels from it. See
         * <a>UpdateSecretVersionStage</a>.</p> <p>If you don't specify an KMS encryption
         * key, Secrets Manager uses the Amazon Web Services managed key
         * <code>aws/secretsmanager</code>. If this key doesn't already exist in your
         * account, then Secrets Manager creates it for you automatically. All users and
         * roles in the Amazon Web Services account automatically have access to use
         * <code>aws/secretsmanager</code>. Creating <code>aws/secretsmanager</code> can
         * result in a one-time significant delay in returning the result. </p> <p>If the
         * secret is in a different Amazon Web Services account from the credentials
         * calling the API, then you can't use <code>aws/secretsmanager</code> to encrypt
         * the secret, and you must create and use a customer managed key. </p> <p>
         * <b>Required permissions: </b> <code>secretsmanager:UpdateSecret</code>. For more
         * information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. If you use a customer managed key,
         * you must also have <code>kms:GenerateDataKey</code> and <code>kms:Decrypt</code>
         * permissions on the key. For more information, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/security-encryption.html">
         * Secret encryption and decryption</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/UpdateSecret">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void UpdateSecretAsync(const Model::UpdateSecretRequest& request, const UpdateSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Modifies the staging labels attached to a version of a secret. Secrets
         * Manager uses staging labels to track a version as it progresses through the
         * secret rotation process. Each staging label can be attached to only one version
         * at a time. To add a staging label to a version when it is already attached to
         * another version, Secrets Manager first removes it from the other version first
         * and then attaches it to this one. For more information about versions and
         * staging labels, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/getting-started.html#term_version">Concepts:
         * Version</a>. </p> <p>The staging labels that you specify in the
         * <code>VersionStage</code> parameter are added to the existing list of staging
         * labels for the version. </p> <p>You can move the <code>AWSCURRENT</code> staging
         * label to this version by including it in this call.</p>  <p>Whenever you
         * move <code>AWSCURRENT</code>, Secrets Manager automatically moves the label
         * <code>AWSPREVIOUS</code> to the version that <code>AWSCURRENT</code> was removed
         * from.</p>  <p>If this action results in the last label being removed from
         * a version, then the version is considered to be 'deprecated' and can be deleted
         * by Secrets Manager.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:UpdateSecretVersionStage</code>. For more information, see
         * <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/UpdateSecretVersionStage">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateSecretVersionStageOutcome UpdateSecretVersionStage(const Model::UpdateSecretVersionStageRequest& request) const;

        /**
         * <p>Modifies the staging labels attached to a version of a secret. Secrets
         * Manager uses staging labels to track a version as it progresses through the
         * secret rotation process. Each staging label can be attached to only one version
         * at a time. To add a staging label to a version when it is already attached to
         * another version, Secrets Manager first removes it from the other version first
         * and then attaches it to this one. For more information about versions and
         * staging labels, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/getting-started.html#term_version">Concepts:
         * Version</a>. </p> <p>The staging labels that you specify in the
         * <code>VersionStage</code> parameter are added to the existing list of staging
         * labels for the version. </p> <p>You can move the <code>AWSCURRENT</code> staging
         * label to this version by including it in this call.</p>  <p>Whenever you
         * move <code>AWSCURRENT</code>, Secrets Manager automatically moves the label
         * <code>AWSPREVIOUS</code> to the version that <code>AWSCURRENT</code> was removed
         * from.</p>  <p>If this action results in the last label being removed from
         * a version, then the version is considered to be 'deprecated' and can be deleted
         * by Secrets Manager.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:UpdateSecretVersionStage</code>. For more information, see
         * <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/UpdateSecretVersionStage">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::UpdateSecretVersionStageOutcomeCallable UpdateSecretVersionStageCallable(const Model::UpdateSecretVersionStageRequest& request) const;

        /**
         * <p>Modifies the staging labels attached to a version of a secret. Secrets
         * Manager uses staging labels to track a version as it progresses through the
         * secret rotation process. Each staging label can be attached to only one version
         * at a time. To add a staging label to a version when it is already attached to
         * another version, Secrets Manager first removes it from the other version first
         * and then attaches it to this one. For more information about versions and
         * staging labels, see <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/getting-started.html#term_version">Concepts:
         * Version</a>. </p> <p>The staging labels that you specify in the
         * <code>VersionStage</code> parameter are added to the existing list of staging
         * labels for the version. </p> <p>You can move the <code>AWSCURRENT</code> staging
         * label to this version by including it in this call.</p>  <p>Whenever you
         * move <code>AWSCURRENT</code>, Secrets Manager automatically moves the label
         * <code>AWSPREVIOUS</code> to the version that <code>AWSCURRENT</code> was removed
         * from.</p>  <p>If this action results in the last label being removed from
         * a version, then the version is considered to be 'deprecated' and can be deleted
         * by Secrets Manager.</p> <p> <b>Required permissions: </b>
         * <code>secretsmanager:UpdateSecretVersionStage</code>. For more information, see
         * <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/UpdateSecretVersionStage">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void UpdateSecretVersionStageAsync(const Model::UpdateSecretVersionStageRequest& request, const UpdateSecretVersionStageResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Validates that a resource policy does not grant a wide range of principals
         * access to your secret. A resource-based policy is optional for secrets.</p>
         * <p>The API performs three checks when validating the policy:</p> <ul> <li>
         * <p>Sends a call to <a
         * href="https://aws.amazon.com/blogs/security/protect-sensitive-data-in-the-cloud-with-automated-reasoning-zelkova/">Zelkova</a>,
         * an automated reasoning engine, to ensure your resource policy does not allow
         * broad access to your secret, for example policies that use a wildcard for the
         * principal.</p> </li> <li> <p>Checks for correct syntax in a policy.</p> </li>
         * <li> <p>Verifies the policy does not lock out a caller.</p> </li> </ul> <p>
         * <b>Required permissions: </b>
         * <code>secretsmanager:ValidateResourcePolicy</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ValidateResourcePolicy">AWS
         * API Reference</a></p>
         */
        virtual Model::ValidateResourcePolicyOutcome ValidateResourcePolicy(const Model::ValidateResourcePolicyRequest& request) const;

        /**
         * <p>Validates that a resource policy does not grant a wide range of principals
         * access to your secret. A resource-based policy is optional for secrets.</p>
         * <p>The API performs three checks when validating the policy:</p> <ul> <li>
         * <p>Sends a call to <a
         * href="https://aws.amazon.com/blogs/security/protect-sensitive-data-in-the-cloud-with-automated-reasoning-zelkova/">Zelkova</a>,
         * an automated reasoning engine, to ensure your resource policy does not allow
         * broad access to your secret, for example policies that use a wildcard for the
         * principal.</p> </li> <li> <p>Checks for correct syntax in a policy.</p> </li>
         * <li> <p>Verifies the policy does not lock out a caller.</p> </li> </ul> <p>
         * <b>Required permissions: </b>
         * <code>secretsmanager:ValidateResourcePolicy</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ValidateResourcePolicy">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::ValidateResourcePolicyOutcomeCallable ValidateResourcePolicyCallable(const Model::ValidateResourcePolicyRequest& request) const;

        /**
         * <p>Validates that a resource policy does not grant a wide range of principals
         * access to your secret. A resource-based policy is optional for secrets.</p>
         * <p>The API performs three checks when validating the policy:</p> <ul> <li>
         * <p>Sends a call to <a
         * href="https://aws.amazon.com/blogs/security/protect-sensitive-data-in-the-cloud-with-automated-reasoning-zelkova/">Zelkova</a>,
         * an automated reasoning engine, to ensure your resource policy does not allow
         * broad access to your secret, for example policies that use a wildcard for the
         * principal.</p> </li> <li> <p>Checks for correct syntax in a policy.</p> </li>
         * <li> <p>Verifies the policy does not lock out a caller.</p> </li> </ul> <p>
         * <b>Required permissions: </b>
         * <code>secretsmanager:ValidateResourcePolicy</code>. For more information, see <a
         * href="https://docs.aws.amazon.com/service-authorization/latest/reference/list_awssecretsmanager.html#awssecretsmanager-actions-as-permissions">
         * IAM policy actions for Secrets Manager</a> and <a
         * href="https://docs.aws.amazon.com/secretsmanager/latest/userguide/auth-and-access.html">Authentication
         * and access control in Secrets Manager</a>. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/secretsmanager-2017-10-17/ValidateResourcePolicy">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void ValidateResourcePolicyAsync(const Model::ValidateResourcePolicyRequest& request, const ValidateResourcePolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;


      void OverrideEndpoint(const Aws::String& endpoint);
    private:
      void init(const Aws::Client::ClientConfiguration& clientConfiguration);
        void CancelRotateSecretAsyncHelper(const Model::CancelRotateSecretRequest& request, const CancelRotateSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateSecretAsyncHelper(const Model::CreateSecretRequest& request, const CreateSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteResourcePolicyAsyncHelper(const Model::DeleteResourcePolicyRequest& request, const DeleteResourcePolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteSecretAsyncHelper(const Model::DeleteSecretRequest& request, const DeleteSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeSecretAsyncHelper(const Model::DescribeSecretRequest& request, const DescribeSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void GetRandomPasswordAsyncHelper(const Model::GetRandomPasswordRequest& request, const GetRandomPasswordResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void GetResourcePolicyAsyncHelper(const Model::GetResourcePolicyRequest& request, const GetResourcePolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void GetSecretValueAsyncHelper(const Model::GetSecretValueRequest& request, const GetSecretValueResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void ListSecretVersionIdsAsyncHelper(const Model::ListSecretVersionIdsRequest& request, const ListSecretVersionIdsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void ListSecretsAsyncHelper(const Model::ListSecretsRequest& request, const ListSecretsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void PutResourcePolicyAsyncHelper(const Model::PutResourcePolicyRequest& request, const PutResourcePolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void PutSecretValueAsyncHelper(const Model::PutSecretValueRequest& request, const PutSecretValueResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void RemoveRegionsFromReplicationAsyncHelper(const Model::RemoveRegionsFromReplicationRequest& request, const RemoveRegionsFromReplicationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void ReplicateSecretToRegionsAsyncHelper(const Model::ReplicateSecretToRegionsRequest& request, const ReplicateSecretToRegionsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void RestoreSecretAsyncHelper(const Model::RestoreSecretRequest& request, const RestoreSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void RotateSecretAsyncHelper(const Model::RotateSecretRequest& request, const RotateSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void StopReplicationToReplicaAsyncHelper(const Model::StopReplicationToReplicaRequest& request, const StopReplicationToReplicaResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void TagResourceAsyncHelper(const Model::TagResourceRequest& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void UntagResourceAsyncHelper(const Model::UntagResourceRequest& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void UpdateSecretAsyncHelper(const Model::UpdateSecretRequest& request, const UpdateSecretResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void UpdateSecretVersionStageAsyncHelper(const Model::UpdateSecretVersionStageRequest& request, const UpdateSecretVersionStageResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void ValidateResourcePolicyAsyncHelper(const Model::ValidateResourcePolicyRequest& request, const ValidateResourcePolicyResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;

      Aws::String m_uri;
      Aws::String m_configScheme;
      std::shared_ptr<Aws::Utils::Threading::Executor> m_executor;
  };

} // namespace SecretsManager
} // namespace Aws
