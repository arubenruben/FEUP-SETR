#include "task.h"

void *task_1(void *args)
{
    volatile Task *task = (Task *)args;

    while (true)
    {
        Serial.println("Hello World");

        task->scheduler_yield();
    }

    return NULL;
}