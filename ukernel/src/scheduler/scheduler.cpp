#include "scheduler.h"

ISR(TIMER1_COMPA_vect, ISR_NAKED)
{
    if (current_task < MAX_NUMBER)
        SAVE_CONTEXT();

    scheduler_schedule();

    scheduler_dispatch();

    if (current_task < MAX_NUMBER)
        RESTORE_CONTEXT();

    asm volatile("reti");
}

void scheduler_schedule(void)
{
    for (size_t i = 0; i < N_TASKS; i++)
    {

        if (tasks[i].delay > 0)
        {
            tasks[i].delay--;
        }
        else
        {
            /**
             * TODO: This Code Is Different From Campanha Suggestion.
             * Campanha was tasks[i].period-1
             */
            tasks[i].delay = tasks[i].period;
            tasks[i].state = TASK_STATE_RUNNING;
        }
    }
}

void scheduler_dispatch(void)
{
    current_task = MAX_NUMBER;

    for (size_t i = 0; i < N_TASKS; i++)
    {
        if (tasks[i].state == TASK_STATE_RUNNING)
        {
            current_task = i;
            break;
        }
    }

    // stack_pointer = tasks[current_task].stack_pointer;
    stack_pointer = &stack[24];
}

void scheduler_yield(void)
{
}

//---------------------------

task_t add_task(uint8_t priority)
{
    task_t task_to_return;

    task_to_return.priority = priority;

    task_to_return.state = TASK_STATE_IDLE;

    task_to_return.stack_pointer = &(stack[(priority + 1) * TASK_STACK_SIZE - 1]);

    switch (priority)
    {
    case 0:
        task_to_return.func = task_1;
        task_to_return.delay = 0;
        task_to_return.period = 3;
        break;
    case 1:
        // task_to_return.func = task_2;
        task_to_return.delay = 0;
        task_to_return.period = 5;
        break;

    default:
        exit(EXIT_FAILURE);
        break;
    }

    return task_to_return;
}
