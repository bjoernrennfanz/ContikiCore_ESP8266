/*
 * Copyright (c) 2017, Björn Rennfanz
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Institute nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * This file is part of the ContikiCore operating system.
 *
 * Author: Björn Rennfanz <bjoern@fam-rennfanz.de>
 *
 */

#include <ets_sys.h>
#include <os_type.h>
#include <osapi.h>

#include "sys/clock.h"

os_timer_t osInternalClockTimer;
clock_time_t internalClockTicks;

void ICACHE_FLASH_ATTR internalClockCallback(void *pArgs)
{
	// Increment clock ticks
	internalClockTicks++;
}

void ICACHE_FLASH_ATTR clock_init(void)
{
	// Setup and enable internal clock timer callback
	os_timer_setfn(&osInternalClockTimer , internalClockCallback, NULL);
	os_timer_arm(&osInternalClockTimer, (uint32_t)(1000 / CLOCK_SECOND), true);
}

clock_time_t ICACHE_FLASH_ATTR clock_time(void)
{
	// Return internal clock ticks
	return internalClockTicks;
}

unsigned long ICACHE_FLASH_ATTR clock_seconds(void)
{
	return internalClockTicks / CLOCK_SECOND;
}

void ICACHE_FLASH_ATTR clock_set_seconds(unsigned long sec)
{
	// Convert seconds to internal clock ticks
	internalClockTicks = (clock_time_t)sec * CLOCK_SECOND;
}

void ICACHE_FLASH_ATTR clock_wait(clock_time_t t)
{
	clock_time_t start;
	start = clock_time();

	while((clock_time() - start) < (clock_time_t)t);
}

void ICACHE_FLASH_ATTR clock_delay_usec(uint16_t dt)
{
}
