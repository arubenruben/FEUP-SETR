#include "kernel.h"

uint8_t stack[TASK_STACK_SIZE * MAX_TASKS];

task_t tasks[MAX_TASKS];
uint8_t n_tasks = 0;
task_t *current_task;
mutex_t mutexes[N_MUTEXES];
volatile void *volatile current_task_stack_pointer = NULL;

extern void register_tasks();

void kernel_init(void)
{
    memset(&stack, 0, MAX_TASKS * TASK_STACK_SIZE * sizeof(uint8_t));
    for (int i = 0; i < MAX_TASKS; i++)
    {
        stack[i * TASK_STACK_SIZE] = stack[(i + 1) * TASK_STACK_SIZE - 1] = 0xf8;
        stack[i * TASK_STACK_SIZE + 1] = stack[(i + 1) * TASK_STACK_SIZE - 2] = 0xf7;
        stack[i * TASK_STACK_SIZE + 2] = stack[(i + 1) * TASK_STACK_SIZE - 3] = 0xf6;
    }
    for (int i = 0; i < N_MUTEXES; i++) {
        mutex_init(&mutexes[i]);
    }
    register_tasks();
    timer_init(1000 / DEFAULT_PERIOD);
}

void kernel_start(void)
{
    scheduler_schedule();
    scheduler_dispatch();
}
task_sorted_list_t running_tasks;