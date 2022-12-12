#include "kernel.h"

void initialize_stack()
{
    uint8_t stack[N_TASKS * TASK_STACK_SIZE];

    for (size_t i = 0; i < N_TASKS * TASK_STACK_SIZE; i++)
    {
        stack[i] = 0x00;
    }
}

void initialize_tasks()
{
    Task tasks[N_TASKS];

    for (uint8_t i = 0; i < N_TASKS; i++)
    {
        tasks[i] = add_task(i);
    }
}

void initialize_kernel()
{
    initialize_stack();
    initialize_tasks();
}