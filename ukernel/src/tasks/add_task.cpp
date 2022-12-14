#include "task.h"

task_t add_task(uint8_t priority)
{
    task_t task_to_return;

    task_to_return.priority = priority;

    switch (priority)
    {
    case 0:
        task_to_return.func = task_1;
        break;
    case 1:
        task_to_return.func = task_2;
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }

    return task_to_return;
}