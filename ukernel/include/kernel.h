#pragma once

#include <Arduino.h>
#include "constants.h"
#include "task.h"
#include "scheduler.h"
#include "context.h"

extern volatile uint8_t stack[N_TASKS * TASK_STACK_SIZE];

extern Task tasks[N_TASKS];

extern volatile uint8_t current_task;

void initialize_kernel();