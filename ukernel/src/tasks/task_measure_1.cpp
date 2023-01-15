#include "task.h"
#include "scheduler.h"


void *task_measure_1(void *args)
{
    while (true)
    {
        START_MEASURE();
        scheduler_yield();
    }

    return NULL;
}
