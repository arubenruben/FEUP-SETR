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
        
    }
}

void scheduler_dispatch(void)
{
}

void scheduler_yield(void)
{
}
