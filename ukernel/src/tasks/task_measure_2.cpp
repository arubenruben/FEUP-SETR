#include "task.h"
#include "scheduler.h"


void *task_measure_2(void *args)
{
    while (true)
    {
        // Serial.flush();
        END_MEASURE();
        START_MEASURE();
        scheduler_yield();
    }

    return NULL;
}
