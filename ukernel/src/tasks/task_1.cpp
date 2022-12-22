#include "scheduler.h"
#include "Arduino.h"

void *task_1(void *args)
{
    while (true)
    {
        Serial.println("Task 1");
        Serial.flush();
        digitalWrite(D1, !digitalRead(D1));
        
        
        
        
        scheduler_yield();
    }

    return NULL;
}
