#pragma once

#include <Arduino.h>
#include "constants.h"
#include "task.h"
#include "context.h"
#include "scheduler.h"
#include "timer.h"
#include "mutex.h"

extern task_t tasks[MAX_TASKS];
extern uint8_t stack[TASK_STACK_SIZE * MAX_TASKS];
extern uint8_t n_tasks;

extern task_t *current_task;
extern mutex_t mutexes[N_MUTEXES];

extern task_sorted_list_t running_tasks;

void kernel_init(void);
void kernel_start(void);