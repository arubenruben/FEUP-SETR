#pragma once

#include <Arduino.h>
#include <errno.h>
#include "constants.h"
#include "segments.h"
#include "measurements.h"

typedef struct
{
    uint8_t static_priority;
    uint8_t dynamic_priority;
    uint32_t delay;
    uint32_t period;
    uint8_t state;

    uint8_t *stack_pointer;

    void *(*func)(void *);

    void *params;

} task_t;

void task_stack_init(task_t *task);

void *task_measure_1(void *args);
void *task_measure_2(void *args);
void *task_measure_3(void *args);

void *task_1(void *args);

void *task_2(void *args);

void *task_3(void *args);

void *task_4(void *args);

void *task_5(void *args);

void *task_6(void *args);

void *task_7(void *args);

void *task_idle(void *args);
