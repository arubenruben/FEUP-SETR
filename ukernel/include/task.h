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

    volatile uint8_t init;

    void *(*func)(void *);

    void (*scheduler_yield)(void);

    volatile uint8_t *task_user_level_stack_pointer;

} Task;

void *task_1(void *args);

void *task_2(void *args);

void initialize_tasks();

Task add_task(uint8_t priority);