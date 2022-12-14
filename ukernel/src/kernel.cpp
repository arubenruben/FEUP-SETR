#include "kernel.h"

uint8_t stack[STACK_SIZE * NUM_TASKS];

task_t tasks[NUM_TASKS];

void init_stack()
{
    for (size_t i = 0; i < STACK_SIZE * NUM_TASKS; i++)
    {
        stack[i] = (uint8_t)0;
    }
}

void init_tasks()
{
    tasks[0].stack_pointer = &stack[STACK_SIZE - 1];
    tasks[0].func = task_1;

    initialize_task_stack_bytes(&tasks[0]);
}

void init_kernel()
{
    init_stack();
    init_tasks();
}