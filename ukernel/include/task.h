#pragma once

#include <Arduino.h>
#include <errno.h>
#include "constants.h"

typedef struct struct_task
{
    uint8_t priority;
    uint8_t delay;
    uint8_t period;
    uint8_t state;

    volatile uint8_t *stack_pointer;

    void *(*func)(void *);

    void *params;

} task_t;

void task_stack_init(task_t *task);

void *task_1(void *args);

void *task_2(void *args);

void *task_idle(void *args);
