#pragma once

#include <Arduino.h>
#include <errno.h>
#include "constants.h"

typedef struct Tasks
{
    uint8_t priority;
    volatile uint8_t state;
    volatile uint8_t delay;
    uint8_t period;

    void (*func)(void);

    volatile uint8_t *stack_pointer;

} task_t;


void task_1(void);

void *task_2(void *args);

void initialize_tasks();

task_t add_task(uint8_t priority);

void initialize_task_stack_bytes(task_t *task);