#include "tasks.h"

void task_1(void)
{
    noInterrupts();

    while (true)
    {
        Serial.println("Hello World");
    }
}