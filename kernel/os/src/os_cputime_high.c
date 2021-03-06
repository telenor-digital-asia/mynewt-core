/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "os/os_cputime.h"

/**
 * This module implements cputime functionality for timers whose frequency is
 * greater than 1 MHz.
 */

#if defined(OS_CPUTIME_FREQ_HIGH)

/**
 * @addtogroup OSKernel Operating System Kernel
 * @{
 *   @defgroup OSCPUTime High Resolution Timers
 *   @{
 */

/**
 * os cputime usecs to ticks
 *
 * Converts the given number of microseconds into cputime ticks.
 *
 * @param usecs The number of microseconds to convert to ticks
 *
 * @return uint32_t The number of ticks corresponding to 'usecs'
 */
uint32_t
os_cputime_usecs_to_ticks(uint32_t usecs)
{
    return usecs * g_os_cputime.ticks_per_usec;
}

/**
 * cputime ticks to usecs
 *
 * Convert the given number of ticks into microseconds.
 *
 * @param ticks The number of ticks to convert to microseconds.
 *
 * @return uint32_t The number of microseconds corresponding to 'ticks'
 */
uint32_t
os_cputime_ticks_to_usecs(uint32_t ticks)
{
    return (ticks + g_os_cputime.ticks_per_usec - 1) /
           g_os_cputime.ticks_per_usec;
}

/**
 * os cputime nsecs to ticks
 *
 * Converts the given number of nanoseconds into cputime ticks.
 *
 * @param usecs The number of nanoseconds to convert to ticks
 *
 * @return uint32_t The number of ticks corresponding to 'nsecs'
 */
uint32_t
os_cputime_nsecs_to_ticks(uint32_t nsecs)
{
    return (nsecs * g_os_cputime.ticks_per_usec + 999) / 1000;
}

/**
 * os cputime ticks to nsecs
 *
 * Convert the given number of ticks into nanoseconds.
 *
 * @param ticks The number of ticks to convert to nanoseconds.
 *
 * @return uint32_t The number of nanoseconds corresponding to 'ticks'
 */
uint32_t
os_cputime_ticks_to_nsecs(uint32_t ticks)
{
    return (ticks * 1000 + g_os_cputime.ticks_per_usec - 1) /
           g_os_cputime.ticks_per_usec;
}

/**
 *   @} OSCPUTime
 * @} OSKernel
 */

#endif
