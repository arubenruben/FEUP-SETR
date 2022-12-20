#include "mutex.h"

extern task_t *current_task;
extern task_sorted_list_t running_tasks;

extern void mutex_yield(void) __attribute__((naked));

void mutex_init(mutex_t *mutex)
{
    //Something to define ceiling here

    //Safeguard
    mutex->locked = MUTEX_UNLOCK;
    return;
}

void mutex_lock(mutex_t *mutex)
{
    noInterrupts();
    if (mutex->locked == MUTEX_LOCK)
    {
        current_task->state = TASK_STATE_BLOCKED;
        task_sorted_list_insert(&mutex->blocked_tasks, current_task);
        mutex_yield();
    }

    mutex->locked = MUTEX_LOCK;
    current_task->dynamic_priority = mutex->ceiling;
    interrupts();
}

void mutex_unlock(mutex_t *mutex)
{
    noInterrupts();
    if(mutex->locked == MUTEX_LOCK)
    {
        mutex->locked = MUTEX_UNLOCK;
        current_task->dynamic_priority = current_task->static_priority;
        
        task_t *next_task = mutex->blocked_tasks.elements[0];
        task_sorted_list_remove(&mutex->blocked_tasks, next_task);
        task_sorted_list_insert(&running_tasks, next_task);
    }
    interrupts();
}