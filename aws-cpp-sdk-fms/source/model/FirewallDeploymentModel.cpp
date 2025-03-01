﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#include <aws/fms/model/FirewallDeploymentModel.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace FMS
  {
    namespace Model
    {
      namespace FirewallDeploymentModelMapper
      {

        static const int CENTRALIZED_HASH = HashingUtils::HashString("CENTRALIZED");


        FirewallDeploymentModel GetFirewallDeploymentModelForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == CENTRALIZED_HASH)
          {
            return FirewallDeploymentModel::CENTRALIZED;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<FirewallDeploymentModel>(hashCode);
          }

          return FirewallDeploymentModel::NOT_SET;
        }

        Aws::String GetNameForFirewallDeploymentModel(FirewallDeploymentModel enumValue)
        {
          switch(enumValue)
          {
          case FirewallDeploymentModel::CENTRALIZED:
            return "CENTRALIZED";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace FirewallDeploymentModelMapper
    } // namespace Model
  } // namespace FMS
} // namespace Aws
