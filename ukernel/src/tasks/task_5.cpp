#include "task.h"
#include "scheduler.h"

void fake_task_5()
{
    Serial.println("Task 5");
    //Serial.flush();
}

void true_task_5()
{
}

void *task_5(void *args)
{
    while (true)
    {
        fake_task_5();
        scheduler_yield();
    }
}