#include "task.h"
#include "scheduler.h"


void true_task_3(volatile uint8_t *number_leds)
{
    mutex_lock(&mutexes[1]);
    (*number_leds)++;
    (*number_leds) = (*number_leds) % NUM_MAX_LEDS;
    mutex_unlock(&mutexes[1]);
}

void *task_3(void *args)
{
    volatile uint8_t *number_leds = (volatile uint8_t *)args;

    while (true)
    {
        true_task_3(number_leds);
        scheduler_yield();
    }
}