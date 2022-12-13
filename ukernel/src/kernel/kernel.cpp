#include "kernel.h"

Task tasks[N_TASKS];

volatile uint8_t stack[N_TASKS * TASK_STACK_SIZE];

volatile uint8_t current_task;

volatile stackPtr_t *volatile curr_stack;

void initialize_stack()
{
    for (size_t i = 0; i < N_TASKS * TASK_STACK_SIZE; i++)
    {
        stack[i] = 0x00;
    }
}

void initialize_tasks()
{
    for (uint8_t i = 0; i < N_TASKS; i++)
    {
        tasks[i] = add_task(i);
    }
}

void initialize_current_task()
{
    current_task = MAX_NUMBER;
}

void initialize_kernel()
{
    initialize_stack();
    initialize_tasks();
    initialize_current_task();
}