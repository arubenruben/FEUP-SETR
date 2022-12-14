#pragma once

#include <Arduino.h>
#include "constants.h"
#include "task.h"
#include "context.h"

extern uint8_t stack[TASK_STACK_SIZE * N_TASKS];

extern task_t tasks[N_TASKS];

extern uint8_t current_task;

void init_kernel(void);