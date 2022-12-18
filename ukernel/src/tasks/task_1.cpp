#include "scheduler.h"
#include "Arduino.h"

void *task_1(void *args)
{
    while (true)
    {
        digitalWrite(D1, !digitalRead(D1));
        scheduler_yield();
    }

    return NULL;
}