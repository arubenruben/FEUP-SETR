#pragma once

#include <Arduino.h>
#include <errno.h>

typedef struct struct_task
{
    uint8_t priority;

    volatile uint8_t *stack_pointer;

    void *(*func)(void *);

} task_t;

task_t add_task(uint8_t priority);

void init_task_bytes(task_t *task);

void *task_1(void *args);

void *task_2(void *args);