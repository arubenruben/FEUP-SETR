#include "task.h"
#include "utils.h"

void *task_1(void *args)
{
    Task *task = (Task *)args;
    
    while (true)
    {
        Serial.println("Durante");
    
        print_task(*task);

        Serial.println("Hello World");

        task->scheduler_yield();
    }

    return NULL;
}