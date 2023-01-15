#include "task.h"
#include "scheduler.h"
/**
 * @brief This function accepts an unsigned long and displays it in the 7 Segments LCD
 * 
 * In the context of this project it is receiving the seconds counter. Working cooperatibly with task 1
 * 
 * @param args 
 * @return void* 
 */
void *task_6(void *args)
{
    volatile unsigned long *seconds_counter = (volatile unsigned long *)args;

    while (true)
    {
        uint8_t units = (*seconds_counter) % 10;
        uint8_t tens = ((*seconds_counter) / 10) % 10;
        uint8_t hundreds = ((*seconds_counter) / 100) % 10;
        uint8_t thousands = ((*seconds_counter) / 1000) % 10;

        WriteNumberToSegment(3, units);
        scheduler_yield();
        WriteNumberToSegment(2, tens);
        scheduler_yield();
        WriteNumberToSegment(1, hundreds);
        scheduler_yield();
        WriteNumberToSegment(0, thousands);

        scheduler_yield();
    }
}