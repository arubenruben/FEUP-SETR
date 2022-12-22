#include "task.h"
#include "scheduler.h"

void fake_task_4()
{
    Serial.println("Task 4");
    //Serial.flush();
}

void true_task_4()
{
}

void *task_4(void *args)
{
    while (true)
    {
        fake_task_4();
        scheduler_yield();
    }
}