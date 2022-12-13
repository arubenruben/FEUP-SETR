#include "task.h"
#include "scheduler.h"

void task_1(void)
{
    Serial.println("Running task_t 1");

    while (true)
    {
        Serial.println("Hello World");

        Serial.flush();
    }

}