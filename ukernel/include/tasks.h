#pragma once

#include <Arduino.h>

typedef struct struct_task
{
    volatile uint16_t *stack_pointer;

    void (*func)(void);

} task_t;

void task_1(void);

void init_task_stack(task_t *task);