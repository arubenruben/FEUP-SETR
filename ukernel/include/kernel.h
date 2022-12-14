#pragma once

#include <Arduino.h>
#include "task.h"
#include "constants.h"

extern task_t tasks[NUM_TASKS];

extern uint8_t stack[STACK_SIZE*NUM_TASKS];

void init_kernel();