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

#ifndef CONTIKI_CORE_H_
#define CONTIKI_CORE_H_

// Define type of clock_time_t and how
// many ticks a second have.
typedef unsigned long clock_time_t;
#define CLOCK_SECOND  1024

// Set to 1 to enable global debugging
#define DEBUG 0

#include <stdint.h>
#include <stddef.h>
#include "contiki-core-version.h"

#include "sys/process.h"
#include "sys/autostart.h"

#include "sys/clock.h"
#include "sys/timer.h"
#include "sys/ctimer.h"
#include "sys/etimer.h"

#include "sys/pt.h"
#include "sys/procinit.h"

#endif /* CONTIKI_CORE_H_ */
