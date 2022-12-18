#include "scheduler.h"

void *task_2(void *args)
{
    while (true)
    {
        // Serial.println("Task 2");
        // Serial.flush();
        digitalWrite(D2, !digitalRead(D2));
        scheduler_yield();
    }

    return NULL;
}