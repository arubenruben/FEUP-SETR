#include "task.h"

void *task_1(void *args)
{
    while (true)
    {
        Serial.println("Hello World");
    }

    return NULL;
}