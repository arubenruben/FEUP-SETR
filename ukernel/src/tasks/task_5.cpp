#include "task.h"
#include "scheduler.h"

/**
 * @brief When Button A2 is pressed, the execution stops. Task 5 has the bigger priority
 * 
 * @param args 
 * @return void* 
 */
void *task_5(void *args)
{
    while (true)
    {
        if (!digitalRead(A2))
        {
            while (!digitalRead(A2));
        }
        scheduler_yield();
    }
}