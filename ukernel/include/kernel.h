#pragma once

#include <Arduino.h>
#include "constants.h"
#include "tasks.h"
#include "context.h"

extern volatile uint16_t stack[STACK_SIZE];
extern task_t tasks[1];

void init_kernel(void);