#pragma once

#include <Arduino.h>
#include <errno.h>
#include "constants.h"

typedef struct Tasks
{
    uint8_t priority;
    uint8_t state;
    void *(*func)(void *);
} Task;

void *task_1(void *args);

void *task_2(void *args);

void initialize_tasks();

Task add_task(uint8_t priority);