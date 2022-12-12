#pragma once

#include <Arduino.h>
#include "constants.h"
#include "task.h"

extern uint8_t stack[N_TASKS * TASK_STACK_SIZE];
extern Task tasks[N_TASKS];

void initialize_kernel();