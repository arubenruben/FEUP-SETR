#include "task.h"
#include "scheduler.h"

void fake_task_3()
{
    Serial.println("Task 3");
    Serial.flush();
    digitalWrite(D3, !digitalRead(D3));
}

void true_task_3(volatile uint8_t *number_leds)
{
    /**
     * TODO: Block Mutex
     *
     */

    (*number_leds)++;
    (*number_leds) = (*number_leds) % NUM_MAX_LEDS;
}

void *task_3(void *args)
{
    volatile uint8_t *number_leds = (volatile uint8_t *)args;

    while (true)
    {
        // fake_task_3();
        true_task_3(number_leds);
        scheduler_yield();
    }
}