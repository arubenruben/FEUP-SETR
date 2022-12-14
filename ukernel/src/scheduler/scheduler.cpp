#include "scheduler.h"


void scheduler_tick_handler()
{
    if (current_task != MAX_NUMBER)
    {
        portSAVE_CONTEXT();
    }

    scheduler_schedule();
    scheduler_dispatch();

    if (current_task != MAX_NUMBER)
    {
        current_task_stack_pointer = &tasks[0].stack_pointer;
        portRESTORE_CONTEXT()
    }

    asm volatile("ret");
}

void scheduler_schedule(void)
{
    for (int i = 0; i < N_TASKS; i++)
    {
        if (tasks[i].delay)
            tasks[i].delay--;
        else
        {
            tasks[i].state = TASK_STATE_RUNNING;
            tasks[i].delay = tasks[i].period - 1;
        }
    }
}

void scheduler_dispatch(void)
{
    current_task = MAX_NUMBER;

    // Update the Current Task Variable
    for (int i = 0; i < N_TASKS; i++)
    {
        if (tasks[i].state == TASK_STATE_RUNNING)
        {
            current_task = i;
            return;
        }
    }
}


task_t add_task(uint8_t priority)
{
    task_t task_to_return;

    task_to_return.priority = priority;
    task_to_return.state = TASK_STATE_IDLE;

    task_to_return.stack_pointer = &stack[TASK_STACK_SIZE * (priority + 1) - 1];

    // TODO: Add StackPointer
    switch (priority)
    {
    case 0:
        task_to_return.func = task_1;
        task_to_return.delay = 0;
        task_to_return.period = 5;
        break;
    case 1:
        task_to_return.func = task_2;
        task_to_return.delay = 0;
        task_to_return.period = 6;
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }

    return task_to_return;
}