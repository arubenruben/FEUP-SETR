#include "task.h"

void *task_2(void *args)
{
    volatile Task *task = (Task *)args;

    while (true)
    {
        Serial.println("Goodbye");

        task->scheduler_yield();
    }

    return NULL;
}