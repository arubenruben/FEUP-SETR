#include "tasks.h"

void *task_1(void *args)
{
    static int seconds_counter = 0;

    while (true)
    {
        seconds_counter++;
        scheduler_yield();
    }

    return NULL;
}