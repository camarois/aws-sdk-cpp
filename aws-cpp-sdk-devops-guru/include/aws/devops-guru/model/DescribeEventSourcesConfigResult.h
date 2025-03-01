﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/devops-guru/DevOpsGuru_EXPORTS.h>
#include <aws/devops-guru/model/EventSourcesConfig.h>
#include <utility>

namespace Aws
{
template<typename RESULT_TYPE>
class AmazonWebServiceResult;

namespace Utils
{
namespace Json
{
  class JsonValue;
} // namespace Json
} // namespace Utils
namespace DevOpsGuru
{
namespace Model
{
  class AWS_DEVOPSGURU_API DescribeEventSourcesConfigResult
  {
  public:
    DescribeEventSourcesConfigResult();
    DescribeEventSourcesConfigResult(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);
    DescribeEventSourcesConfigResult& operator=(const Aws::AmazonWebServiceResult<Aws::Utils::Json::JsonValue>& result);


    /**
     * <p>The name of the event source.</p>
     */
    inline const EventSourcesConfig& GetEventSources() const{ return m_eventSources; }

    /**
     * <p>The name of the event source.</p>
     */
    inline void SetEventSources(const EventSourcesConfig& value) { m_eventSources = value; }

    /**
     * <p>The name of the event source.</p>
     */
    inline void SetEventSources(EventSourcesConfig&& value) { m_eventSources = std::move(value); }

    /**
     * <p>The name of the event source.</p>
     */
    inline DescribeEventSourcesConfigResult& WithEventSources(const EventSourcesConfig& value) { SetEventSources(value); return *this;}

    /**
     * <p>The name of the event source.</p>
     */
    inline DescribeEventSourcesConfigResult& WithEventSources(EventSourcesConfig&& value) { SetEventSources(std::move(value)); return *this;}

  private:

    EventSourcesConfig m_eventSources;
  };

} // namespace Model
} // namespace DevOpsGuru
} // namespace Aws
