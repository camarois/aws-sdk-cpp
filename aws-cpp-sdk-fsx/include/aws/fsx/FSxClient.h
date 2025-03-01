﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/fsx/FSx_EXPORTS.h>
#include <aws/fsx/FSxErrors.h>
#include <aws/core/client/AWSError.h>
#include <aws/core/client/ClientConfiguration.h>
#include <aws/core/client/AWSClient.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/json/JsonSerializer.h>
#include <aws/fsx/model/AssociateFileSystemAliasesResult.h>
#include <aws/fsx/model/CancelDataRepositoryTaskResult.h>
#include <aws/fsx/model/CopyBackupResult.h>
#include <aws/fsx/model/CreateBackupResult.h>
#include <aws/fsx/model/CreateDataRepositoryAssociationResult.h>
#include <aws/fsx/model/CreateDataRepositoryTaskResult.h>
#include <aws/fsx/model/CreateFileSystemResult.h>
#include <aws/fsx/model/CreateFileSystemFromBackupResult.h>
#include <aws/fsx/model/CreateSnapshotResult.h>
#include <aws/fsx/model/CreateStorageVirtualMachineResult.h>
#include <aws/fsx/model/CreateVolumeResult.h>
#include <aws/fsx/model/CreateVolumeFromBackupResult.h>
#include <aws/fsx/model/DeleteBackupResult.h>
#include <aws/fsx/model/DeleteDataRepositoryAssociationResult.h>
#include <aws/fsx/model/DeleteFileSystemResult.h>
#include <aws/fsx/model/DeleteSnapshotResult.h>
#include <aws/fsx/model/DeleteStorageVirtualMachineResult.h>
#include <aws/fsx/model/DeleteVolumeResult.h>
#include <aws/fsx/model/DescribeBackupsResult.h>
#include <aws/fsx/model/DescribeDataRepositoryAssociationsResult.h>
#include <aws/fsx/model/DescribeDataRepositoryTasksResult.h>
#include <aws/fsx/model/DescribeFileSystemAliasesResult.h>
#include <aws/fsx/model/DescribeFileSystemsResult.h>
#include <aws/fsx/model/DescribeSnapshotsResult.h>
#include <aws/fsx/model/DescribeStorageVirtualMachinesResult.h>
#include <aws/fsx/model/DescribeVolumesResult.h>
#include <aws/fsx/model/DisassociateFileSystemAliasesResult.h>
#include <aws/fsx/model/ListTagsForResourceResult.h>
#include <aws/fsx/model/ReleaseFileSystemNfsV3LocksResult.h>
#include <aws/fsx/model/RestoreVolumeFromSnapshotResult.h>
#include <aws/fsx/model/TagResourceResult.h>
#include <aws/fsx/model/UntagResourceResult.h>
#include <aws/fsx/model/UpdateDataRepositoryAssociationResult.h>
#include <aws/fsx/model/UpdateFileSystemResult.h>
#include <aws/fsx/model/UpdateSnapshotResult.h>
#include <aws/fsx/model/UpdateStorageVirtualMachineResult.h>
#include <aws/fsx/model/UpdateVolumeResult.h>
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

namespace FSx
{

namespace Model
{
        class AssociateFileSystemAliasesRequest;
        class CancelDataRepositoryTaskRequest;
        class CopyBackupRequest;
        class CreateBackupRequest;
        class CreateDataRepositoryAssociationRequest;
        class CreateDataRepositoryTaskRequest;
        class CreateFileSystemRequest;
        class CreateFileSystemFromBackupRequest;
        class CreateSnapshotRequest;
        class CreateStorageVirtualMachineRequest;
        class CreateVolumeRequest;
        class CreateVolumeFromBackupRequest;
        class DeleteBackupRequest;
        class DeleteDataRepositoryAssociationRequest;
        class DeleteFileSystemRequest;
        class DeleteSnapshotRequest;
        class DeleteStorageVirtualMachineRequest;
        class DeleteVolumeRequest;
        class DescribeBackupsRequest;
        class DescribeDataRepositoryAssociationsRequest;
        class DescribeDataRepositoryTasksRequest;
        class DescribeFileSystemAliasesRequest;
        class DescribeFileSystemsRequest;
        class DescribeSnapshotsRequest;
        class DescribeStorageVirtualMachinesRequest;
        class DescribeVolumesRequest;
        class DisassociateFileSystemAliasesRequest;
        class ListTagsForResourceRequest;
        class ReleaseFileSystemNfsV3LocksRequest;
        class RestoreVolumeFromSnapshotRequest;
        class TagResourceRequest;
        class UntagResourceRequest;
        class UpdateDataRepositoryAssociationRequest;
        class UpdateFileSystemRequest;
        class UpdateSnapshotRequest;
        class UpdateStorageVirtualMachineRequest;
        class UpdateVolumeRequest;

        typedef Aws::Utils::Outcome<AssociateFileSystemAliasesResult, FSxError> AssociateFileSystemAliasesOutcome;
        typedef Aws::Utils::Outcome<CancelDataRepositoryTaskResult, FSxError> CancelDataRepositoryTaskOutcome;
        typedef Aws::Utils::Outcome<CopyBackupResult, FSxError> CopyBackupOutcome;
        typedef Aws::Utils::Outcome<CreateBackupResult, FSxError> CreateBackupOutcome;
        typedef Aws::Utils::Outcome<CreateDataRepositoryAssociationResult, FSxError> CreateDataRepositoryAssociationOutcome;
        typedef Aws::Utils::Outcome<CreateDataRepositoryTaskResult, FSxError> CreateDataRepositoryTaskOutcome;
        typedef Aws::Utils::Outcome<CreateFileSystemResult, FSxError> CreateFileSystemOutcome;
        typedef Aws::Utils::Outcome<CreateFileSystemFromBackupResult, FSxError> CreateFileSystemFromBackupOutcome;
        typedef Aws::Utils::Outcome<CreateSnapshotResult, FSxError> CreateSnapshotOutcome;
        typedef Aws::Utils::Outcome<CreateStorageVirtualMachineResult, FSxError> CreateStorageVirtualMachineOutcome;
        typedef Aws::Utils::Outcome<CreateVolumeResult, FSxError> CreateVolumeOutcome;
        typedef Aws::Utils::Outcome<CreateVolumeFromBackupResult, FSxError> CreateVolumeFromBackupOutcome;
        typedef Aws::Utils::Outcome<DeleteBackupResult, FSxError> DeleteBackupOutcome;
        typedef Aws::Utils::Outcome<DeleteDataRepositoryAssociationResult, FSxError> DeleteDataRepositoryAssociationOutcome;
        typedef Aws::Utils::Outcome<DeleteFileSystemResult, FSxError> DeleteFileSystemOutcome;
        typedef Aws::Utils::Outcome<DeleteSnapshotResult, FSxError> DeleteSnapshotOutcome;
        typedef Aws::Utils::Outcome<DeleteStorageVirtualMachineResult, FSxError> DeleteStorageVirtualMachineOutcome;
        typedef Aws::Utils::Outcome<DeleteVolumeResult, FSxError> DeleteVolumeOutcome;
        typedef Aws::Utils::Outcome<DescribeBackupsResult, FSxError> DescribeBackupsOutcome;
        typedef Aws::Utils::Outcome<DescribeDataRepositoryAssociationsResult, FSxError> DescribeDataRepositoryAssociationsOutcome;
        typedef Aws::Utils::Outcome<DescribeDataRepositoryTasksResult, FSxError> DescribeDataRepositoryTasksOutcome;
        typedef Aws::Utils::Outcome<DescribeFileSystemAliasesResult, FSxError> DescribeFileSystemAliasesOutcome;
        typedef Aws::Utils::Outcome<DescribeFileSystemsResult, FSxError> DescribeFileSystemsOutcome;
        typedef Aws::Utils::Outcome<DescribeSnapshotsResult, FSxError> DescribeSnapshotsOutcome;
        typedef Aws::Utils::Outcome<DescribeStorageVirtualMachinesResult, FSxError> DescribeStorageVirtualMachinesOutcome;
        typedef Aws::Utils::Outcome<DescribeVolumesResult, FSxError> DescribeVolumesOutcome;
        typedef Aws::Utils::Outcome<DisassociateFileSystemAliasesResult, FSxError> DisassociateFileSystemAliasesOutcome;
        typedef Aws::Utils::Outcome<ListTagsForResourceResult, FSxError> ListTagsForResourceOutcome;
        typedef Aws::Utils::Outcome<ReleaseFileSystemNfsV3LocksResult, FSxError> ReleaseFileSystemNfsV3LocksOutcome;
        typedef Aws::Utils::Outcome<RestoreVolumeFromSnapshotResult, FSxError> RestoreVolumeFromSnapshotOutcome;
        typedef Aws::Utils::Outcome<TagResourceResult, FSxError> TagResourceOutcome;
        typedef Aws::Utils::Outcome<UntagResourceResult, FSxError> UntagResourceOutcome;
        typedef Aws::Utils::Outcome<UpdateDataRepositoryAssociationResult, FSxError> UpdateDataRepositoryAssociationOutcome;
        typedef Aws::Utils::Outcome<UpdateFileSystemResult, FSxError> UpdateFileSystemOutcome;
        typedef Aws::Utils::Outcome<UpdateSnapshotResult, FSxError> UpdateSnapshotOutcome;
        typedef Aws::Utils::Outcome<UpdateStorageVirtualMachineResult, FSxError> UpdateStorageVirtualMachineOutcome;
        typedef Aws::Utils::Outcome<UpdateVolumeResult, FSxError> UpdateVolumeOutcome;

        typedef std::future<AssociateFileSystemAliasesOutcome> AssociateFileSystemAliasesOutcomeCallable;
        typedef std::future<CancelDataRepositoryTaskOutcome> CancelDataRepositoryTaskOutcomeCallable;
        typedef std::future<CopyBackupOutcome> CopyBackupOutcomeCallable;
        typedef std::future<CreateBackupOutcome> CreateBackupOutcomeCallable;
        typedef std::future<CreateDataRepositoryAssociationOutcome> CreateDataRepositoryAssociationOutcomeCallable;
        typedef std::future<CreateDataRepositoryTaskOutcome> CreateDataRepositoryTaskOutcomeCallable;
        typedef std::future<CreateFileSystemOutcome> CreateFileSystemOutcomeCallable;
        typedef std::future<CreateFileSystemFromBackupOutcome> CreateFileSystemFromBackupOutcomeCallable;
        typedef std::future<CreateSnapshotOutcome> CreateSnapshotOutcomeCallable;
        typedef std::future<CreateStorageVirtualMachineOutcome> CreateStorageVirtualMachineOutcomeCallable;
        typedef std::future<CreateVolumeOutcome> CreateVolumeOutcomeCallable;
        typedef std::future<CreateVolumeFromBackupOutcome> CreateVolumeFromBackupOutcomeCallable;
        typedef std::future<DeleteBackupOutcome> DeleteBackupOutcomeCallable;
        typedef std::future<DeleteDataRepositoryAssociationOutcome> DeleteDataRepositoryAssociationOutcomeCallable;
        typedef std::future<DeleteFileSystemOutcome> DeleteFileSystemOutcomeCallable;
        typedef std::future<DeleteSnapshotOutcome> DeleteSnapshotOutcomeCallable;
        typedef std::future<DeleteStorageVirtualMachineOutcome> DeleteStorageVirtualMachineOutcomeCallable;
        typedef std::future<DeleteVolumeOutcome> DeleteVolumeOutcomeCallable;
        typedef std::future<DescribeBackupsOutcome> DescribeBackupsOutcomeCallable;
        typedef std::future<DescribeDataRepositoryAssociationsOutcome> DescribeDataRepositoryAssociationsOutcomeCallable;
        typedef std::future<DescribeDataRepositoryTasksOutcome> DescribeDataRepositoryTasksOutcomeCallable;
        typedef std::future<DescribeFileSystemAliasesOutcome> DescribeFileSystemAliasesOutcomeCallable;
        typedef std::future<DescribeFileSystemsOutcome> DescribeFileSystemsOutcomeCallable;
        typedef std::future<DescribeSnapshotsOutcome> DescribeSnapshotsOutcomeCallable;
        typedef std::future<DescribeStorageVirtualMachinesOutcome> DescribeStorageVirtualMachinesOutcomeCallable;
        typedef std::future<DescribeVolumesOutcome> DescribeVolumesOutcomeCallable;
        typedef std::future<DisassociateFileSystemAliasesOutcome> DisassociateFileSystemAliasesOutcomeCallable;
        typedef std::future<ListTagsForResourceOutcome> ListTagsForResourceOutcomeCallable;
        typedef std::future<ReleaseFileSystemNfsV3LocksOutcome> ReleaseFileSystemNfsV3LocksOutcomeCallable;
        typedef std::future<RestoreVolumeFromSnapshotOutcome> RestoreVolumeFromSnapshotOutcomeCallable;
        typedef std::future<TagResourceOutcome> TagResourceOutcomeCallable;
        typedef std::future<UntagResourceOutcome> UntagResourceOutcomeCallable;
        typedef std::future<UpdateDataRepositoryAssociationOutcome> UpdateDataRepositoryAssociationOutcomeCallable;
        typedef std::future<UpdateFileSystemOutcome> UpdateFileSystemOutcomeCallable;
        typedef std::future<UpdateSnapshotOutcome> UpdateSnapshotOutcomeCallable;
        typedef std::future<UpdateStorageVirtualMachineOutcome> UpdateStorageVirtualMachineOutcomeCallable;
        typedef std::future<UpdateVolumeOutcome> UpdateVolumeOutcomeCallable;
} // namespace Model

  class FSxClient;

    typedef std::function<void(const FSxClient*, const Model::AssociateFileSystemAliasesRequest&, const Model::AssociateFileSystemAliasesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > AssociateFileSystemAliasesResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::CancelDataRepositoryTaskRequest&, const Model::CancelDataRepositoryTaskOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CancelDataRepositoryTaskResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::CopyBackupRequest&, const Model::CopyBackupOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CopyBackupResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::CreateBackupRequest&, const Model::CreateBackupOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateBackupResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::CreateDataRepositoryAssociationRequest&, const Model::CreateDataRepositoryAssociationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateDataRepositoryAssociationResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::CreateDataRepositoryTaskRequest&, const Model::CreateDataRepositoryTaskOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateDataRepositoryTaskResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::CreateFileSystemRequest&, const Model::CreateFileSystemOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateFileSystemResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::CreateFileSystemFromBackupRequest&, const Model::CreateFileSystemFromBackupOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateFileSystemFromBackupResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::CreateSnapshotRequest&, const Model::CreateSnapshotOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateSnapshotResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::CreateStorageVirtualMachineRequest&, const Model::CreateStorageVirtualMachineOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateStorageVirtualMachineResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::CreateVolumeRequest&, const Model::CreateVolumeOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateVolumeResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::CreateVolumeFromBackupRequest&, const Model::CreateVolumeFromBackupOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > CreateVolumeFromBackupResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DeleteBackupRequest&, const Model::DeleteBackupOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteBackupResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DeleteDataRepositoryAssociationRequest&, const Model::DeleteDataRepositoryAssociationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteDataRepositoryAssociationResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DeleteFileSystemRequest&, const Model::DeleteFileSystemOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteFileSystemResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DeleteSnapshotRequest&, const Model::DeleteSnapshotOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteSnapshotResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DeleteStorageVirtualMachineRequest&, const Model::DeleteStorageVirtualMachineOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteStorageVirtualMachineResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DeleteVolumeRequest&, const Model::DeleteVolumeOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DeleteVolumeResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DescribeBackupsRequest&, const Model::DescribeBackupsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeBackupsResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DescribeDataRepositoryAssociationsRequest&, const Model::DescribeDataRepositoryAssociationsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeDataRepositoryAssociationsResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DescribeDataRepositoryTasksRequest&, const Model::DescribeDataRepositoryTasksOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeDataRepositoryTasksResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DescribeFileSystemAliasesRequest&, const Model::DescribeFileSystemAliasesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeFileSystemAliasesResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DescribeFileSystemsRequest&, const Model::DescribeFileSystemsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeFileSystemsResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DescribeSnapshotsRequest&, const Model::DescribeSnapshotsOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeSnapshotsResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DescribeStorageVirtualMachinesRequest&, const Model::DescribeStorageVirtualMachinesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeStorageVirtualMachinesResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DescribeVolumesRequest&, const Model::DescribeVolumesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DescribeVolumesResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::DisassociateFileSystemAliasesRequest&, const Model::DisassociateFileSystemAliasesOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > DisassociateFileSystemAliasesResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::ListTagsForResourceRequest&, const Model::ListTagsForResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ListTagsForResourceResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::ReleaseFileSystemNfsV3LocksRequest&, const Model::ReleaseFileSystemNfsV3LocksOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > ReleaseFileSystemNfsV3LocksResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::RestoreVolumeFromSnapshotRequest&, const Model::RestoreVolumeFromSnapshotOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > RestoreVolumeFromSnapshotResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::TagResourceRequest&, const Model::TagResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > TagResourceResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::UntagResourceRequest&, const Model::UntagResourceOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UntagResourceResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::UpdateDataRepositoryAssociationRequest&, const Model::UpdateDataRepositoryAssociationOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateDataRepositoryAssociationResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::UpdateFileSystemRequest&, const Model::UpdateFileSystemOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateFileSystemResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::UpdateSnapshotRequest&, const Model::UpdateSnapshotOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateSnapshotResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::UpdateStorageVirtualMachineRequest&, const Model::UpdateStorageVirtualMachineOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateStorageVirtualMachineResponseReceivedHandler;
    typedef std::function<void(const FSxClient*, const Model::UpdateVolumeRequest&, const Model::UpdateVolumeOutcome&, const std::shared_ptr<const Aws::Client::AsyncCallerContext>&) > UpdateVolumeResponseReceivedHandler;

  /**
   * <p>Amazon FSx is a fully managed service that makes it easy for storage and
   * application administrators to launch and use shared file storage.</p>
   */
  class AWS_FSX_API FSxClient : public Aws::Client::AWSJsonClient
  {
    public:
      typedef Aws::Client::AWSJsonClient BASECLASS;

       /**
        * Initializes client to use DefaultCredentialProviderChain, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        FSxClient(const Aws::Client::ClientConfiguration& clientConfiguration = Aws::Client::ClientConfiguration());

       /**
        * Initializes client to use SimpleAWSCredentialsProvider, with default http client factory, and optional client config. If client config
        * is not specified, it will be initialized to default values.
        */
        FSxClient(const Aws::Auth::AWSCredentials& credentials, const Aws::Client::ClientConfiguration& clientConfiguration = Aws::Client::ClientConfiguration());

       /**
        * Initializes client to use specified credentials provider with specified client config. If http client factory is not supplied,
        * the default http client factory will be used
        */
        FSxClient(const std::shared_ptr<Aws::Auth::AWSCredentialsProvider>& credentialsProvider,
            const Aws::Client::ClientConfiguration& clientConfiguration = Aws::Client::ClientConfiguration());

        virtual ~FSxClient();


        /**
         * <p>Use this action to associate one or more Domain Name Server (DNS) aliases
         * with an existing Amazon FSx for Windows File Server file system. A file system
         * can have a maximum of 50 DNS aliases associated with it at any one time. If you
         * try to associate a DNS alias that is already associated with the file system,
         * FSx takes no action on that alias in the request. For more information, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/managing-dns-aliases.html">Working
         * with DNS Aliases</a> and <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/walkthrough05-file-system-custom-CNAME.html">Walkthrough
         * 5: Using DNS aliases to access your file system</a>, including additional steps
         * you must take to be able to access your file system using a DNS alias.</p>
         * <p>The system response shows the DNS aliases that Amazon FSx is attempting to
         * associate with the file system. Use the API operation to monitor the status of
         * the aliases Amazon FSx is associating with the file system.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/AssociateFileSystemAliases">AWS
         * API Reference</a></p>
         */
        virtual Model::AssociateFileSystemAliasesOutcome AssociateFileSystemAliases(const Model::AssociateFileSystemAliasesRequest& request) const;

        /**
         * <p>Use this action to associate one or more Domain Name Server (DNS) aliases
         * with an existing Amazon FSx for Windows File Server file system. A file system
         * can have a maximum of 50 DNS aliases associated with it at any one time. If you
         * try to associate a DNS alias that is already associated with the file system,
         * FSx takes no action on that alias in the request. For more information, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/managing-dns-aliases.html">Working
         * with DNS Aliases</a> and <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/walkthrough05-file-system-custom-CNAME.html">Walkthrough
         * 5: Using DNS aliases to access your file system</a>, including additional steps
         * you must take to be able to access your file system using a DNS alias.</p>
         * <p>The system response shows the DNS aliases that Amazon FSx is attempting to
         * associate with the file system. Use the API operation to monitor the status of
         * the aliases Amazon FSx is associating with the file system.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/AssociateFileSystemAliases">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::AssociateFileSystemAliasesOutcomeCallable AssociateFileSystemAliasesCallable(const Model::AssociateFileSystemAliasesRequest& request) const;

        /**
         * <p>Use this action to associate one or more Domain Name Server (DNS) aliases
         * with an existing Amazon FSx for Windows File Server file system. A file system
         * can have a maximum of 50 DNS aliases associated with it at any one time. If you
         * try to associate a DNS alias that is already associated with the file system,
         * FSx takes no action on that alias in the request. For more information, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/managing-dns-aliases.html">Working
         * with DNS Aliases</a> and <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/walkthrough05-file-system-custom-CNAME.html">Walkthrough
         * 5: Using DNS aliases to access your file system</a>, including additional steps
         * you must take to be able to access your file system using a DNS alias.</p>
         * <p>The system response shows the DNS aliases that Amazon FSx is attempting to
         * associate with the file system. Use the API operation to monitor the status of
         * the aliases Amazon FSx is associating with the file system.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/AssociateFileSystemAliases">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void AssociateFileSystemAliasesAsync(const Model::AssociateFileSystemAliasesRequest& request, const AssociateFileSystemAliasesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Cancels an existing Amazon FSx for Lustre data repository task if that task
         * is in either the <code>PENDING</code> or <code>EXECUTING</code> state. When you
         * cancel a task, Amazon FSx does the following.</p> <ul> <li> <p>Any files that
         * FSx has already exported are not reverted.</p> </li> <li> <p>FSx continues to
         * export any files that are "in-flight" when the cancel operation is received.</p>
         * </li> <li> <p>FSx does not export any files that have not yet been exported.</p>
         * </li> </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CancelDataRepositoryTask">AWS
         * API Reference</a></p>
         */
        virtual Model::CancelDataRepositoryTaskOutcome CancelDataRepositoryTask(const Model::CancelDataRepositoryTaskRequest& request) const;

        /**
         * <p>Cancels an existing Amazon FSx for Lustre data repository task if that task
         * is in either the <code>PENDING</code> or <code>EXECUTING</code> state. When you
         * cancel a task, Amazon FSx does the following.</p> <ul> <li> <p>Any files that
         * FSx has already exported are not reverted.</p> </li> <li> <p>FSx continues to
         * export any files that are "in-flight" when the cancel operation is received.</p>
         * </li> <li> <p>FSx does not export any files that have not yet been exported.</p>
         * </li> </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CancelDataRepositoryTask">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CancelDataRepositoryTaskOutcomeCallable CancelDataRepositoryTaskCallable(const Model::CancelDataRepositoryTaskRequest& request) const;

        /**
         * <p>Cancels an existing Amazon FSx for Lustre data repository task if that task
         * is in either the <code>PENDING</code> or <code>EXECUTING</code> state. When you
         * cancel a task, Amazon FSx does the following.</p> <ul> <li> <p>Any files that
         * FSx has already exported are not reverted.</p> </li> <li> <p>FSx continues to
         * export any files that are "in-flight" when the cancel operation is received.</p>
         * </li> <li> <p>FSx does not export any files that have not yet been exported.</p>
         * </li> </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CancelDataRepositoryTask">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CancelDataRepositoryTaskAsync(const Model::CancelDataRepositoryTaskRequest& request, const CancelDataRepositoryTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Copies an existing backup within the same Amazon Web Services account to
         * another Amazon Web Services Region (cross-Region copy) or within the same Amazon
         * Web Services Region (in-Region copy). You can have up to five backup copy
         * requests in progress to a single destination Region per account.</p> <p>You can
         * use cross-Region backup copies for cross-Region disaster recovery. You can
         * periodically take backups and copy them to another Region so that in the event
         * of a disaster in the primary Region, you can restore from backup and recover
         * availability quickly in the other Region. You can make cross-Region copies only
         * within your Amazon Web Services partition. A partition is a grouping of Regions.
         * Amazon Web Services currently has three partitions: <code>aws</code> (Standard
         * Regions), <code>aws-cn</code> (China Regions), and <code>aws-us-gov</code>
         * (Amazon Web Services GovCloud [US] Regions).</p> <p>You can also use backup
         * copies to clone your file dataset to another Region or within the same
         * Region.</p> <p>You can use the <code>SourceRegion</code> parameter to specify
         * the Amazon Web Services Region from which the backup will be copied. For
         * example, if you make the call from the <code>us-west-1</code> Region and want to
         * copy a backup from the <code>us-east-2</code> Region, you specify
         * <code>us-east-2</code> in the <code>SourceRegion</code> parameter to make a
         * cross-Region copy. If you don't specify a Region, the backup copy is created in
         * the same Region where the request is sent from (in-Region copy).</p> <p>For more
         * information about creating backup copies, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/using-backups.html#copy-backups">
         * Copying backups</a> in the <i>Amazon FSx for Windows User Guide</i>, <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/using-backups-fsx.html#copy-backups">Copying
         * backups</a> in the <i>Amazon FSx for Lustre User Guide</i>, and <a
         * href="https://docs.aws.amazon.com/fsx/latest/OpenZFSGuide/using-backups.html#copy-backups">Copying
         * backups</a> in the <i>Amazon FSx for OpenZFS User Guide</i>.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CopyBackup">AWS API
         * Reference</a></p>
         */
        virtual Model::CopyBackupOutcome CopyBackup(const Model::CopyBackupRequest& request) const;

        /**
         * <p>Copies an existing backup within the same Amazon Web Services account to
         * another Amazon Web Services Region (cross-Region copy) or within the same Amazon
         * Web Services Region (in-Region copy). You can have up to five backup copy
         * requests in progress to a single destination Region per account.</p> <p>You can
         * use cross-Region backup copies for cross-Region disaster recovery. You can
         * periodically take backups and copy them to another Region so that in the event
         * of a disaster in the primary Region, you can restore from backup and recover
         * availability quickly in the other Region. You can make cross-Region copies only
         * within your Amazon Web Services partition. A partition is a grouping of Regions.
         * Amazon Web Services currently has three partitions: <code>aws</code> (Standard
         * Regions), <code>aws-cn</code> (China Regions), and <code>aws-us-gov</code>
         * (Amazon Web Services GovCloud [US] Regions).</p> <p>You can also use backup
         * copies to clone your file dataset to another Region or within the same
         * Region.</p> <p>You can use the <code>SourceRegion</code> parameter to specify
         * the Amazon Web Services Region from which the backup will be copied. For
         * example, if you make the call from the <code>us-west-1</code> Region and want to
         * copy a backup from the <code>us-east-2</code> Region, you specify
         * <code>us-east-2</code> in the <code>SourceRegion</code> parameter to make a
         * cross-Region copy. If you don't specify a Region, the backup copy is created in
         * the same Region where the request is sent from (in-Region copy).</p> <p>For more
         * information about creating backup copies, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/using-backups.html#copy-backups">
         * Copying backups</a> in the <i>Amazon FSx for Windows User Guide</i>, <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/using-backups-fsx.html#copy-backups">Copying
         * backups</a> in the <i>Amazon FSx for Lustre User Guide</i>, and <a
         * href="https://docs.aws.amazon.com/fsx/latest/OpenZFSGuide/using-backups.html#copy-backups">Copying
         * backups</a> in the <i>Amazon FSx for OpenZFS User Guide</i>.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CopyBackup">AWS API
         * Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CopyBackupOutcomeCallable CopyBackupCallable(const Model::CopyBackupRequest& request) const;

        /**
         * <p>Copies an existing backup within the same Amazon Web Services account to
         * another Amazon Web Services Region (cross-Region copy) or within the same Amazon
         * Web Services Region (in-Region copy). You can have up to five backup copy
         * requests in progress to a single destination Region per account.</p> <p>You can
         * use cross-Region backup copies for cross-Region disaster recovery. You can
         * periodically take backups and copy them to another Region so that in the event
         * of a disaster in the primary Region, you can restore from backup and recover
         * availability quickly in the other Region. You can make cross-Region copies only
         * within your Amazon Web Services partition. A partition is a grouping of Regions.
         * Amazon Web Services currently has three partitions: <code>aws</code> (Standard
         * Regions), <code>aws-cn</code> (China Regions), and <code>aws-us-gov</code>
         * (Amazon Web Services GovCloud [US] Regions).</p> <p>You can also use backup
         * copies to clone your file dataset to another Region or within the same
         * Region.</p> <p>You can use the <code>SourceRegion</code> parameter to specify
         * the Amazon Web Services Region from which the backup will be copied. For
         * example, if you make the call from the <code>us-west-1</code> Region and want to
         * copy a backup from the <code>us-east-2</code> Region, you specify
         * <code>us-east-2</code> in the <code>SourceRegion</code> parameter to make a
         * cross-Region copy. If you don't specify a Region, the backup copy is created in
         * the same Region where the request is sent from (in-Region copy).</p> <p>For more
         * information about creating backup copies, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/using-backups.html#copy-backups">
         * Copying backups</a> in the <i>Amazon FSx for Windows User Guide</i>, <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/using-backups-fsx.html#copy-backups">Copying
         * backups</a> in the <i>Amazon FSx for Lustre User Guide</i>, and <a
         * href="https://docs.aws.amazon.com/fsx/latest/OpenZFSGuide/using-backups.html#copy-backups">Copying
         * backups</a> in the <i>Amazon FSx for OpenZFS User Guide</i>.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CopyBackup">AWS API
         * Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CopyBackupAsync(const Model::CopyBackupRequest& request, const CopyBackupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates a backup of an existing Amazon FSx for Windows File Server file
         * system, Amazon FSx for Lustre file system, Amazon FSx for NetApp ONTAP volume,
         * or Amazon FSx for OpenZFS file system. We recommend creating regular backups so
         * that you can restore a file system or volume from a backup if an issue arises
         * with the original file system or volume.</p> <p>For Amazon FSx for Lustre file
         * systems, you can create a backup only for file systems that have the following
         * configuration:</p> <ul> <li> <p>A Persistent deployment type</p> </li> <li>
         * <p>Are <i>not</i> linked to a data repository</p> </li> </ul> <p>For more
         * information about backups, see the following:</p> <ul> <li> <p>For Amazon FSx
         * for Lustre, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/using-backups-fsx.html">Working
         * with FSx for Lustre backups</a>.</p> </li> <li> <p>For Amazon FSx for Windows,
         * see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/using-backups.html">Working
         * with FSx for Windows backups</a>.</p> </li> <li> <p>For Amazon FSx for NetApp
         * ONTAP, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/ONTAPGuide/using-backups.html">Working
         * with FSx for NetApp ONTAP backups</a>.</p> </li> <li> <p>For Amazon FSx for
         * OpenZFS, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/OpenZFSGuide/using-backups.html">Working
         * with FSx for OpenZFS backups</a>.</p> </li> </ul> <p>If a backup with the
         * specified client request token exists and the parameters match, this operation
         * returns the description of the existing backup. If a backup with the specified
         * client request token exists and the parameters don't match, this operation
         * returns <code>IncompatibleParameterError</code>. If a backup with the specified
         * client request token doesn't exist, <code>CreateBackup</code> does the
         * following: </p> <ul> <li> <p>Creates a new Amazon FSx backup with an assigned
         * ID, and an initial lifecycle state of <code>CREATING</code>.</p> </li> <li>
         * <p>Returns the description of the backup.</p> </li> </ul> <p>By using the
         * idempotent operation, you can retry a <code>CreateBackup</code> operation
         * without the risk of creating an extra backup. This approach can be useful when
         * an initial call fails in a way that makes it unclear whether a backup was
         * created. If you use the same client request token and the initial call created a
         * backup, the operation returns a successful result because all the parameters are
         * the same.</p> <p>The <code>CreateBackup</code> operation returns while the
         * backup's lifecycle state is still <code>CREATING</code>. You can check the
         * backup creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeBackups.html">DescribeBackups</a>
         * operation, which returns the backup state along with other
         * information.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateBackup">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateBackupOutcome CreateBackup(const Model::CreateBackupRequest& request) const;

        /**
         * <p>Creates a backup of an existing Amazon FSx for Windows File Server file
         * system, Amazon FSx for Lustre file system, Amazon FSx for NetApp ONTAP volume,
         * or Amazon FSx for OpenZFS file system. We recommend creating regular backups so
         * that you can restore a file system or volume from a backup if an issue arises
         * with the original file system or volume.</p> <p>For Amazon FSx for Lustre file
         * systems, you can create a backup only for file systems that have the following
         * configuration:</p> <ul> <li> <p>A Persistent deployment type</p> </li> <li>
         * <p>Are <i>not</i> linked to a data repository</p> </li> </ul> <p>For more
         * information about backups, see the following:</p> <ul> <li> <p>For Amazon FSx
         * for Lustre, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/using-backups-fsx.html">Working
         * with FSx for Lustre backups</a>.</p> </li> <li> <p>For Amazon FSx for Windows,
         * see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/using-backups.html">Working
         * with FSx for Windows backups</a>.</p> </li> <li> <p>For Amazon FSx for NetApp
         * ONTAP, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/ONTAPGuide/using-backups.html">Working
         * with FSx for NetApp ONTAP backups</a>.</p> </li> <li> <p>For Amazon FSx for
         * OpenZFS, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/OpenZFSGuide/using-backups.html">Working
         * with FSx for OpenZFS backups</a>.</p> </li> </ul> <p>If a backup with the
         * specified client request token exists and the parameters match, this operation
         * returns the description of the existing backup. If a backup with the specified
         * client request token exists and the parameters don't match, this operation
         * returns <code>IncompatibleParameterError</code>. If a backup with the specified
         * client request token doesn't exist, <code>CreateBackup</code> does the
         * following: </p> <ul> <li> <p>Creates a new Amazon FSx backup with an assigned
         * ID, and an initial lifecycle state of <code>CREATING</code>.</p> </li> <li>
         * <p>Returns the description of the backup.</p> </li> </ul> <p>By using the
         * idempotent operation, you can retry a <code>CreateBackup</code> operation
         * without the risk of creating an extra backup. This approach can be useful when
         * an initial call fails in a way that makes it unclear whether a backup was
         * created. If you use the same client request token and the initial call created a
         * backup, the operation returns a successful result because all the parameters are
         * the same.</p> <p>The <code>CreateBackup</code> operation returns while the
         * backup's lifecycle state is still <code>CREATING</code>. You can check the
         * backup creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeBackups.html">DescribeBackups</a>
         * operation, which returns the backup state along with other
         * information.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateBackup">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateBackupOutcomeCallable CreateBackupCallable(const Model::CreateBackupRequest& request) const;

        /**
         * <p>Creates a backup of an existing Amazon FSx for Windows File Server file
         * system, Amazon FSx for Lustre file system, Amazon FSx for NetApp ONTAP volume,
         * or Amazon FSx for OpenZFS file system. We recommend creating regular backups so
         * that you can restore a file system or volume from a backup if an issue arises
         * with the original file system or volume.</p> <p>For Amazon FSx for Lustre file
         * systems, you can create a backup only for file systems that have the following
         * configuration:</p> <ul> <li> <p>A Persistent deployment type</p> </li> <li>
         * <p>Are <i>not</i> linked to a data repository</p> </li> </ul> <p>For more
         * information about backups, see the following:</p> <ul> <li> <p>For Amazon FSx
         * for Lustre, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/using-backups-fsx.html">Working
         * with FSx for Lustre backups</a>.</p> </li> <li> <p>For Amazon FSx for Windows,
         * see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/using-backups.html">Working
         * with FSx for Windows backups</a>.</p> </li> <li> <p>For Amazon FSx for NetApp
         * ONTAP, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/ONTAPGuide/using-backups.html">Working
         * with FSx for NetApp ONTAP backups</a>.</p> </li> <li> <p>For Amazon FSx for
         * OpenZFS, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/OpenZFSGuide/using-backups.html">Working
         * with FSx for OpenZFS backups</a>.</p> </li> </ul> <p>If a backup with the
         * specified client request token exists and the parameters match, this operation
         * returns the description of the existing backup. If a backup with the specified
         * client request token exists and the parameters don't match, this operation
         * returns <code>IncompatibleParameterError</code>. If a backup with the specified
         * client request token doesn't exist, <code>CreateBackup</code> does the
         * following: </p> <ul> <li> <p>Creates a new Amazon FSx backup with an assigned
         * ID, and an initial lifecycle state of <code>CREATING</code>.</p> </li> <li>
         * <p>Returns the description of the backup.</p> </li> </ul> <p>By using the
         * idempotent operation, you can retry a <code>CreateBackup</code> operation
         * without the risk of creating an extra backup. This approach can be useful when
         * an initial call fails in a way that makes it unclear whether a backup was
         * created. If you use the same client request token and the initial call created a
         * backup, the operation returns a successful result because all the parameters are
         * the same.</p> <p>The <code>CreateBackup</code> operation returns while the
         * backup's lifecycle state is still <code>CREATING</code>. You can check the
         * backup creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeBackups.html">DescribeBackups</a>
         * operation, which returns the backup state along with other
         * information.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateBackup">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateBackupAsync(const Model::CreateBackupRequest& request, const CreateBackupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates an Amazon FSx for Lustre data repository association (DRA). A data
         * repository association is a link between a directory on the file system and an
         * Amazon S3 bucket or prefix. You can have a maximum of 8 data repository
         * associations on a file system. Data repository associations are supported only
         * for file systems with the <code>Persistent_2</code> deployment type.</p> <p>Each
         * data repository association must have a unique Amazon FSx file system directory
         * and a unique S3 bucket or prefix associated with it. You can configure a data
         * repository association for automatic import only, for automatic export only, or
         * for both. To learn more about linking a data repository to your file system, see
         * <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/create-dra-linked-data-repo.html">Linking
         * your file system to an S3 bucket</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateDataRepositoryAssociation">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateDataRepositoryAssociationOutcome CreateDataRepositoryAssociation(const Model::CreateDataRepositoryAssociationRequest& request) const;

        /**
         * <p>Creates an Amazon FSx for Lustre data repository association (DRA). A data
         * repository association is a link between a directory on the file system and an
         * Amazon S3 bucket or prefix. You can have a maximum of 8 data repository
         * associations on a file system. Data repository associations are supported only
         * for file systems with the <code>Persistent_2</code> deployment type.</p> <p>Each
         * data repository association must have a unique Amazon FSx file system directory
         * and a unique S3 bucket or prefix associated with it. You can configure a data
         * repository association for automatic import only, for automatic export only, or
         * for both. To learn more about linking a data repository to your file system, see
         * <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/create-dra-linked-data-repo.html">Linking
         * your file system to an S3 bucket</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateDataRepositoryAssociation">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateDataRepositoryAssociationOutcomeCallable CreateDataRepositoryAssociationCallable(const Model::CreateDataRepositoryAssociationRequest& request) const;

        /**
         * <p>Creates an Amazon FSx for Lustre data repository association (DRA). A data
         * repository association is a link between a directory on the file system and an
         * Amazon S3 bucket or prefix. You can have a maximum of 8 data repository
         * associations on a file system. Data repository associations are supported only
         * for file systems with the <code>Persistent_2</code> deployment type.</p> <p>Each
         * data repository association must have a unique Amazon FSx file system directory
         * and a unique S3 bucket or prefix associated with it. You can configure a data
         * repository association for automatic import only, for automatic export only, or
         * for both. To learn more about linking a data repository to your file system, see
         * <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/create-dra-linked-data-repo.html">Linking
         * your file system to an S3 bucket</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateDataRepositoryAssociation">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateDataRepositoryAssociationAsync(const Model::CreateDataRepositoryAssociationRequest& request, const CreateDataRepositoryAssociationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates an Amazon FSx for Lustre data repository task. You use data
         * repository tasks to perform bulk operations between your Amazon FSx file system
         * and its linked data repositories. An example of a data repository task is
         * exporting any data and metadata changes, including POSIX metadata, to files,
         * directories, and symbolic links (symlinks) from your FSx file system to a linked
         * data repository. A <code>CreateDataRepositoryTask</code> operation will fail if
         * a data repository is not linked to the FSx file system. To learn more about data
         * repository tasks, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/data-repository-tasks.html">Data
         * Repository Tasks</a>. To learn more about linking a data repository to your file
         * system, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/create-dra-linked-data-repo.html">Linking
         * your file system to an S3 bucket</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateDataRepositoryTask">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateDataRepositoryTaskOutcome CreateDataRepositoryTask(const Model::CreateDataRepositoryTaskRequest& request) const;

        /**
         * <p>Creates an Amazon FSx for Lustre data repository task. You use data
         * repository tasks to perform bulk operations between your Amazon FSx file system
         * and its linked data repositories. An example of a data repository task is
         * exporting any data and metadata changes, including POSIX metadata, to files,
         * directories, and symbolic links (symlinks) from your FSx file system to a linked
         * data repository. A <code>CreateDataRepositoryTask</code> operation will fail if
         * a data repository is not linked to the FSx file system. To learn more about data
         * repository tasks, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/data-repository-tasks.html">Data
         * Repository Tasks</a>. To learn more about linking a data repository to your file
         * system, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/create-dra-linked-data-repo.html">Linking
         * your file system to an S3 bucket</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateDataRepositoryTask">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateDataRepositoryTaskOutcomeCallable CreateDataRepositoryTaskCallable(const Model::CreateDataRepositoryTaskRequest& request) const;

        /**
         * <p>Creates an Amazon FSx for Lustre data repository task. You use data
         * repository tasks to perform bulk operations between your Amazon FSx file system
         * and its linked data repositories. An example of a data repository task is
         * exporting any data and metadata changes, including POSIX metadata, to files,
         * directories, and symbolic links (symlinks) from your FSx file system to a linked
         * data repository. A <code>CreateDataRepositoryTask</code> operation will fail if
         * a data repository is not linked to the FSx file system. To learn more about data
         * repository tasks, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/data-repository-tasks.html">Data
         * Repository Tasks</a>. To learn more about linking a data repository to your file
         * system, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/LustreGuide/create-dra-linked-data-repo.html">Linking
         * your file system to an S3 bucket</a>.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateDataRepositoryTask">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateDataRepositoryTaskAsync(const Model::CreateDataRepositoryTaskRequest& request, const CreateDataRepositoryTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates a new, empty Amazon FSx file system. You can create the following
         * supported Amazon FSx file systems using the <code>CreateFileSystem</code> API
         * operation:</p> <ul> <li> <p>Amazon FSx for Lustre</p> </li> <li> <p>Amazon FSx
         * for NetApp ONTAP</p> </li> <li> <p>Amazon FSx for OpenZFS</p> </li> <li>
         * <p>Amazon FSx for Windows File Server</p> </li> </ul> <p>This operation requires
         * a client request token in the request that Amazon FSx uses to ensure idempotent
         * creation. This means that calling the operation multiple times with the same
         * client request token has no effect. By using the idempotent operation, you can
         * retry a <code>CreateFileSystem</code> operation without the risk of creating an
         * extra file system. This approach can be useful when an initial call fails in a
         * way that makes it unclear whether a file system was created. Examples are if a
         * transport level timeout occurred, or your connection was reset. If you use the
         * same client request token and the initial call created a file system, the client
         * receives success as long as the parameters are the same.</p> <p>If a file system
         * with the specified client request token exists and the parameters match,
         * <code>CreateFileSystem</code> returns the description of the existing file
         * system. If a file system with the specified client request token exists and the
         * parameters don't match, this call returns
         * <code>IncompatibleParameterError</code>. If a file system with the specified
         * client request token doesn't exist, <code>CreateFileSystem</code> does the
         * following: </p> <ul> <li> <p>Creates a new, empty Amazon FSx file system with an
         * assigned ID, and an initial lifecycle state of <code>CREATING</code>.</p> </li>
         * <li> <p>Returns the description of the file system.</p> </li> </ul> <p>This
         * operation requires a client request token in the request that Amazon FSx uses to
         * ensure idempotent creation. This means that calling the operation multiple times
         * with the same client request token has no effect. By using the idempotent
         * operation, you can retry a <code>CreateFileSystem</code> operation without the
         * risk of creating an extra file system. This approach can be useful when an
         * initial call fails in a way that makes it unclear whether a file system was
         * created. Examples are if a transport-level timeout occurred, or your connection
         * was reset. If you use the same client request token and the initial call created
         * a file system, the client receives a success message as long as the parameters
         * are the same.</p>  <p>The <code>CreateFileSystem</code> call returns while
         * the file system's lifecycle state is still <code>CREATING</code>. You can check
         * the file-system creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeFileSystems.html">DescribeFileSystems</a>
         * operation, which returns the file system state along with other information.</p>
         * <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateFileSystem">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateFileSystemOutcome CreateFileSystem(const Model::CreateFileSystemRequest& request) const;

        /**
         * <p>Creates a new, empty Amazon FSx file system. You can create the following
         * supported Amazon FSx file systems using the <code>CreateFileSystem</code> API
         * operation:</p> <ul> <li> <p>Amazon FSx for Lustre</p> </li> <li> <p>Amazon FSx
         * for NetApp ONTAP</p> </li> <li> <p>Amazon FSx for OpenZFS</p> </li> <li>
         * <p>Amazon FSx for Windows File Server</p> </li> </ul> <p>This operation requires
         * a client request token in the request that Amazon FSx uses to ensure idempotent
         * creation. This means that calling the operation multiple times with the same
         * client request token has no effect. By using the idempotent operation, you can
         * retry a <code>CreateFileSystem</code> operation without the risk of creating an
         * extra file system. This approach can be useful when an initial call fails in a
         * way that makes it unclear whether a file system was created. Examples are if a
         * transport level timeout occurred, or your connection was reset. If you use the
         * same client request token and the initial call created a file system, the client
         * receives success as long as the parameters are the same.</p> <p>If a file system
         * with the specified client request token exists and the parameters match,
         * <code>CreateFileSystem</code> returns the description of the existing file
         * system. If a file system with the specified client request token exists and the
         * parameters don't match, this call returns
         * <code>IncompatibleParameterError</code>. If a file system with the specified
         * client request token doesn't exist, <code>CreateFileSystem</code> does the
         * following: </p> <ul> <li> <p>Creates a new, empty Amazon FSx file system with an
         * assigned ID, and an initial lifecycle state of <code>CREATING</code>.</p> </li>
         * <li> <p>Returns the description of the file system.</p> </li> </ul> <p>This
         * operation requires a client request token in the request that Amazon FSx uses to
         * ensure idempotent creation. This means that calling the operation multiple times
         * with the same client request token has no effect. By using the idempotent
         * operation, you can retry a <code>CreateFileSystem</code> operation without the
         * risk of creating an extra file system. This approach can be useful when an
         * initial call fails in a way that makes it unclear whether a file system was
         * created. Examples are if a transport-level timeout occurred, or your connection
         * was reset. If you use the same client request token and the initial call created
         * a file system, the client receives a success message as long as the parameters
         * are the same.</p>  <p>The <code>CreateFileSystem</code> call returns while
         * the file system's lifecycle state is still <code>CREATING</code>. You can check
         * the file-system creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeFileSystems.html">DescribeFileSystems</a>
         * operation, which returns the file system state along with other information.</p>
         * <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateFileSystem">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateFileSystemOutcomeCallable CreateFileSystemCallable(const Model::CreateFileSystemRequest& request) const;

        /**
         * <p>Creates a new, empty Amazon FSx file system. You can create the following
         * supported Amazon FSx file systems using the <code>CreateFileSystem</code> API
         * operation:</p> <ul> <li> <p>Amazon FSx for Lustre</p> </li> <li> <p>Amazon FSx
         * for NetApp ONTAP</p> </li> <li> <p>Amazon FSx for OpenZFS</p> </li> <li>
         * <p>Amazon FSx for Windows File Server</p> </li> </ul> <p>This operation requires
         * a client request token in the request that Amazon FSx uses to ensure idempotent
         * creation. This means that calling the operation multiple times with the same
         * client request token has no effect. By using the idempotent operation, you can
         * retry a <code>CreateFileSystem</code> operation without the risk of creating an
         * extra file system. This approach can be useful when an initial call fails in a
         * way that makes it unclear whether a file system was created. Examples are if a
         * transport level timeout occurred, or your connection was reset. If you use the
         * same client request token and the initial call created a file system, the client
         * receives success as long as the parameters are the same.</p> <p>If a file system
         * with the specified client request token exists and the parameters match,
         * <code>CreateFileSystem</code> returns the description of the existing file
         * system. If a file system with the specified client request token exists and the
         * parameters don't match, this call returns
         * <code>IncompatibleParameterError</code>. If a file system with the specified
         * client request token doesn't exist, <code>CreateFileSystem</code> does the
         * following: </p> <ul> <li> <p>Creates a new, empty Amazon FSx file system with an
         * assigned ID, and an initial lifecycle state of <code>CREATING</code>.</p> </li>
         * <li> <p>Returns the description of the file system.</p> </li> </ul> <p>This
         * operation requires a client request token in the request that Amazon FSx uses to
         * ensure idempotent creation. This means that calling the operation multiple times
         * with the same client request token has no effect. By using the idempotent
         * operation, you can retry a <code>CreateFileSystem</code> operation without the
         * risk of creating an extra file system. This approach can be useful when an
         * initial call fails in a way that makes it unclear whether a file system was
         * created. Examples are if a transport-level timeout occurred, or your connection
         * was reset. If you use the same client request token and the initial call created
         * a file system, the client receives a success message as long as the parameters
         * are the same.</p>  <p>The <code>CreateFileSystem</code> call returns while
         * the file system's lifecycle state is still <code>CREATING</code>. You can check
         * the file-system creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeFileSystems.html">DescribeFileSystems</a>
         * operation, which returns the file system state along with other information.</p>
         * <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateFileSystem">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateFileSystemAsync(const Model::CreateFileSystemRequest& request, const CreateFileSystemResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates a new Amazon FSx for Lustre, Amazon FSx for Windows File Server, or
         * Amazon FSx for OpenZFS file system from an existing Amazon FSx backup.</p> <p>If
         * a file system with the specified client request token exists and the parameters
         * match, this operation returns the description of the file system. If a file
         * system with the specified client request token exists but the parameters don't
         * match, this call returns <code>IncompatibleParameterError</code>. If a file
         * system with the specified client request token doesn't exist, this operation
         * does the following:</p> <ul> <li> <p>Creates a new Amazon FSx file system from
         * backup with an assigned ID, and an initial lifecycle state of
         * <code>CREATING</code>.</p> </li> <li> <p>Returns the description of the file
         * system.</p> </li> </ul> <p>Parameters like the Active Directory, default share
         * name, automatic backup, and backup settings default to the parameters of the
         * file system that was backed up, unless overridden. You can explicitly supply
         * other settings.</p> <p>By using the idempotent operation, you can retry a
         * <code>CreateFileSystemFromBackup</code> call without the risk of creating an
         * extra file system. This approach can be useful when an initial call fails in a
         * way that makes it unclear whether a file system was created. Examples are if a
         * transport level timeout occurred, or your connection was reset. If you use the
         * same client request token and the initial call created a file system, the client
         * receives a success message as long as the parameters are the same.</p> 
         * <p>The <code>CreateFileSystemFromBackup</code> call returns while the file
         * system's lifecycle state is still <code>CREATING</code>. You can check the
         * file-system creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeFileSystems.html">
         * DescribeFileSystems</a> operation, which returns the file system state along
         * with other information.</p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateFileSystemFromBackup">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateFileSystemFromBackupOutcome CreateFileSystemFromBackup(const Model::CreateFileSystemFromBackupRequest& request) const;

        /**
         * <p>Creates a new Amazon FSx for Lustre, Amazon FSx for Windows File Server, or
         * Amazon FSx for OpenZFS file system from an existing Amazon FSx backup.</p> <p>If
         * a file system with the specified client request token exists and the parameters
         * match, this operation returns the description of the file system. If a file
         * system with the specified client request token exists but the parameters don't
         * match, this call returns <code>IncompatibleParameterError</code>. If a file
         * system with the specified client request token doesn't exist, this operation
         * does the following:</p> <ul> <li> <p>Creates a new Amazon FSx file system from
         * backup with an assigned ID, and an initial lifecycle state of
         * <code>CREATING</code>.</p> </li> <li> <p>Returns the description of the file
         * system.</p> </li> </ul> <p>Parameters like the Active Directory, default share
         * name, automatic backup, and backup settings default to the parameters of the
         * file system that was backed up, unless overridden. You can explicitly supply
         * other settings.</p> <p>By using the idempotent operation, you can retry a
         * <code>CreateFileSystemFromBackup</code> call without the risk of creating an
         * extra file system. This approach can be useful when an initial call fails in a
         * way that makes it unclear whether a file system was created. Examples are if a
         * transport level timeout occurred, or your connection was reset. If you use the
         * same client request token and the initial call created a file system, the client
         * receives a success message as long as the parameters are the same.</p> 
         * <p>The <code>CreateFileSystemFromBackup</code> call returns while the file
         * system's lifecycle state is still <code>CREATING</code>. You can check the
         * file-system creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeFileSystems.html">
         * DescribeFileSystems</a> operation, which returns the file system state along
         * with other information.</p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateFileSystemFromBackup">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateFileSystemFromBackupOutcomeCallable CreateFileSystemFromBackupCallable(const Model::CreateFileSystemFromBackupRequest& request) const;

        /**
         * <p>Creates a new Amazon FSx for Lustre, Amazon FSx for Windows File Server, or
         * Amazon FSx for OpenZFS file system from an existing Amazon FSx backup.</p> <p>If
         * a file system with the specified client request token exists and the parameters
         * match, this operation returns the description of the file system. If a file
         * system with the specified client request token exists but the parameters don't
         * match, this call returns <code>IncompatibleParameterError</code>. If a file
         * system with the specified client request token doesn't exist, this operation
         * does the following:</p> <ul> <li> <p>Creates a new Amazon FSx file system from
         * backup with an assigned ID, and an initial lifecycle state of
         * <code>CREATING</code>.</p> </li> <li> <p>Returns the description of the file
         * system.</p> </li> </ul> <p>Parameters like the Active Directory, default share
         * name, automatic backup, and backup settings default to the parameters of the
         * file system that was backed up, unless overridden. You can explicitly supply
         * other settings.</p> <p>By using the idempotent operation, you can retry a
         * <code>CreateFileSystemFromBackup</code> call without the risk of creating an
         * extra file system. This approach can be useful when an initial call fails in a
         * way that makes it unclear whether a file system was created. Examples are if a
         * transport level timeout occurred, or your connection was reset. If you use the
         * same client request token and the initial call created a file system, the client
         * receives a success message as long as the parameters are the same.</p> 
         * <p>The <code>CreateFileSystemFromBackup</code> call returns while the file
         * system's lifecycle state is still <code>CREATING</code>. You can check the
         * file-system creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeFileSystems.html">
         * DescribeFileSystems</a> operation, which returns the file system state along
         * with other information.</p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateFileSystemFromBackup">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateFileSystemFromBackupAsync(const Model::CreateFileSystemFromBackupRequest& request, const CreateFileSystemFromBackupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates a snapshot of an existing Amazon FSx for OpenZFS volume. With
         * snapshots, you can easily undo file changes and compare file versions by
         * restoring the volume to a previous version.</p> <p>If a snapshot with the
         * specified client request token exists, and the parameters match, this operation
         * returns the description of the existing snapshot. If a snapshot with the
         * specified client request token exists, and the parameters don't match, this
         * operation returns <code>IncompatibleParameterError</code>. If a snapshot with
         * the specified client request token doesn't exist, <code>CreateSnapshot</code>
         * does the following:</p> <ul> <li> <p>Creates a new OpenZFS snapshot with an
         * assigned ID, and an initial lifecycle state of <code>CREATING</code>.</p> </li>
         * <li> <p>Returns the description of the snapshot.</p> </li> </ul> <p>By using the
         * idempotent operation, you can retry a <code>CreateSnapshot</code> operation
         * without the risk of creating an extra snapshot. This approach can be useful when
         * an initial call fails in a way that makes it unclear whether a snapshot was
         * created. If you use the same client request token and the initial call created a
         * snapshot, the operation returns a successful result because all the parameters
         * are the same.</p> <p>The <code>CreateSnapshot</code> operation returns while the
         * snapshot's lifecycle state is still <code>CREATING</code>. You can check the
         * snapshot creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeSnapshots.html">DescribeSnapshots</a>
         * operation, which returns the snapshot state along with other
         * information.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateSnapshot">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateSnapshotOutcome CreateSnapshot(const Model::CreateSnapshotRequest& request) const;

        /**
         * <p>Creates a snapshot of an existing Amazon FSx for OpenZFS volume. With
         * snapshots, you can easily undo file changes and compare file versions by
         * restoring the volume to a previous version.</p> <p>If a snapshot with the
         * specified client request token exists, and the parameters match, this operation
         * returns the description of the existing snapshot. If a snapshot with the
         * specified client request token exists, and the parameters don't match, this
         * operation returns <code>IncompatibleParameterError</code>. If a snapshot with
         * the specified client request token doesn't exist, <code>CreateSnapshot</code>
         * does the following:</p> <ul> <li> <p>Creates a new OpenZFS snapshot with an
         * assigned ID, and an initial lifecycle state of <code>CREATING</code>.</p> </li>
         * <li> <p>Returns the description of the snapshot.</p> </li> </ul> <p>By using the
         * idempotent operation, you can retry a <code>CreateSnapshot</code> operation
         * without the risk of creating an extra snapshot. This approach can be useful when
         * an initial call fails in a way that makes it unclear whether a snapshot was
         * created. If you use the same client request token and the initial call created a
         * snapshot, the operation returns a successful result because all the parameters
         * are the same.</p> <p>The <code>CreateSnapshot</code> operation returns while the
         * snapshot's lifecycle state is still <code>CREATING</code>. You can check the
         * snapshot creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeSnapshots.html">DescribeSnapshots</a>
         * operation, which returns the snapshot state along with other
         * information.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateSnapshot">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateSnapshotOutcomeCallable CreateSnapshotCallable(const Model::CreateSnapshotRequest& request) const;

        /**
         * <p>Creates a snapshot of an existing Amazon FSx for OpenZFS volume. With
         * snapshots, you can easily undo file changes and compare file versions by
         * restoring the volume to a previous version.</p> <p>If a snapshot with the
         * specified client request token exists, and the parameters match, this operation
         * returns the description of the existing snapshot. If a snapshot with the
         * specified client request token exists, and the parameters don't match, this
         * operation returns <code>IncompatibleParameterError</code>. If a snapshot with
         * the specified client request token doesn't exist, <code>CreateSnapshot</code>
         * does the following:</p> <ul> <li> <p>Creates a new OpenZFS snapshot with an
         * assigned ID, and an initial lifecycle state of <code>CREATING</code>.</p> </li>
         * <li> <p>Returns the description of the snapshot.</p> </li> </ul> <p>By using the
         * idempotent operation, you can retry a <code>CreateSnapshot</code> operation
         * without the risk of creating an extra snapshot. This approach can be useful when
         * an initial call fails in a way that makes it unclear whether a snapshot was
         * created. If you use the same client request token and the initial call created a
         * snapshot, the operation returns a successful result because all the parameters
         * are the same.</p> <p>The <code>CreateSnapshot</code> operation returns while the
         * snapshot's lifecycle state is still <code>CREATING</code>. You can check the
         * snapshot creation status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeSnapshots.html">DescribeSnapshots</a>
         * operation, which returns the snapshot state along with other
         * information.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateSnapshot">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateSnapshotAsync(const Model::CreateSnapshotRequest& request, const CreateSnapshotResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates a storage virtual machine (SVM) for an Amazon FSx for ONTAP file
         * system.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateStorageVirtualMachine">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateStorageVirtualMachineOutcome CreateStorageVirtualMachine(const Model::CreateStorageVirtualMachineRequest& request) const;

        /**
         * <p>Creates a storage virtual machine (SVM) for an Amazon FSx for ONTAP file
         * system.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateStorageVirtualMachine">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateStorageVirtualMachineOutcomeCallable CreateStorageVirtualMachineCallable(const Model::CreateStorageVirtualMachineRequest& request) const;

        /**
         * <p>Creates a storage virtual machine (SVM) for an Amazon FSx for ONTAP file
         * system.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateStorageVirtualMachine">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateStorageVirtualMachineAsync(const Model::CreateStorageVirtualMachineRequest& request, const CreateStorageVirtualMachineResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates an FSx for ONTAP or Amazon FSx for OpenZFS storage
         * volume.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateVolume">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateVolumeOutcome CreateVolume(const Model::CreateVolumeRequest& request) const;

        /**
         * <p>Creates an FSx for ONTAP or Amazon FSx for OpenZFS storage
         * volume.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateVolume">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateVolumeOutcomeCallable CreateVolumeCallable(const Model::CreateVolumeRequest& request) const;

        /**
         * <p>Creates an FSx for ONTAP or Amazon FSx for OpenZFS storage
         * volume.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateVolume">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateVolumeAsync(const Model::CreateVolumeRequest& request, const CreateVolumeResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Creates a new Amazon FSx for NetApp ONTAP volume from an existing Amazon FSx
         * volume backup.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateVolumeFromBackup">AWS
         * API Reference</a></p>
         */
        virtual Model::CreateVolumeFromBackupOutcome CreateVolumeFromBackup(const Model::CreateVolumeFromBackupRequest& request) const;

        /**
         * <p>Creates a new Amazon FSx for NetApp ONTAP volume from an existing Amazon FSx
         * volume backup.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateVolumeFromBackup">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::CreateVolumeFromBackupOutcomeCallable CreateVolumeFromBackupCallable(const Model::CreateVolumeFromBackupRequest& request) const;

        /**
         * <p>Creates a new Amazon FSx for NetApp ONTAP volume from an existing Amazon FSx
         * volume backup.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/CreateVolumeFromBackup">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void CreateVolumeFromBackupAsync(const Model::CreateVolumeFromBackupRequest& request, const CreateVolumeFromBackupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Deletes an Amazon FSx backup. After deletion, the backup no longer exists,
         * and its data is gone.</p> <p>The <code>DeleteBackup</code> call returns
         * instantly. The backup won't show up in later <code>DescribeBackups</code>
         * calls.</p>  <p>The data in a deleted backup is also deleted and can't
         * be recovered by any means.</p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteBackup">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteBackupOutcome DeleteBackup(const Model::DeleteBackupRequest& request) const;

        /**
         * <p>Deletes an Amazon FSx backup. After deletion, the backup no longer exists,
         * and its data is gone.</p> <p>The <code>DeleteBackup</code> call returns
         * instantly. The backup won't show up in later <code>DescribeBackups</code>
         * calls.</p>  <p>The data in a deleted backup is also deleted and can't
         * be recovered by any means.</p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteBackup">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteBackupOutcomeCallable DeleteBackupCallable(const Model::DeleteBackupRequest& request) const;

        /**
         * <p>Deletes an Amazon FSx backup. After deletion, the backup no longer exists,
         * and its data is gone.</p> <p>The <code>DeleteBackup</code> call returns
         * instantly. The backup won't show up in later <code>DescribeBackups</code>
         * calls.</p>  <p>The data in a deleted backup is also deleted and can't
         * be recovered by any means.</p> <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteBackup">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteBackupAsync(const Model::DeleteBackupRequest& request, const DeleteBackupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Deletes a data repository association on an Amazon FSx for Lustre file
         * system. Deleting the data repository association unlinks the file system from
         * the Amazon S3 bucket. When deleting a data repository association, you have the
         * option of deleting the data in the file system that corresponds to the data
         * repository association. Data repository associations are supported only for file
         * systems with the <code>Persistent_2</code> deployment type.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteDataRepositoryAssociation">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteDataRepositoryAssociationOutcome DeleteDataRepositoryAssociation(const Model::DeleteDataRepositoryAssociationRequest& request) const;

        /**
         * <p>Deletes a data repository association on an Amazon FSx for Lustre file
         * system. Deleting the data repository association unlinks the file system from
         * the Amazon S3 bucket. When deleting a data repository association, you have the
         * option of deleting the data in the file system that corresponds to the data
         * repository association. Data repository associations are supported only for file
         * systems with the <code>Persistent_2</code> deployment type.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteDataRepositoryAssociation">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteDataRepositoryAssociationOutcomeCallable DeleteDataRepositoryAssociationCallable(const Model::DeleteDataRepositoryAssociationRequest& request) const;

        /**
         * <p>Deletes a data repository association on an Amazon FSx for Lustre file
         * system. Deleting the data repository association unlinks the file system from
         * the Amazon S3 bucket. When deleting a data repository association, you have the
         * option of deleting the data in the file system that corresponds to the data
         * repository association. Data repository associations are supported only for file
         * systems with the <code>Persistent_2</code> deployment type.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteDataRepositoryAssociation">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteDataRepositoryAssociationAsync(const Model::DeleteDataRepositoryAssociationRequest& request, const DeleteDataRepositoryAssociationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Deletes a file system. After deletion, the file system no longer exists, and
         * its data is gone. Any existing automatic backups and snapshots are also
         * deleted.</p> <p>To delete an Amazon FSx for NetApp ONTAP file system, first
         * delete all the volumes and storage virtual machines (SVMs) on the file system.
         * Then provide a <code>FileSystemId</code> value to the
         * <code>DeleFileSystem</code> operation.</p> <p>By default, when you delete an
         * Amazon FSx for Windows File Server file system, a final backup is created upon
         * deletion. This final backup isn't subject to the file system's retention policy,
         * and must be manually deleted.</p> <p>The <code>DeleteFileSystem</code> operation
         * returns while the file system has the <code>DELETING</code> status. You can
         * check the file system deletion status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeFileSystems.html">DescribeFileSystems</a>
         * operation, which returns a list of file systems in your account. If you pass the
         * file system ID for a deleted file system, the <code>DescribeFileSystems</code>
         * operation returns a <code>FileSystemNotFound</code> error.</p>  <p>If a
         * data repository task is in a <code>PENDING</code> or <code>EXECUTING</code>
         * state, deleting an Amazon FSx for Lustre file system will fail with an HTTP
         * status code 400 (Bad Request).</p>   <p>The data in a deleted
         * file system is also deleted and can't be recovered by any means.</p>
         * <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteFileSystem">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteFileSystemOutcome DeleteFileSystem(const Model::DeleteFileSystemRequest& request) const;

        /**
         * <p>Deletes a file system. After deletion, the file system no longer exists, and
         * its data is gone. Any existing automatic backups and snapshots are also
         * deleted.</p> <p>To delete an Amazon FSx for NetApp ONTAP file system, first
         * delete all the volumes and storage virtual machines (SVMs) on the file system.
         * Then provide a <code>FileSystemId</code> value to the
         * <code>DeleFileSystem</code> operation.</p> <p>By default, when you delete an
         * Amazon FSx for Windows File Server file system, a final backup is created upon
         * deletion. This final backup isn't subject to the file system's retention policy,
         * and must be manually deleted.</p> <p>The <code>DeleteFileSystem</code> operation
         * returns while the file system has the <code>DELETING</code> status. You can
         * check the file system deletion status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeFileSystems.html">DescribeFileSystems</a>
         * operation, which returns a list of file systems in your account. If you pass the
         * file system ID for a deleted file system, the <code>DescribeFileSystems</code>
         * operation returns a <code>FileSystemNotFound</code> error.</p>  <p>If a
         * data repository task is in a <code>PENDING</code> or <code>EXECUTING</code>
         * state, deleting an Amazon FSx for Lustre file system will fail with an HTTP
         * status code 400 (Bad Request).</p>   <p>The data in a deleted
         * file system is also deleted and can't be recovered by any means.</p>
         * <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteFileSystem">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteFileSystemOutcomeCallable DeleteFileSystemCallable(const Model::DeleteFileSystemRequest& request) const;

        /**
         * <p>Deletes a file system. After deletion, the file system no longer exists, and
         * its data is gone. Any existing automatic backups and snapshots are also
         * deleted.</p> <p>To delete an Amazon FSx for NetApp ONTAP file system, first
         * delete all the volumes and storage virtual machines (SVMs) on the file system.
         * Then provide a <code>FileSystemId</code> value to the
         * <code>DeleFileSystem</code> operation.</p> <p>By default, when you delete an
         * Amazon FSx for Windows File Server file system, a final backup is created upon
         * deletion. This final backup isn't subject to the file system's retention policy,
         * and must be manually deleted.</p> <p>The <code>DeleteFileSystem</code> operation
         * returns while the file system has the <code>DELETING</code> status. You can
         * check the file system deletion status by calling the <a
         * href="https://docs.aws.amazon.com/fsx/latest/APIReference/API_DescribeFileSystems.html">DescribeFileSystems</a>
         * operation, which returns a list of file systems in your account. If you pass the
         * file system ID for a deleted file system, the <code>DescribeFileSystems</code>
         * operation returns a <code>FileSystemNotFound</code> error.</p>  <p>If a
         * data repository task is in a <code>PENDING</code> or <code>EXECUTING</code>
         * state, deleting an Amazon FSx for Lustre file system will fail with an HTTP
         * status code 400 (Bad Request).</p>   <p>The data in a deleted
         * file system is also deleted and can't be recovered by any means.</p>
         * <p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteFileSystem">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteFileSystemAsync(const Model::DeleteFileSystemRequest& request, const DeleteFileSystemResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Deletes an Amazon FSx for OpenZFS snapshot. After deletion, the snapshot no
         * longer exists, and its data is gone. Deleting a snapshot doesn't affect
         * snapshots stored in a file system backup. </p> <p>The
         * <code>DeleteSnapshot</code> operation returns instantly. The snapshot appears
         * with the lifecycle status of <code>DELETING</code> until the deletion is
         * complete.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteSnapshot">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteSnapshotOutcome DeleteSnapshot(const Model::DeleteSnapshotRequest& request) const;

        /**
         * <p>Deletes an Amazon FSx for OpenZFS snapshot. After deletion, the snapshot no
         * longer exists, and its data is gone. Deleting a snapshot doesn't affect
         * snapshots stored in a file system backup. </p> <p>The
         * <code>DeleteSnapshot</code> operation returns instantly. The snapshot appears
         * with the lifecycle status of <code>DELETING</code> until the deletion is
         * complete.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteSnapshot">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteSnapshotOutcomeCallable DeleteSnapshotCallable(const Model::DeleteSnapshotRequest& request) const;

        /**
         * <p>Deletes an Amazon FSx for OpenZFS snapshot. After deletion, the snapshot no
         * longer exists, and its data is gone. Deleting a snapshot doesn't affect
         * snapshots stored in a file system backup. </p> <p>The
         * <code>DeleteSnapshot</code> operation returns instantly. The snapshot appears
         * with the lifecycle status of <code>DELETING</code> until the deletion is
         * complete.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteSnapshot">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteSnapshotAsync(const Model::DeleteSnapshotRequest& request, const DeleteSnapshotResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Deletes an existing Amazon FSx for ONTAP storage virtual machine (SVM). Prior
         * to deleting an SVM, you must delete all non-root volumes in the SVM, otherwise
         * the operation will fail.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteStorageVirtualMachine">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteStorageVirtualMachineOutcome DeleteStorageVirtualMachine(const Model::DeleteStorageVirtualMachineRequest& request) const;

        /**
         * <p>Deletes an existing Amazon FSx for ONTAP storage virtual machine (SVM). Prior
         * to deleting an SVM, you must delete all non-root volumes in the SVM, otherwise
         * the operation will fail.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteStorageVirtualMachine">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteStorageVirtualMachineOutcomeCallable DeleteStorageVirtualMachineCallable(const Model::DeleteStorageVirtualMachineRequest& request) const;

        /**
         * <p>Deletes an existing Amazon FSx for ONTAP storage virtual machine (SVM). Prior
         * to deleting an SVM, you must delete all non-root volumes in the SVM, otherwise
         * the operation will fail.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteStorageVirtualMachine">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteStorageVirtualMachineAsync(const Model::DeleteStorageVirtualMachineRequest& request, const DeleteStorageVirtualMachineResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Deletes an Amazon FSx for NetApp ONTAP or Amazon FSx for OpenZFS
         * volume.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteVolume">AWS
         * API Reference</a></p>
         */
        virtual Model::DeleteVolumeOutcome DeleteVolume(const Model::DeleteVolumeRequest& request) const;

        /**
         * <p>Deletes an Amazon FSx for NetApp ONTAP or Amazon FSx for OpenZFS
         * volume.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteVolume">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DeleteVolumeOutcomeCallable DeleteVolumeCallable(const Model::DeleteVolumeRequest& request) const;

        /**
         * <p>Deletes an Amazon FSx for NetApp ONTAP or Amazon FSx for OpenZFS
         * volume.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DeleteVolume">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DeleteVolumeAsync(const Model::DeleteVolumeRequest& request, const DeleteVolumeResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Returns the description of a specific Amazon FSx backup, if a
         * <code>BackupIds</code> value is provided for that backup. Otherwise, it returns
         * all backups owned by your Amazon Web Services account in the Amazon Web Services
         * Region of the endpoint that you're calling.</p> <p>When retrieving all backups,
         * you can optionally specify the <code>MaxResults</code> parameter to limit the
         * number of backups in a response. If more backups remain, Amazon FSx returns a
         * <code>NextToken</code> value in the response. In this case, send a later request
         * with the <code>NextToken</code> request parameter set to the value of the
         * <code>NextToken</code> value from the last response.</p> <p>This operation is
         * used in an iterative process to retrieve a list of your backups.
         * <code>DescribeBackups</code> is called first without a <code>NextToken</code>
         * value. Then the operation continues to be called with the <code>NextToken</code>
         * parameter set to the value of the last <code>NextToken</code> value until a
         * response has no <code>NextToken</code> value.</p> <p>When using this operation,
         * keep the following in mind:</p> <ul> <li> <p>The operation might return fewer
         * than the <code>MaxResults</code> value of backup descriptions while still
         * including a <code>NextToken</code> value.</p> </li> <li> <p>The order of the
         * backups returned in the response of one <code>DescribeBackups</code> call and
         * the order of the backups returned across the responses of a multi-call iteration
         * is unspecified.</p> </li> </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeBackups">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeBackupsOutcome DescribeBackups(const Model::DescribeBackupsRequest& request) const;

        /**
         * <p>Returns the description of a specific Amazon FSx backup, if a
         * <code>BackupIds</code> value is provided for that backup. Otherwise, it returns
         * all backups owned by your Amazon Web Services account in the Amazon Web Services
         * Region of the endpoint that you're calling.</p> <p>When retrieving all backups,
         * you can optionally specify the <code>MaxResults</code> parameter to limit the
         * number of backups in a response. If more backups remain, Amazon FSx returns a
         * <code>NextToken</code> value in the response. In this case, send a later request
         * with the <code>NextToken</code> request parameter set to the value of the
         * <code>NextToken</code> value from the last response.</p> <p>This operation is
         * used in an iterative process to retrieve a list of your backups.
         * <code>DescribeBackups</code> is called first without a <code>NextToken</code>
         * value. Then the operation continues to be called with the <code>NextToken</code>
         * parameter set to the value of the last <code>NextToken</code> value until a
         * response has no <code>NextToken</code> value.</p> <p>When using this operation,
         * keep the following in mind:</p> <ul> <li> <p>The operation might return fewer
         * than the <code>MaxResults</code> value of backup descriptions while still
         * including a <code>NextToken</code> value.</p> </li> <li> <p>The order of the
         * backups returned in the response of one <code>DescribeBackups</code> call and
         * the order of the backups returned across the responses of a multi-call iteration
         * is unspecified.</p> </li> </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeBackups">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeBackupsOutcomeCallable DescribeBackupsCallable(const Model::DescribeBackupsRequest& request) const;

        /**
         * <p>Returns the description of a specific Amazon FSx backup, if a
         * <code>BackupIds</code> value is provided for that backup. Otherwise, it returns
         * all backups owned by your Amazon Web Services account in the Amazon Web Services
         * Region of the endpoint that you're calling.</p> <p>When retrieving all backups,
         * you can optionally specify the <code>MaxResults</code> parameter to limit the
         * number of backups in a response. If more backups remain, Amazon FSx returns a
         * <code>NextToken</code> value in the response. In this case, send a later request
         * with the <code>NextToken</code> request parameter set to the value of the
         * <code>NextToken</code> value from the last response.</p> <p>This operation is
         * used in an iterative process to retrieve a list of your backups.
         * <code>DescribeBackups</code> is called first without a <code>NextToken</code>
         * value. Then the operation continues to be called with the <code>NextToken</code>
         * parameter set to the value of the last <code>NextToken</code> value until a
         * response has no <code>NextToken</code> value.</p> <p>When using this operation,
         * keep the following in mind:</p> <ul> <li> <p>The operation might return fewer
         * than the <code>MaxResults</code> value of backup descriptions while still
         * including a <code>NextToken</code> value.</p> </li> <li> <p>The order of the
         * backups returned in the response of one <code>DescribeBackups</code> call and
         * the order of the backups returned across the responses of a multi-call iteration
         * is unspecified.</p> </li> </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeBackups">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeBackupsAsync(const Model::DescribeBackupsRequest& request, const DescribeBackupsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Returns the description of specific Amazon FSx for Lustre data repository
         * associations, if one or more <code>AssociationIds</code> values are provided in
         * the request, or if filters are used in the request. Data repository associations
         * are supported only for file systems with the <code>Persistent_2</code>
         * deployment type.</p> <p>You can use filters to narrow the response to include
         * just data repository associations for specific file systems (use the
         * <code>file-system-id</code> filter with the ID of the file system) or data
         * repository associations for a specific repository type (use the
         * <code>data-repository-type</code> filter with a value of <code>S3</code>). If
         * you don't use filters, the response returns all data repository associations
         * owned by your Amazon Web Services account in the Amazon Web Services Region of
         * the endpoint that you're calling.</p> <p>When retrieving all data repository
         * associations, you can paginate the response by using the optional
         * <code>MaxResults</code> parameter to limit the number of data repository
         * associations returned in a response. If more data repository associations
         * remain, Amazon FSx returns a <code>NextToken</code> value in the response. In
         * this case, send a later request with the <code>NextToken</code> request
         * parameter set to the value of <code>NextToken</code> from the last
         * response.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeDataRepositoryAssociations">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeDataRepositoryAssociationsOutcome DescribeDataRepositoryAssociations(const Model::DescribeDataRepositoryAssociationsRequest& request) const;

        /**
         * <p>Returns the description of specific Amazon FSx for Lustre data repository
         * associations, if one or more <code>AssociationIds</code> values are provided in
         * the request, or if filters are used in the request. Data repository associations
         * are supported only for file systems with the <code>Persistent_2</code>
         * deployment type.</p> <p>You can use filters to narrow the response to include
         * just data repository associations for specific file systems (use the
         * <code>file-system-id</code> filter with the ID of the file system) or data
         * repository associations for a specific repository type (use the
         * <code>data-repository-type</code> filter with a value of <code>S3</code>). If
         * you don't use filters, the response returns all data repository associations
         * owned by your Amazon Web Services account in the Amazon Web Services Region of
         * the endpoint that you're calling.</p> <p>When retrieving all data repository
         * associations, you can paginate the response by using the optional
         * <code>MaxResults</code> parameter to limit the number of data repository
         * associations returned in a response. If more data repository associations
         * remain, Amazon FSx returns a <code>NextToken</code> value in the response. In
         * this case, send a later request with the <code>NextToken</code> request
         * parameter set to the value of <code>NextToken</code> from the last
         * response.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeDataRepositoryAssociations">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeDataRepositoryAssociationsOutcomeCallable DescribeDataRepositoryAssociationsCallable(const Model::DescribeDataRepositoryAssociationsRequest& request) const;

        /**
         * <p>Returns the description of specific Amazon FSx for Lustre data repository
         * associations, if one or more <code>AssociationIds</code> values are provided in
         * the request, or if filters are used in the request. Data repository associations
         * are supported only for file systems with the <code>Persistent_2</code>
         * deployment type.</p> <p>You can use filters to narrow the response to include
         * just data repository associations for specific file systems (use the
         * <code>file-system-id</code> filter with the ID of the file system) or data
         * repository associations for a specific repository type (use the
         * <code>data-repository-type</code> filter with a value of <code>S3</code>). If
         * you don't use filters, the response returns all data repository associations
         * owned by your Amazon Web Services account in the Amazon Web Services Region of
         * the endpoint that you're calling.</p> <p>When retrieving all data repository
         * associations, you can paginate the response by using the optional
         * <code>MaxResults</code> parameter to limit the number of data repository
         * associations returned in a response. If more data repository associations
         * remain, Amazon FSx returns a <code>NextToken</code> value in the response. In
         * this case, send a later request with the <code>NextToken</code> request
         * parameter set to the value of <code>NextToken</code> from the last
         * response.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeDataRepositoryAssociations">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeDataRepositoryAssociationsAsync(const Model::DescribeDataRepositoryAssociationsRequest& request, const DescribeDataRepositoryAssociationsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Returns the description of specific Amazon FSx for Lustre data repository
         * tasks, if one or more <code>TaskIds</code> values are provided in the request,
         * or if filters are used in the request. You can use filters to narrow the
         * response to include just tasks for specific file systems, or tasks in a specific
         * lifecycle state. Otherwise, it returns all data repository tasks owned by your
         * Amazon Web Services account in the Amazon Web Services Region of the endpoint
         * that you're calling.</p> <p>When retrieving all tasks, you can paginate the
         * response by using the optional <code>MaxResults</code> parameter to limit the
         * number of tasks returned in a response. If more tasks remain, Amazon FSx returns
         * a <code>NextToken</code> value in the response. In this case, send a later
         * request with the <code>NextToken</code> request parameter set to the value of
         * <code>NextToken</code> from the last response.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeDataRepositoryTasks">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeDataRepositoryTasksOutcome DescribeDataRepositoryTasks(const Model::DescribeDataRepositoryTasksRequest& request) const;

        /**
         * <p>Returns the description of specific Amazon FSx for Lustre data repository
         * tasks, if one or more <code>TaskIds</code> values are provided in the request,
         * or if filters are used in the request. You can use filters to narrow the
         * response to include just tasks for specific file systems, or tasks in a specific
         * lifecycle state. Otherwise, it returns all data repository tasks owned by your
         * Amazon Web Services account in the Amazon Web Services Region of the endpoint
         * that you're calling.</p> <p>When retrieving all tasks, you can paginate the
         * response by using the optional <code>MaxResults</code> parameter to limit the
         * number of tasks returned in a response. If more tasks remain, Amazon FSx returns
         * a <code>NextToken</code> value in the response. In this case, send a later
         * request with the <code>NextToken</code> request parameter set to the value of
         * <code>NextToken</code> from the last response.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeDataRepositoryTasks">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeDataRepositoryTasksOutcomeCallable DescribeDataRepositoryTasksCallable(const Model::DescribeDataRepositoryTasksRequest& request) const;

        /**
         * <p>Returns the description of specific Amazon FSx for Lustre data repository
         * tasks, if one or more <code>TaskIds</code> values are provided in the request,
         * or if filters are used in the request. You can use filters to narrow the
         * response to include just tasks for specific file systems, or tasks in a specific
         * lifecycle state. Otherwise, it returns all data repository tasks owned by your
         * Amazon Web Services account in the Amazon Web Services Region of the endpoint
         * that you're calling.</p> <p>When retrieving all tasks, you can paginate the
         * response by using the optional <code>MaxResults</code> parameter to limit the
         * number of tasks returned in a response. If more tasks remain, Amazon FSx returns
         * a <code>NextToken</code> value in the response. In this case, send a later
         * request with the <code>NextToken</code> request parameter set to the value of
         * <code>NextToken</code> from the last response.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeDataRepositoryTasks">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeDataRepositoryTasksAsync(const Model::DescribeDataRepositoryTasksRequest& request, const DescribeDataRepositoryTasksResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Returns the DNS aliases that are associated with the specified Amazon FSx for
         * Windows File Server file system. A history of all DNS aliases that have been
         * associated with and disassociated from the file system is available in the list
         * of <a>AdministrativeAction</a> provided in the <a>DescribeFileSystems</a>
         * operation response.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeFileSystemAliases">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeFileSystemAliasesOutcome DescribeFileSystemAliases(const Model::DescribeFileSystemAliasesRequest& request) const;

        /**
         * <p>Returns the DNS aliases that are associated with the specified Amazon FSx for
         * Windows File Server file system. A history of all DNS aliases that have been
         * associated with and disassociated from the file system is available in the list
         * of <a>AdministrativeAction</a> provided in the <a>DescribeFileSystems</a>
         * operation response.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeFileSystemAliases">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeFileSystemAliasesOutcomeCallable DescribeFileSystemAliasesCallable(const Model::DescribeFileSystemAliasesRequest& request) const;

        /**
         * <p>Returns the DNS aliases that are associated with the specified Amazon FSx for
         * Windows File Server file system. A history of all DNS aliases that have been
         * associated with and disassociated from the file system is available in the list
         * of <a>AdministrativeAction</a> provided in the <a>DescribeFileSystems</a>
         * operation response.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeFileSystemAliases">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeFileSystemAliasesAsync(const Model::DescribeFileSystemAliasesRequest& request, const DescribeFileSystemAliasesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Returns the description of specific Amazon FSx file systems, if a
         * <code>FileSystemIds</code> value is provided for that file system. Otherwise, it
         * returns descriptions of all file systems owned by your Amazon Web Services
         * account in the Amazon Web Services Region of the endpoint that you're
         * calling.</p> <p>When retrieving all file system descriptions, you can optionally
         * specify the <code>MaxResults</code> parameter to limit the number of
         * descriptions in a response. If more file system descriptions remain, Amazon FSx
         * returns a <code>NextToken</code> value in the response. In this case, send a
         * later request with the <code>NextToken</code> request parameter set to the value
         * of <code>NextToken</code> from the last response.</p> <p>This operation is used
         * in an iterative process to retrieve a list of your file system descriptions.
         * <code>DescribeFileSystems</code> is called first without a
         * <code>NextToken</code>value. Then the operation continues to be called with the
         * <code>NextToken</code> parameter set to the value of the last
         * <code>NextToken</code> value until a response has no <code>NextToken</code>.</p>
         * <p>When using this operation, keep the following in mind:</p> <ul> <li> <p>The
         * implementation might return fewer than <code>MaxResults</code> file system
         * descriptions while still including a <code>NextToken</code> value.</p> </li>
         * <li> <p>The order of file systems returned in the response of one
         * <code>DescribeFileSystems</code> call and the order of file systems returned
         * across the responses of a multicall iteration is unspecified.</p> </li>
         * </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeFileSystems">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeFileSystemsOutcome DescribeFileSystems(const Model::DescribeFileSystemsRequest& request) const;

        /**
         * <p>Returns the description of specific Amazon FSx file systems, if a
         * <code>FileSystemIds</code> value is provided for that file system. Otherwise, it
         * returns descriptions of all file systems owned by your Amazon Web Services
         * account in the Amazon Web Services Region of the endpoint that you're
         * calling.</p> <p>When retrieving all file system descriptions, you can optionally
         * specify the <code>MaxResults</code> parameter to limit the number of
         * descriptions in a response. If more file system descriptions remain, Amazon FSx
         * returns a <code>NextToken</code> value in the response. In this case, send a
         * later request with the <code>NextToken</code> request parameter set to the value
         * of <code>NextToken</code> from the last response.</p> <p>This operation is used
         * in an iterative process to retrieve a list of your file system descriptions.
         * <code>DescribeFileSystems</code> is called first without a
         * <code>NextToken</code>value. Then the operation continues to be called with the
         * <code>NextToken</code> parameter set to the value of the last
         * <code>NextToken</code> value until a response has no <code>NextToken</code>.</p>
         * <p>When using this operation, keep the following in mind:</p> <ul> <li> <p>The
         * implementation might return fewer than <code>MaxResults</code> file system
         * descriptions while still including a <code>NextToken</code> value.</p> </li>
         * <li> <p>The order of file systems returned in the response of one
         * <code>DescribeFileSystems</code> call and the order of file systems returned
         * across the responses of a multicall iteration is unspecified.</p> </li>
         * </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeFileSystems">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeFileSystemsOutcomeCallable DescribeFileSystemsCallable(const Model::DescribeFileSystemsRequest& request) const;

        /**
         * <p>Returns the description of specific Amazon FSx file systems, if a
         * <code>FileSystemIds</code> value is provided for that file system. Otherwise, it
         * returns descriptions of all file systems owned by your Amazon Web Services
         * account in the Amazon Web Services Region of the endpoint that you're
         * calling.</p> <p>When retrieving all file system descriptions, you can optionally
         * specify the <code>MaxResults</code> parameter to limit the number of
         * descriptions in a response. If more file system descriptions remain, Amazon FSx
         * returns a <code>NextToken</code> value in the response. In this case, send a
         * later request with the <code>NextToken</code> request parameter set to the value
         * of <code>NextToken</code> from the last response.</p> <p>This operation is used
         * in an iterative process to retrieve a list of your file system descriptions.
         * <code>DescribeFileSystems</code> is called first without a
         * <code>NextToken</code>value. Then the operation continues to be called with the
         * <code>NextToken</code> parameter set to the value of the last
         * <code>NextToken</code> value until a response has no <code>NextToken</code>.</p>
         * <p>When using this operation, keep the following in mind:</p> <ul> <li> <p>The
         * implementation might return fewer than <code>MaxResults</code> file system
         * descriptions while still including a <code>NextToken</code> value.</p> </li>
         * <li> <p>The order of file systems returned in the response of one
         * <code>DescribeFileSystems</code> call and the order of file systems returned
         * across the responses of a multicall iteration is unspecified.</p> </li>
         * </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeFileSystems">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeFileSystemsAsync(const Model::DescribeFileSystemsRequest& request, const DescribeFileSystemsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Returns the description of specific Amazon FSx for OpenZFS snapshots, if a
         * <code>SnapshotIds</code> value is provided. Otherwise, this operation returns
         * all snapshots owned by your Amazon Web Services account in the Amazon Web
         * Services Region of the endpoint that you're calling.</p> <p>When retrieving all
         * snapshots, you can optionally specify the <code>MaxResults</code> parameter to
         * limit the number of snapshots in a response. If more backups remain, Amazon FSx
         * returns a <code>NextToken</code> value in the response. In this case, send a
         * later request with the <code>NextToken</code> request parameter set to the value
         * of <code>NextToken</code> from the last response. </p> <p>Use this operation in
         * an iterative process to retrieve a list of your snapshots.
         * <code>DescribeSnapshots</code> is called first without a <code>NextToken</code>
         * value. Then the operation continues to be called with the <code>NextToken</code>
         * parameter set to the value of the last <code>NextToken</code> value until a
         * response has no <code>NextToken</code> value.</p> <p>When using this operation,
         * keep the following in mind:</p> <ul> <li> <p>The operation might return fewer
         * than the <code>MaxResults</code> value of snapshot descriptions while still
         * including a <code>NextToken</code> value.</p> </li> <li> <p>The order of
         * snapshots returned in the response of one <code>DescribeSnapshots</code> call
         * and the order of backups returned across the responses of a multi-call iteration
         * is unspecified. </p> </li> </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeSnapshots">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeSnapshotsOutcome DescribeSnapshots(const Model::DescribeSnapshotsRequest& request) const;

        /**
         * <p>Returns the description of specific Amazon FSx for OpenZFS snapshots, if a
         * <code>SnapshotIds</code> value is provided. Otherwise, this operation returns
         * all snapshots owned by your Amazon Web Services account in the Amazon Web
         * Services Region of the endpoint that you're calling.</p> <p>When retrieving all
         * snapshots, you can optionally specify the <code>MaxResults</code> parameter to
         * limit the number of snapshots in a response. If more backups remain, Amazon FSx
         * returns a <code>NextToken</code> value in the response. In this case, send a
         * later request with the <code>NextToken</code> request parameter set to the value
         * of <code>NextToken</code> from the last response. </p> <p>Use this operation in
         * an iterative process to retrieve a list of your snapshots.
         * <code>DescribeSnapshots</code> is called first without a <code>NextToken</code>
         * value. Then the operation continues to be called with the <code>NextToken</code>
         * parameter set to the value of the last <code>NextToken</code> value until a
         * response has no <code>NextToken</code> value.</p> <p>When using this operation,
         * keep the following in mind:</p> <ul> <li> <p>The operation might return fewer
         * than the <code>MaxResults</code> value of snapshot descriptions while still
         * including a <code>NextToken</code> value.</p> </li> <li> <p>The order of
         * snapshots returned in the response of one <code>DescribeSnapshots</code> call
         * and the order of backups returned across the responses of a multi-call iteration
         * is unspecified. </p> </li> </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeSnapshots">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeSnapshotsOutcomeCallable DescribeSnapshotsCallable(const Model::DescribeSnapshotsRequest& request) const;

        /**
         * <p>Returns the description of specific Amazon FSx for OpenZFS snapshots, if a
         * <code>SnapshotIds</code> value is provided. Otherwise, this operation returns
         * all snapshots owned by your Amazon Web Services account in the Amazon Web
         * Services Region of the endpoint that you're calling.</p> <p>When retrieving all
         * snapshots, you can optionally specify the <code>MaxResults</code> parameter to
         * limit the number of snapshots in a response. If more backups remain, Amazon FSx
         * returns a <code>NextToken</code> value in the response. In this case, send a
         * later request with the <code>NextToken</code> request parameter set to the value
         * of <code>NextToken</code> from the last response. </p> <p>Use this operation in
         * an iterative process to retrieve a list of your snapshots.
         * <code>DescribeSnapshots</code> is called first without a <code>NextToken</code>
         * value. Then the operation continues to be called with the <code>NextToken</code>
         * parameter set to the value of the last <code>NextToken</code> value until a
         * response has no <code>NextToken</code> value.</p> <p>When using this operation,
         * keep the following in mind:</p> <ul> <li> <p>The operation might return fewer
         * than the <code>MaxResults</code> value of snapshot descriptions while still
         * including a <code>NextToken</code> value.</p> </li> <li> <p>The order of
         * snapshots returned in the response of one <code>DescribeSnapshots</code> call
         * and the order of backups returned across the responses of a multi-call iteration
         * is unspecified. </p> </li> </ul><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeSnapshots">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeSnapshotsAsync(const Model::DescribeSnapshotsRequest& request, const DescribeSnapshotsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Describes one or more Amazon FSx for NetApp ONTAP storage virtual machines
         * (SVMs).</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeStorageVirtualMachines">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeStorageVirtualMachinesOutcome DescribeStorageVirtualMachines(const Model::DescribeStorageVirtualMachinesRequest& request) const;

        /**
         * <p>Describes one or more Amazon FSx for NetApp ONTAP storage virtual machines
         * (SVMs).</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeStorageVirtualMachines">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeStorageVirtualMachinesOutcomeCallable DescribeStorageVirtualMachinesCallable(const Model::DescribeStorageVirtualMachinesRequest& request) const;

        /**
         * <p>Describes one or more Amazon FSx for NetApp ONTAP storage virtual machines
         * (SVMs).</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeStorageVirtualMachines">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeStorageVirtualMachinesAsync(const Model::DescribeStorageVirtualMachinesRequest& request, const DescribeStorageVirtualMachinesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Describes one or more Amazon FSx for NetApp ONTAP or Amazon FSx for OpenZFS
         * volumes.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeVolumes">AWS
         * API Reference</a></p>
         */
        virtual Model::DescribeVolumesOutcome DescribeVolumes(const Model::DescribeVolumesRequest& request) const;

        /**
         * <p>Describes one or more Amazon FSx for NetApp ONTAP or Amazon FSx for OpenZFS
         * volumes.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeVolumes">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DescribeVolumesOutcomeCallable DescribeVolumesCallable(const Model::DescribeVolumesRequest& request) const;

        /**
         * <p>Describes one or more Amazon FSx for NetApp ONTAP or Amazon FSx for OpenZFS
         * volumes.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DescribeVolumes">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DescribeVolumesAsync(const Model::DescribeVolumesRequest& request, const DescribeVolumesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Use this action to disassociate, or remove, one or more Domain Name Service
         * (DNS) aliases from an Amazon FSx for Windows File Server file system. If you
         * attempt to disassociate a DNS alias that is not associated with the file system,
         * Amazon FSx responds with a 400 Bad Request. For more information, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/managing-dns-aliases.html">Working
         * with DNS Aliases</a>.</p> <p>The system generated response showing the DNS
         * aliases that Amazon FSx is attempting to disassociate from the file system. Use
         * the API operation to monitor the status of the aliases Amazon FSx is
         * disassociating with the file system.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DisassociateFileSystemAliases">AWS
         * API Reference</a></p>
         */
        virtual Model::DisassociateFileSystemAliasesOutcome DisassociateFileSystemAliases(const Model::DisassociateFileSystemAliasesRequest& request) const;

        /**
         * <p>Use this action to disassociate, or remove, one or more Domain Name Service
         * (DNS) aliases from an Amazon FSx for Windows File Server file system. If you
         * attempt to disassociate a DNS alias that is not associated with the file system,
         * Amazon FSx responds with a 400 Bad Request. For more information, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/managing-dns-aliases.html">Working
         * with DNS Aliases</a>.</p> <p>The system generated response showing the DNS
         * aliases that Amazon FSx is attempting to disassociate from the file system. Use
         * the API operation to monitor the status of the aliases Amazon FSx is
         * disassociating with the file system.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DisassociateFileSystemAliases">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::DisassociateFileSystemAliasesOutcomeCallable DisassociateFileSystemAliasesCallable(const Model::DisassociateFileSystemAliasesRequest& request) const;

        /**
         * <p>Use this action to disassociate, or remove, one or more Domain Name Service
         * (DNS) aliases from an Amazon FSx for Windows File Server file system. If you
         * attempt to disassociate a DNS alias that is not associated with the file system,
         * Amazon FSx responds with a 400 Bad Request. For more information, see <a
         * href="https://docs.aws.amazon.com/fsx/latest/WindowsGuide/managing-dns-aliases.html">Working
         * with DNS Aliases</a>.</p> <p>The system generated response showing the DNS
         * aliases that Amazon FSx is attempting to disassociate from the file system. Use
         * the API operation to monitor the status of the aliases Amazon FSx is
         * disassociating with the file system.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/DisassociateFileSystemAliases">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void DisassociateFileSystemAliasesAsync(const Model::DisassociateFileSystemAliasesRequest& request, const DisassociateFileSystemAliasesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Lists tags for an Amazon FSx file systems and backups in the case of Amazon
         * FSx for Windows File Server.</p> <p>When retrieving all tags, you can optionally
         * specify the <code>MaxResults</code> parameter to limit the number of tags in a
         * response. If more tags remain, Amazon FSx returns a <code>NextToken</code> value
         * in the response. In this case, send a later request with the
         * <code>NextToken</code> request parameter set to the value of
         * <code>NextToken</code> from the last response.</p> <p>This action is used in an
         * iterative process to retrieve a list of your tags.
         * <code>ListTagsForResource</code> is called first without a
         * <code>NextToken</code>value. Then the action continues to be called with the
         * <code>NextToken</code> parameter set to the value of the last
         * <code>NextToken</code> value until a response has no <code>NextToken</code>.</p>
         * <p>When using this action, keep the following in mind:</p> <ul> <li> <p>The
         * implementation might return fewer than <code>MaxResults</code> file system
         * descriptions while still including a <code>NextToken</code> value.</p> </li>
         * <li> <p>The order of tags returned in the response of one
         * <code>ListTagsForResource</code> call and the order of tags returned across the
         * responses of a multi-call iteration is unspecified.</p> </li> </ul><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/ListTagsForResource">AWS
         * API Reference</a></p>
         */
        virtual Model::ListTagsForResourceOutcome ListTagsForResource(const Model::ListTagsForResourceRequest& request) const;

        /**
         * <p>Lists tags for an Amazon FSx file systems and backups in the case of Amazon
         * FSx for Windows File Server.</p> <p>When retrieving all tags, you can optionally
         * specify the <code>MaxResults</code> parameter to limit the number of tags in a
         * response. If more tags remain, Amazon FSx returns a <code>NextToken</code> value
         * in the response. In this case, send a later request with the
         * <code>NextToken</code> request parameter set to the value of
         * <code>NextToken</code> from the last response.</p> <p>This action is used in an
         * iterative process to retrieve a list of your tags.
         * <code>ListTagsForResource</code> is called first without a
         * <code>NextToken</code>value. Then the action continues to be called with the
         * <code>NextToken</code> parameter set to the value of the last
         * <code>NextToken</code> value until a response has no <code>NextToken</code>.</p>
         * <p>When using this action, keep the following in mind:</p> <ul> <li> <p>The
         * implementation might return fewer than <code>MaxResults</code> file system
         * descriptions while still including a <code>NextToken</code> value.</p> </li>
         * <li> <p>The order of tags returned in the response of one
         * <code>ListTagsForResource</code> call and the order of tags returned across the
         * responses of a multi-call iteration is unspecified.</p> </li> </ul><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/ListTagsForResource">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::ListTagsForResourceOutcomeCallable ListTagsForResourceCallable(const Model::ListTagsForResourceRequest& request) const;

        /**
         * <p>Lists tags for an Amazon FSx file systems and backups in the case of Amazon
         * FSx for Windows File Server.</p> <p>When retrieving all tags, you can optionally
         * specify the <code>MaxResults</code> parameter to limit the number of tags in a
         * response. If more tags remain, Amazon FSx returns a <code>NextToken</code> value
         * in the response. In this case, send a later request with the
         * <code>NextToken</code> request parameter set to the value of
         * <code>NextToken</code> from the last response.</p> <p>This action is used in an
         * iterative process to retrieve a list of your tags.
         * <code>ListTagsForResource</code> is called first without a
         * <code>NextToken</code>value. Then the action continues to be called with the
         * <code>NextToken</code> parameter set to the value of the last
         * <code>NextToken</code> value until a response has no <code>NextToken</code>.</p>
         * <p>When using this action, keep the following in mind:</p> <ul> <li> <p>The
         * implementation might return fewer than <code>MaxResults</code> file system
         * descriptions while still including a <code>NextToken</code> value.</p> </li>
         * <li> <p>The order of tags returned in the response of one
         * <code>ListTagsForResource</code> call and the order of tags returned across the
         * responses of a multi-call iteration is unspecified.</p> </li> </ul><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/ListTagsForResource">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void ListTagsForResourceAsync(const Model::ListTagsForResourceRequest& request, const ListTagsForResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Releases the file system lock from an Amazon FSx for OpenZFS file
         * system.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/ReleaseFileSystemNfsV3Locks">AWS
         * API Reference</a></p>
         */
        virtual Model::ReleaseFileSystemNfsV3LocksOutcome ReleaseFileSystemNfsV3Locks(const Model::ReleaseFileSystemNfsV3LocksRequest& request) const;

        /**
         * <p>Releases the file system lock from an Amazon FSx for OpenZFS file
         * system.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/ReleaseFileSystemNfsV3Locks">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::ReleaseFileSystemNfsV3LocksOutcomeCallable ReleaseFileSystemNfsV3LocksCallable(const Model::ReleaseFileSystemNfsV3LocksRequest& request) const;

        /**
         * <p>Releases the file system lock from an Amazon FSx for OpenZFS file
         * system.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/ReleaseFileSystemNfsV3Locks">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void ReleaseFileSystemNfsV3LocksAsync(const Model::ReleaseFileSystemNfsV3LocksRequest& request, const ReleaseFileSystemNfsV3LocksResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Returns an Amazon FSx for OpenZFS volume to the state saved by the specified
         * snapshot. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/RestoreVolumeFromSnapshot">AWS
         * API Reference</a></p>
         */
        virtual Model::RestoreVolumeFromSnapshotOutcome RestoreVolumeFromSnapshot(const Model::RestoreVolumeFromSnapshotRequest& request) const;

        /**
         * <p>Returns an Amazon FSx for OpenZFS volume to the state saved by the specified
         * snapshot. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/RestoreVolumeFromSnapshot">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::RestoreVolumeFromSnapshotOutcomeCallable RestoreVolumeFromSnapshotCallable(const Model::RestoreVolumeFromSnapshotRequest& request) const;

        /**
         * <p>Returns an Amazon FSx for OpenZFS volume to the state saved by the specified
         * snapshot. </p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/RestoreVolumeFromSnapshot">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void RestoreVolumeFromSnapshotAsync(const Model::RestoreVolumeFromSnapshotRequest& request, const RestoreVolumeFromSnapshotResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Tags an Amazon FSx resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/TagResource">AWS API
         * Reference</a></p>
         */
        virtual Model::TagResourceOutcome TagResource(const Model::TagResourceRequest& request) const;

        /**
         * <p>Tags an Amazon FSx resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/TagResource">AWS API
         * Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::TagResourceOutcomeCallable TagResourceCallable(const Model::TagResourceRequest& request) const;

        /**
         * <p>Tags an Amazon FSx resource.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/TagResource">AWS API
         * Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void TagResourceAsync(const Model::TagResourceRequest& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>This action removes a tag from an Amazon FSx resource.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UntagResource">AWS
         * API Reference</a></p>
         */
        virtual Model::UntagResourceOutcome UntagResource(const Model::UntagResourceRequest& request) const;

        /**
         * <p>This action removes a tag from an Amazon FSx resource.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UntagResource">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::UntagResourceOutcomeCallable UntagResourceCallable(const Model::UntagResourceRequest& request) const;

        /**
         * <p>This action removes a tag from an Amazon FSx resource.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UntagResource">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void UntagResourceAsync(const Model::UntagResourceRequest& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Updates the configuration of an existing data repository association on an
         * Amazon FSx for Lustre file system. Data repository associations are supported
         * only for file systems with the <code>Persistent_2</code> deployment
         * type.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateDataRepositoryAssociation">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateDataRepositoryAssociationOutcome UpdateDataRepositoryAssociation(const Model::UpdateDataRepositoryAssociationRequest& request) const;

        /**
         * <p>Updates the configuration of an existing data repository association on an
         * Amazon FSx for Lustre file system. Data repository associations are supported
         * only for file systems with the <code>Persistent_2</code> deployment
         * type.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateDataRepositoryAssociation">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::UpdateDataRepositoryAssociationOutcomeCallable UpdateDataRepositoryAssociationCallable(const Model::UpdateDataRepositoryAssociationRequest& request) const;

        /**
         * <p>Updates the configuration of an existing data repository association on an
         * Amazon FSx for Lustre file system. Data repository associations are supported
         * only for file systems with the <code>Persistent_2</code> deployment
         * type.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateDataRepositoryAssociation">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void UpdateDataRepositoryAssociationAsync(const Model::UpdateDataRepositoryAssociationRequest& request, const UpdateDataRepositoryAssociationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Use this operation to update the configuration of an existing Amazon FSx file
         * system. You can update multiple properties in a single request.</p> <p>For
         * Amazon FSx for Windows File Server file systems, you can update the following
         * properties:</p> <ul> <li> <p> <code>AuditLogConfiguration</code> </p> </li> <li>
         * <p> <code>AutomaticBackupRetentionDays</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>SelfManagedActiveDirectoryConfiguration</code> </p> </li> <li> <p>
         * <code>StorageCapacity</code> </p> </li> <li> <p> <code>ThroughputCapacity</code>
         * </p> </li> <li> <p> <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul>
         * <p>For Amazon FSx for Lustre file systems, you can update the following
         * properties:</p> <ul> <li> <p> <code>AutoImportPolicy</code> </p> </li> <li> <p>
         * <code>AutomaticBackupRetentionDays</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>DataCompressionType</code> </p> </li> <li> <p>
         * <code>StorageCapacity</code> </p> </li> <li> <p>
         * <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul> <p>For Amazon FSx for
         * NetApp ONTAP file systems, you can update the following properties:</p> <ul>
         * <li> <p> <code>AutomaticBackupRetentionDays</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>DiskIopsConfiguration</code> </p> </li> <li> <p>
         * <code>FsxAdminPassword</code> </p> </li> <li> <p> <code>StorageCapacity</code>
         * </p> </li> <li> <p> <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul>
         * <p>For the Amazon FSx for OpenZFS file systems, you can update the following
         * properties:</p> <ul> <li> <p> <code>AutomaticBackupRetentionDays</code> </p>
         * </li> <li> <p> <code>CopyTagsToBackups</code> </p> </li> <li> <p>
         * <code>CopyTagsToVolumes</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>ThroughputCapacity</code> </p> </li> <li> <p>
         * <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul><p><h3>See Also:</h3>  
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateFileSystem">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateFileSystemOutcome UpdateFileSystem(const Model::UpdateFileSystemRequest& request) const;

        /**
         * <p>Use this operation to update the configuration of an existing Amazon FSx file
         * system. You can update multiple properties in a single request.</p> <p>For
         * Amazon FSx for Windows File Server file systems, you can update the following
         * properties:</p> <ul> <li> <p> <code>AuditLogConfiguration</code> </p> </li> <li>
         * <p> <code>AutomaticBackupRetentionDays</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>SelfManagedActiveDirectoryConfiguration</code> </p> </li> <li> <p>
         * <code>StorageCapacity</code> </p> </li> <li> <p> <code>ThroughputCapacity</code>
         * </p> </li> <li> <p> <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul>
         * <p>For Amazon FSx for Lustre file systems, you can update the following
         * properties:</p> <ul> <li> <p> <code>AutoImportPolicy</code> </p> </li> <li> <p>
         * <code>AutomaticBackupRetentionDays</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>DataCompressionType</code> </p> </li> <li> <p>
         * <code>StorageCapacity</code> </p> </li> <li> <p>
         * <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul> <p>For Amazon FSx for
         * NetApp ONTAP file systems, you can update the following properties:</p> <ul>
         * <li> <p> <code>AutomaticBackupRetentionDays</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>DiskIopsConfiguration</code> </p> </li> <li> <p>
         * <code>FsxAdminPassword</code> </p> </li> <li> <p> <code>StorageCapacity</code>
         * </p> </li> <li> <p> <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul>
         * <p>For the Amazon FSx for OpenZFS file systems, you can update the following
         * properties:</p> <ul> <li> <p> <code>AutomaticBackupRetentionDays</code> </p>
         * </li> <li> <p> <code>CopyTagsToBackups</code> </p> </li> <li> <p>
         * <code>CopyTagsToVolumes</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>ThroughputCapacity</code> </p> </li> <li> <p>
         * <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul><p><h3>See Also:</h3>  
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateFileSystem">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::UpdateFileSystemOutcomeCallable UpdateFileSystemCallable(const Model::UpdateFileSystemRequest& request) const;

        /**
         * <p>Use this operation to update the configuration of an existing Amazon FSx file
         * system. You can update multiple properties in a single request.</p> <p>For
         * Amazon FSx for Windows File Server file systems, you can update the following
         * properties:</p> <ul> <li> <p> <code>AuditLogConfiguration</code> </p> </li> <li>
         * <p> <code>AutomaticBackupRetentionDays</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>SelfManagedActiveDirectoryConfiguration</code> </p> </li> <li> <p>
         * <code>StorageCapacity</code> </p> </li> <li> <p> <code>ThroughputCapacity</code>
         * </p> </li> <li> <p> <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul>
         * <p>For Amazon FSx for Lustre file systems, you can update the following
         * properties:</p> <ul> <li> <p> <code>AutoImportPolicy</code> </p> </li> <li> <p>
         * <code>AutomaticBackupRetentionDays</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>DataCompressionType</code> </p> </li> <li> <p>
         * <code>StorageCapacity</code> </p> </li> <li> <p>
         * <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul> <p>For Amazon FSx for
         * NetApp ONTAP file systems, you can update the following properties:</p> <ul>
         * <li> <p> <code>AutomaticBackupRetentionDays</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>DiskIopsConfiguration</code> </p> </li> <li> <p>
         * <code>FsxAdminPassword</code> </p> </li> <li> <p> <code>StorageCapacity</code>
         * </p> </li> <li> <p> <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul>
         * <p>For the Amazon FSx for OpenZFS file systems, you can update the following
         * properties:</p> <ul> <li> <p> <code>AutomaticBackupRetentionDays</code> </p>
         * </li> <li> <p> <code>CopyTagsToBackups</code> </p> </li> <li> <p>
         * <code>CopyTagsToVolumes</code> </p> </li> <li> <p>
         * <code>DailyAutomaticBackupStartTime</code> </p> </li> <li> <p>
         * <code>ThroughputCapacity</code> </p> </li> <li> <p>
         * <code>WeeklyMaintenanceStartTime</code> </p> </li> </ul><p><h3>See Also:</h3>  
         * <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateFileSystem">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void UpdateFileSystemAsync(const Model::UpdateFileSystemRequest& request, const UpdateFileSystemResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Updates the name of an Amazon FSx for OpenZFS snapshot.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateSnapshot">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateSnapshotOutcome UpdateSnapshot(const Model::UpdateSnapshotRequest& request) const;

        /**
         * <p>Updates the name of an Amazon FSx for OpenZFS snapshot.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateSnapshot">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::UpdateSnapshotOutcomeCallable UpdateSnapshotCallable(const Model::UpdateSnapshotRequest& request) const;

        /**
         * <p>Updates the name of an Amazon FSx for OpenZFS snapshot.</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateSnapshot">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void UpdateSnapshotAsync(const Model::UpdateSnapshotRequest& request, const UpdateSnapshotResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Updates an Amazon FSx for ONTAP storage virtual machine (SVM).</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateStorageVirtualMachine">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateStorageVirtualMachineOutcome UpdateStorageVirtualMachine(const Model::UpdateStorageVirtualMachineRequest& request) const;

        /**
         * <p>Updates an Amazon FSx for ONTAP storage virtual machine (SVM).</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateStorageVirtualMachine">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::UpdateStorageVirtualMachineOutcomeCallable UpdateStorageVirtualMachineCallable(const Model::UpdateStorageVirtualMachineRequest& request) const;

        /**
         * <p>Updates an Amazon FSx for ONTAP storage virtual machine (SVM).</p><p><h3>See
         * Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateStorageVirtualMachine">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void UpdateStorageVirtualMachineAsync(const Model::UpdateStorageVirtualMachineRequest& request, const UpdateStorageVirtualMachineResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;

        /**
         * <p>Updates the configuration of an Amazon FSx for NetApp ONTAP or Amazon FSx for
         * OpenZFS volume.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateVolume">AWS
         * API Reference</a></p>
         */
        virtual Model::UpdateVolumeOutcome UpdateVolume(const Model::UpdateVolumeRequest& request) const;

        /**
         * <p>Updates the configuration of an Amazon FSx for NetApp ONTAP or Amazon FSx for
         * OpenZFS volume.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateVolume">AWS
         * API Reference</a></p>
         *
         * returns a future to the operation so that it can be executed in parallel to other requests.
         */
        virtual Model::UpdateVolumeOutcomeCallable UpdateVolumeCallable(const Model::UpdateVolumeRequest& request) const;

        /**
         * <p>Updates the configuration of an Amazon FSx for NetApp ONTAP or Amazon FSx for
         * OpenZFS volume.</p><p><h3>See Also:</h3>   <a
         * href="http://docs.aws.amazon.com/goto/WebAPI/fsx-2018-03-01/UpdateVolume">AWS
         * API Reference</a></p>
         *
         * Queues the request into a thread executor and triggers associated callback when operation has finished.
         */
        virtual void UpdateVolumeAsync(const Model::UpdateVolumeRequest& request, const UpdateVolumeResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context = nullptr) const;


      void OverrideEndpoint(const Aws::String& endpoint);
    private:
      void init(const Aws::Client::ClientConfiguration& clientConfiguration);
        void AssociateFileSystemAliasesAsyncHelper(const Model::AssociateFileSystemAliasesRequest& request, const AssociateFileSystemAliasesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CancelDataRepositoryTaskAsyncHelper(const Model::CancelDataRepositoryTaskRequest& request, const CancelDataRepositoryTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CopyBackupAsyncHelper(const Model::CopyBackupRequest& request, const CopyBackupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateBackupAsyncHelper(const Model::CreateBackupRequest& request, const CreateBackupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateDataRepositoryAssociationAsyncHelper(const Model::CreateDataRepositoryAssociationRequest& request, const CreateDataRepositoryAssociationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateDataRepositoryTaskAsyncHelper(const Model::CreateDataRepositoryTaskRequest& request, const CreateDataRepositoryTaskResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateFileSystemAsyncHelper(const Model::CreateFileSystemRequest& request, const CreateFileSystemResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateFileSystemFromBackupAsyncHelper(const Model::CreateFileSystemFromBackupRequest& request, const CreateFileSystemFromBackupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateSnapshotAsyncHelper(const Model::CreateSnapshotRequest& request, const CreateSnapshotResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateStorageVirtualMachineAsyncHelper(const Model::CreateStorageVirtualMachineRequest& request, const CreateStorageVirtualMachineResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateVolumeAsyncHelper(const Model::CreateVolumeRequest& request, const CreateVolumeResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void CreateVolumeFromBackupAsyncHelper(const Model::CreateVolumeFromBackupRequest& request, const CreateVolumeFromBackupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteBackupAsyncHelper(const Model::DeleteBackupRequest& request, const DeleteBackupResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteDataRepositoryAssociationAsyncHelper(const Model::DeleteDataRepositoryAssociationRequest& request, const DeleteDataRepositoryAssociationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteFileSystemAsyncHelper(const Model::DeleteFileSystemRequest& request, const DeleteFileSystemResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteSnapshotAsyncHelper(const Model::DeleteSnapshotRequest& request, const DeleteSnapshotResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteStorageVirtualMachineAsyncHelper(const Model::DeleteStorageVirtualMachineRequest& request, const DeleteStorageVirtualMachineResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DeleteVolumeAsyncHelper(const Model::DeleteVolumeRequest& request, const DeleteVolumeResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeBackupsAsyncHelper(const Model::DescribeBackupsRequest& request, const DescribeBackupsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeDataRepositoryAssociationsAsyncHelper(const Model::DescribeDataRepositoryAssociationsRequest& request, const DescribeDataRepositoryAssociationsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeDataRepositoryTasksAsyncHelper(const Model::DescribeDataRepositoryTasksRequest& request, const DescribeDataRepositoryTasksResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeFileSystemAliasesAsyncHelper(const Model::DescribeFileSystemAliasesRequest& request, const DescribeFileSystemAliasesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeFileSystemsAsyncHelper(const Model::DescribeFileSystemsRequest& request, const DescribeFileSystemsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeSnapshotsAsyncHelper(const Model::DescribeSnapshotsRequest& request, const DescribeSnapshotsResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeStorageVirtualMachinesAsyncHelper(const Model::DescribeStorageVirtualMachinesRequest& request, const DescribeStorageVirtualMachinesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DescribeVolumesAsyncHelper(const Model::DescribeVolumesRequest& request, const DescribeVolumesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void DisassociateFileSystemAliasesAsyncHelper(const Model::DisassociateFileSystemAliasesRequest& request, const DisassociateFileSystemAliasesResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void ListTagsForResourceAsyncHelper(const Model::ListTagsForResourceRequest& request, const ListTagsForResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void ReleaseFileSystemNfsV3LocksAsyncHelper(const Model::ReleaseFileSystemNfsV3LocksRequest& request, const ReleaseFileSystemNfsV3LocksResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void RestoreVolumeFromSnapshotAsyncHelper(const Model::RestoreVolumeFromSnapshotRequest& request, const RestoreVolumeFromSnapshotResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void TagResourceAsyncHelper(const Model::TagResourceRequest& request, const TagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void UntagResourceAsyncHelper(const Model::UntagResourceRequest& request, const UntagResourceResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void UpdateDataRepositoryAssociationAsyncHelper(const Model::UpdateDataRepositoryAssociationRequest& request, const UpdateDataRepositoryAssociationResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void UpdateFileSystemAsyncHelper(const Model::UpdateFileSystemRequest& request, const UpdateFileSystemResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void UpdateSnapshotAsyncHelper(const Model::UpdateSnapshotRequest& request, const UpdateSnapshotResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void UpdateStorageVirtualMachineAsyncHelper(const Model::UpdateStorageVirtualMachineRequest& request, const UpdateStorageVirtualMachineResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;
        void UpdateVolumeAsyncHelper(const Model::UpdateVolumeRequest& request, const UpdateVolumeResponseReceivedHandler& handler, const std::shared_ptr<const Aws::Client::AsyncCallerContext>& context) const;

      Aws::String m_uri;
      Aws::String m_configScheme;
      std::shared_ptr<Aws::Utils::Threading::Executor> m_executor;
  };

} // namespace FSx
} // namespace Aws
