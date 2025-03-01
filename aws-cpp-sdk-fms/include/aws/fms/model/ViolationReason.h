﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/fms/FMS_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSString.h>

namespace Aws
{
namespace FMS
{
namespace Model
{
  enum class ViolationReason
  {
    NOT_SET,
    WEB_ACL_MISSING_RULE_GROUP,
    RESOURCE_MISSING_WEB_ACL,
    RESOURCE_INCORRECT_WEB_ACL,
    RESOURCE_MISSING_SHIELD_PROTECTION,
    RESOURCE_MISSING_WEB_ACL_OR_SHIELD_PROTECTION,
    RESOURCE_MISSING_SECURITY_GROUP,
    RESOURCE_VIOLATES_AUDIT_SECURITY_GROUP,
    SECURITY_GROUP_UNUSED,
    SECURITY_GROUP_REDUNDANT,
    FMS_CREATED_SECURITY_GROUP_EDITED,
    MISSING_FIREWALL,
    MISSING_FIREWALL_SUBNET_IN_AZ,
    MISSING_EXPECTED_ROUTE_TABLE,
    NETWORK_FIREWALL_POLICY_MODIFIED,
    INTERNET_GATEWAY_MISSING_EXPECTED_ROUTE,
    FIREWALL_SUBNET_MISSING_EXPECTED_ROUTE,
    UNEXPECTED_FIREWALL_ROUTES,
    UNEXPECTED_TARGET_GATEWAY_ROUTES,
    TRAFFIC_INSPECTION_CROSSES_AZ_BOUNDARY,
    INVALID_ROUTE_CONFIGURATION,
    MISSING_TARGET_GATEWAY,
    INTERNET_TRAFFIC_NOT_INSPECTED,
    BLACK_HOLE_ROUTE_DETECTED,
    BLACK_HOLE_ROUTE_DETECTED_IN_FIREWALL_SUBNET,
    RESOURCE_MISSING_DNS_FIREWALL,
    FIREWALL_SUBNET_IS_OUT_OF_SCOPE,
    ROUTE_HAS_OUT_OF_SCOPE_ENDPOINT
  };

namespace ViolationReasonMapper
{
AWS_FMS_API ViolationReason GetViolationReasonForName(const Aws::String& name);

AWS_FMS_API Aws::String GetNameForViolationReason(ViolationReason value);
} // namespace ViolationReasonMapper
} // namespace Model
} // namespace FMS
} // namespace Aws
