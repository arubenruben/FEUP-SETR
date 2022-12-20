#include "scheduler.h"

volatile int i;

/*
From https://gcc.gnu.org/onlinedocs/gcc/AVR-Function-Attributes.html

naked
This attribute allows the compiler to construct the requisite function
declaration, while allowing the body of the function to be assembly code. The
specified function will not have prologue/epilogue sequences generated by the
compiler. Only basic asm statements can safely be included in naked functions
(see Basic Asm). While using extended asm or a mixture of basic asm and C code
may appear to work, they cannot be depended upon to work reliably and are not
supported.

I think we can call the functions safely and then execute code safely (needs
confirming)
 */
ISR(TIMER1_COMPA_vect, ISR_NAKED)
{
    portSAVE_CONTEXT();
    scheduler_schedule();
    scheduler_dispatch();
}

void scheduler_schedule(void)
{
    for (i = 0; i < n_tasks; i++)
    {
        if (tasks[i].delay != 0)
        {
            tasks[i].delay--;
        }
        else
        {
            tasks[i].state = TASK_STATE_RUNNING;
            tasks[i].delay = tasks[i].period - 1;
        }
    }
}

void scheduler_dispatch(void)
{
    // current_task = idle_task;
    for (i = 0; i < n_tasks; i++)
    {
        if (tasks[i].state == TASK_STATE_RUNNING)
        {
            current_task = &tasks[i];
            break;
        }
    }

    current_task_stack_pointer = &(current_task->stack_pointer);
    portRESTORE_CONTEXT();

    // return to execution of the function
    // PC <- STACK
    asm volatile("reti");
}

void scheduler_yield(void)
{
    portSAVE_CONTEXT();
    current_task->state = TASK_STATE_IDLE;
    scheduler_dispatch();
}

task_t *scheduler_add_task(uint8_t priority, void *(*func)(void *), void *params, uint8_t delay, uint8_t period)
{
    if (n_tasks >= MAX_TASKS)
    {
        return NULL;
    }
    task_t *task = &tasks[n_tasks++];

    task->priority = priority;
    task->state = TASK_STATE_IDLE;

    // SP begins in the END of the stack
    task->stack_pointer = &stack[TASK_STACK_SIZE * n_tasks - 1 - 3];

    task->func = func;
    task->params = params;

    task->delay = delay;
    task->period = period;

    task_stack_init(task);
    return task;
}