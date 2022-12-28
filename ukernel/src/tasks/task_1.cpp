#include "task.h"
#include "scheduler.h"



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
        (*seconds_counter)++;
        
        scheduler_yield();
    }

    return NULL;
}
