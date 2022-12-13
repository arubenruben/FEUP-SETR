#include "kernel.h"

task_t tasks[N_TASKS];

volatile uint8_t stack[N_TASKS * TASK_STACK_SIZE];

volatile uint8_t current_task;

volatile void *volatile stack_pointer;

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

        volatile uint8_t *tmp_stack_pointer = tasks[i].stack_pointer;

        initialize_task_stack_bytes(&tasks[i]);

        /**
         * TODO: Understand If this is Correct
         * It Could be The High or the Low Address
         * Ensure Correctness
         *
         */

        tasks[i].stack_pointer = tmp_stack_pointer;
    }
}

void initialize_current_task()
{
    current_task = MAX_NUMBER;
}

void initialize_kernel()
{
    initialize_stack();
    initialize_current_task();
    initialize_tasks();
}