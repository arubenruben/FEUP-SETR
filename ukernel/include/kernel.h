#pragma once

#include <Arduino.h>
#include "constants.h"
#include "task.h"
#include "context.h"
#include "scheduler.h"
#include "timer.h"

extern task_t tasks[MAX_TASKS];
extern uint8_t stack[TASK_STACK_SIZE * MAX_TASKS];
extern uint8_t n_tasks;

extern volatile task_t *current_task, *idle_task;

void kernel_init(void);
void kernel_start(void);