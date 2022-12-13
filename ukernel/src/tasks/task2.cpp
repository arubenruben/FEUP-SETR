#include "task.h"
#include "scheduler.h"

void *task_2(void *args)
{
    Serial.println("Running task_t 2");

    while (true)
    {
        Serial.println("Goodbye");

        Serial.flush();
    }

    return NULL;
}