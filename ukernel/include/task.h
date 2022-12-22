#pragma once

#include <Arduino.h>
#include <errno.h>
#include "constants.h"
#include "segments.h"

typedef struct
{
    uint8_t static_priority;
    uint8_t dynamic_priority;
    uint8_t delay;
    uint8_t period;
    uint8_t state;

    uint8_t *stack_pointer;

    void *(*func)(void *);

    void *params;

} task_t;

void task_stack_init(task_t *task);

void *task_1(void *args);

void *task_2(void *args);

void *task_3(void *args);

void *task_4(void *args);

void *task_5(void *args);

void *task_6(void *args);

void *task_idle(void *args);
