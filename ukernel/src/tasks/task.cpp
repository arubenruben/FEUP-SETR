#include "task.h"

Task add_task(uint8_t priority)
{
    Task task_to_return;

    task_to_return.priority = priority;
    task_to_return.state = TASK_STATE_IDLE;
    task_to_return.init = false;

    switch (priority)
    {
    case 1:
        task_to_return.func = task_1;
        task_to_return.delay = 0;
        task_to_return.period = 3;
        break;
    case 2:
        task_to_return.func = task_2;
        task_to_return.delay = 0;
        task_to_return.period = 5;
        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }

    return task_to_return;
}