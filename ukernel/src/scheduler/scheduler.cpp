#include "scheduler.h"

void scheduler_tick_handler()
{
    Serial.println("Tick");

    asm volatile("ret");
}
