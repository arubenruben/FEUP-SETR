#include "task.h"
#include "scheduler.h"


void true_task_5()
{
    if(!digitalRead(A2)){
        while(!digitalRead(A2));
    }
}

void *task_5(void *args)
{
    while (true)
    {
        true_task_5();
        scheduler_yield();
    }
}