#include "task.h"

void *task_2(void *args)
{
    params *value = (params *)args;

    while (true)
    {
        Serial.println("Goodbye");
        Serial.flush();
        value->scheduler_yield();
    }

    return NULL;
}