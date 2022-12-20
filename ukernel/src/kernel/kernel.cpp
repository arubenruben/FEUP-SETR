#include "kernel.h"

uint8_t stack[TASK_STACK_SIZE * MAX_TASKS];
task_t tasks[MAX_TASKS];
uint8_t n_tasks = 0;
task_t volatile *current_task;
task_t volatile *idle_task;
volatile void *volatile current_task_stack_pointer = NULL;

volatile unsigned long seconds_counter = 0;

void register_tasks(void)
{
    scheduler_add_task(0, task_1, (void *)&seconds_counter, 0, 10);
    scheduler_add_task(1, task_2, NULL, 0, 1);

    idle_task = scheduler_add_task(256, task_idle, NULL, 0, 1);
}

void kernel_init(void)
{
    memset(&stack, 0, MAX_TASKS * TASK_STACK_SIZE * sizeof(uint8_t));
    for (int i = 0; i < MAX_TASKS; i++)
    {
        stack[i * TASK_STACK_SIZE] = stack[(i + 1) * TASK_STACK_SIZE - 1] = 0xf8;
        stack[i * TASK_STACK_SIZE + 1] = stack[(i + 1) * TASK_STACK_SIZE - 2] = 0xf7;
        stack[i * TASK_STACK_SIZE + 2] = stack[(i + 1) * TASK_STACK_SIZE - 3] = 0xf6;
    }

    register_tasks();
    timer_init(DEFAULT_FREQ);
}

void kernel_start(void)
{
    scheduler_schedule();
    scheduler_dispatch();
}