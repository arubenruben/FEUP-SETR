#include "task.h"
#include "scheduler.h"

void true_task_6(byte *seg, volatile unsigned long *seconds_counter)
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
}

void *task_6(void *args)
{
    byte seg = 0;

    volatile unsigned long *seconds_counter = (volatile unsigned long *)args;

    while (true)
    {
        true_task_6(&seg, seconds_counter);
        scheduler_yield();
    }
}