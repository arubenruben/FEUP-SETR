#pragma once

#include <Arduino.h>
#include "constants.h"
#include "context.h"
#include "task.h"
#include "kernel.h"

void scheduler_tick_handler() __attribute__((naked));

void scheduler_schedule(void);

void scheduler_dispatch(void);