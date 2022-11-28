
#include "handler.h"

void run_t1()
{
    static int count = 0;
    // Update Count

    task_1((void *)count);

    count++;
    count = count % MAX_NUMBER;
}

void run_t2()
{
    static int number_leds = 2;

    task_2((void *)number_leds);
}

void tick_handler()
{
    // run_t1()
    run_t2();

    return;
}
