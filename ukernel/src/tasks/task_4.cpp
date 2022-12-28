#include "task.h"
#include "scheduler.h"

void true_task_4()
{
    digitalWrite(BUZZER_DIO, digitalRead(A1));
}

void *task_4(void *args)
{
    while (true)
    {
        true_task_4();
        scheduler_yield();
    }
}