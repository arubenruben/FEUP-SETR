#include "task.h"
#include "scheduler.h"

/**
 * @brief This Task is responsible to periodically light the number of leds defined in "number_leds"
 * 
 * "number_leds" is a shared resource with task 3, therefore the access to the value is protected by mutex.
 * The access to the leds hardware is also protected by mutex since it is shared with task 7.
 * 
 * @param args 
 * @return void* args -> Reference to number_leds variable
 */
void *task_2(void *args)
{

    volatile uint8_t *number_leds = (volatile uint8_t *)args;

    while (true)
    {
        mutex_lock(&mutexes[1]);
        mutex_lock(&mutexes[0]);

        digitalWrite(D1, *number_leds < 1);
        digitalWrite(D2, *number_leds < 2);
        digitalWrite(D3, *number_leds < 3);
        digitalWrite(D4, *number_leds < 4);
        mutex_unlock(&mutexes[0]);
        mutex_unlock(&mutexes[1]);

        scheduler_yield();
    }
    return NULL;
}