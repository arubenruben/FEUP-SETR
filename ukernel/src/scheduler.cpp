#include "scheduler.h"

void scheduler_tick_handler(void)
{
    scheduler_schedule();
    scheduler_dispatch();
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
    for (size_t i = 0; i < N_TASKS; i++)
    {
        if (tasks[i].state == TASK_STATE_RUNNING)
        {
            current_task = i;
            break;
        }
    }

    if (tasks[current_task].init == false)
    {
        (tasks[current_task].func)(NULL);
    }
    else
    {
        // TODO:Restore Context
    }
}

void scheduler_yield(void)
{
    // TODO: Pass To Task Pointer to Scheduler Yield
}
