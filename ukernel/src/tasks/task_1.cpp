#include "scheduler.h"
#include "Arduino.h"

/**
 * This Task Receives an Intenger That is a Seconds Counter.
 * Increments the counter in One Unit
 */
void *task_1(void *args)
{
    volatile unsigned long *seconds_counter = (volatile unsigned long *)args;

    unsigned long last_tick = 0;

    while (true)
    {
        unsigned long current_tick = millis();

        if ((current_tick - last_tick) >= 1000)
        {        
            *seconds_counter++;
            Serial.println(*seconds_counter);
        }

        last_tick = current_tick;

        scheduler_yield();
    }

    return NULL;
}