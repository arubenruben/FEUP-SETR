#include "task.h"
#include "scheduler.h"
/**
 * @brief Modifies the number of leds on by task 2
 * 
 * It shares a mutex with task 2 to avoid race conditions when modifing this variable
 * 
 * @param args 
 * @return void* 
 */
void *task_3(void *args)
{
    volatile uint8_t *number_leds = (volatile uint8_t *)args;

    while (true)
    {
        mutex_lock(&mutexes[1]);
        (*number_leds)++;
        (*number_leds) = (*number_leds) % NUM_MAX_LEDS;
        mutex_unlock(&mutexes[1]);

        scheduler_yield();
    }
}