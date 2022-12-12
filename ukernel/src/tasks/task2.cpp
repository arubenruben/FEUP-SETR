#include "task.h"

void *task_2(void *args)
{
    while (true)
    {
        Serial.println("Goodbye");
    }

    return NULL;
}