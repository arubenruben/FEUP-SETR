#include "task.h"
#include "scheduler.h"

void fake_task_4()
{
    Serial.println("Task 4");
    Serial.flush();
    digitalWrite(D4, !digitalRead(D4));
}

void true_task_4()
{   
    digitalWrite(BUZZER_DIO, digitalRead(A1));
}

void *task_4(void *args)
{
    while (true)
    {
        //fake_task_4();
        true_task_4();
        scheduler_yield();
    }
}