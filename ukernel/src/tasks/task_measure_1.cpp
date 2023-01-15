#include "task.h"
#include "scheduler.h"


void *task_measure_1(void *args)
{
    while (true)
    {
        mutex_lock(&mutexes[0]);
        mutex_unlock(&mutexes[0]);
        scheduler_yield();
    }

    return NULL;
}
