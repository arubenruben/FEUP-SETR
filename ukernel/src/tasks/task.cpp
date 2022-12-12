#include "task.h"

Task add_task(uint8_t priority)
{
    Task task_to_return;

    task_to_return.priority = priority;
    task_to_return.state = TASK_STATE_NOT_INIT;

    switch (priority)
    {
    case 1:
        task_to_return.func = task_1;
        break;
    case 2:
        task_to_return.func = task_2;
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }

    return task_to_return;
}