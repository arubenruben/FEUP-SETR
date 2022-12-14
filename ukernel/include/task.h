#pragma once

#include <Arduino.h>

typedef struct struct_task
{
    volatile uint8_t *stack_pointer;

    void (*func)(void);

} task_t;

void task_1(void);

void initialize_task_stack_bytes(task_t *task);