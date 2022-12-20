#pragma once

#include <Arduino.h>
#include "constants.h"
#include "context.h"
#include "task.h"
#include "kernel.h"

void scheduler_tick_handler(void) __attribute__((naked));

void scheduler_schedule(void);

void scheduler_dispatch(void);

void scheduler_yield(void) __attribute__((naked));

task_t *scheduler_add_task(uint8_t priority, void *(*func)(void *), void *params, uint8_t delay, uint8_t period);