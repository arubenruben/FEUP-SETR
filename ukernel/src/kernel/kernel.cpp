#include "kernel.h"

uint8_t stack[TASK_STACK_SIZE * NUM_TASKS];

task_t tasks[NUM_TASKS];

uint8_t current_task;

volatile uint8_t *volatile current_task_stack_pointer;

void init_stack(void)
{
    for (size_t i = 0; i < NUM_TASKS * TASK_STACK_SIZE; i++)
    {
        stack[i] = (uint8_t)0;
    }
}

void init_tasks(void)
{
    for (size_t i = 0; i < NUM_TASKS; i++)
    {
        tasks[i] = add_task(i);

        init_task_bytes(&tasks[i]);
    }
}

void init_current_task()
{
    current_task = MAX_NUMBER;
}

void init_global_stack_pointer()
{
    current_task_stack_pointer = NULL;
}

void init_kernel(void)
{
    init_stack();
    init_tasks();
    init_current_task();
    init_global_stack_pointer();
}