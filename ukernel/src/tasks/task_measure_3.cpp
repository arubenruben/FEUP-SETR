#include "task.h"
#include "scheduler.h"


void *task_measure_3(void *args)
{
    while (true)
    {
        END_MEASURE();
        scheduler_yield();
    }

    return NULL;
}
