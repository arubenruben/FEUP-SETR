#pragma once

#include <Arduino.h>
#include "constants.h"
#include "task.h"
#include "scheduler.h"
#include "context.h"

extern uint8_t stack[N_TASKS * TASK_STACK_SIZE];

extern task_t tasks[N_TASKS];

extern volatile uint8_t current_task;

void initialize_kernel();

void print_all_stack();

void print_stack_task(uint8_t task_to_print);