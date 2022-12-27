#include "task.h"
#include "scheduler.h"

void fake_task_2()
{
    Serial.println("Task 2");
    Serial.flush();
    digitalWrite(D2, !digitalRead(D2));
}

void true_task_2(volatile uint8_t *number_leds)
{
    mutex_lock(&mutexes[1]);
    mutex_lock(&mutexes[0]);
    digitalWrite(D1, *number_leds < 1);
    digitalWrite(D2, *number_leds < 2);
    digitalWrite(D3, *number_leds < 3);
    digitalWrite(D4, *number_leds < 4);
    mutex_unlock(&mutexes[0]);
    mutex_unlock(&mutexes[1]);
}

void *task_2(void *args)
{

    volatile uint8_t *number_leds = (volatile uint8_t *)args;

    while (true)
    {
        true_task_2(number_leds);
        // fake_task_2();
        scheduler_yield();
    }
    return NULL;
}