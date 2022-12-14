#pragma once

#include <Arduino.h>
#include "constants.h"
#include "task.h"
#include "context.h"

extern uint8_t stack[TASK_STACK_SIZE * NUM_TASKS];

extern task_t tasks[NUM_TASKS];

extern uint8_t current_task;

void init_kernel(void);