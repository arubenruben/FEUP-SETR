#pragma once

#include <Arduino.h>
#include "constants.h"
#include "kernel.h"
#include "context.h"

void scheduler_schedule(void);

void scheduler_yield(void);

void scheduler_dispatch(void);

void scheduler_tick_handler(void) __attribute__((naked));