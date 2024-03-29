#include "mutex.h"

extern task_t *current_task;
extern task_sorted_list_t running_tasks;

extern void mutex_yield(void) __attribute__((naked));

void mutex_init(mutex_t *mutex)
{
    mutex->locked = MUTEX_UNLOCKED;
    mutex->ceiling = MAX_PRIORITY;
}

void mutex_register_task(mutex_t *mutex, task_t *task)
{
    if (task->static_priority < mutex->ceiling)
    {
        mutex->ceiling = task->static_priority;
    }
}

void mutex_lock(mutex_t *mutex)
{
    noInterrupts();
    if (mutex->locked)
    {
        current_task->state = TASK_STATE_BLOCKED;
        task_sorted_list_insert(&mutex->blocked_tasks, current_task);
        task_sorted_list_remove(&running_tasks, current_task);
        mutex_yield();
    }

    mutex->locked = MUTEX_LOCKED;
    current_task->dynamic_priority = mutex->ceiling;
    interrupts();
}

void mutex_unlock(mutex_t *mutex)
{
    START_MEASURE();
    noInterrupts();
    if(mutex->locked)
    {
        mutex->locked = MUTEX_UNLOCKED;
        current_task->dynamic_priority = current_task->static_priority;
        
        if (mutex->blocked_tasks.size > 0) {
            task_t *next_task = mutex->blocked_tasks.elements[0];
            next_task->state = TASK_STATE_RUNNING;
            task_sorted_list_remove(&mutex->blocked_tasks, next_task);
            task_sorted_list_insert(&running_tasks, next_task);
            mutex_yield();
        }
    }
    interrupts();
    END_MEASURE();
}