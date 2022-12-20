#include "scheduler.h"

void *task_2(void *args)
{
    while (true)
    {
        Serial.println("Task 2");
        Serial.flush();
        digitalWrite(D2, !digitalRead(D2));
        scheduler_yield();
    }

    /*Code to perform the actual task (insert this inside while(true))
    switch ((uint8_t)args[0]){
        case 1:
            digitalWrite(D1, !digitalRead(D1));
            break;
        case 2:
            digitalWrite(D1, !digitalRead(D1));
            digitalWrite(D2, !digitalRead(D2));
            break;
        case 3:
            digitalWrite(D1, !digitalRead(D1));
            digitalWrite(D2, !digitalRead(D2));
            digitalWrite(D3, !digitalRead(D3));
            break;
        case 4:
            digitalWrite(D1, !digitalRead(D1));
            digitalWrite(D2, !digitalRead(D2));
            digitalWrite(D3, !digitalRead(D3));
            digitalWrite(D4, !digitalRead(D4));
            break;
        default:
    }
    scheduler_yield();*/
    return NULL;
}