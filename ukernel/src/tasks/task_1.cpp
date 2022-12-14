#include "task.h"

void *task_1(void *args)
{
    params *value = (params *)args;

    while (true)
    {
        Serial.println("Hello World");
        Serial.flush();
        value->scheduler_yield();
    }

    return NULL;
}