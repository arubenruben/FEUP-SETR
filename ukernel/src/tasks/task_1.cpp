#include "task.h"
#include "scheduler.h"

void true_task_1(volatile unsigned long *seconds_counter, unsigned long *last_tick)
{
    (*seconds_counter)++;
}

/**
 * This Task Receives an Intenger That is a Seconds Counter.
 * Increments the counter in One Unit
 */
void *task_1(void *args)
{
    volatile unsigned long *seconds_counter = (volatile unsigned long *)args;

    unsigned long last_tick = 0;

    while (true)
    {
        true_task_1(seconds_counter, &last_tick);
        scheduler_yield();
    }

    return NULL;
}
