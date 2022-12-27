#include "task.h"
#include "scheduler.h"

#define DEBUG

void fake_task_1()
{
    Serial.println("Task 1");
    Serial.flush();
    digitalWrite(D1, !digitalRead(D1));
}

void true_task_1(volatile unsigned long *seconds_counter, unsigned long *last_tick)
{
    // unsigned long current_tick = millis();

    // if ((current_tick - (*last_tick)) >= 1000)
    // {
    (*seconds_counter)++;

#ifdef DEBUG
        Serial.println((*seconds_counter));
#endif
    //     (*last_tick) = current_tick;
    // }
}

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
        //fake_task_1();

        true_task_1(seconds_counter, &last_tick);

        scheduler_yield();
    }

    return NULL;
}
