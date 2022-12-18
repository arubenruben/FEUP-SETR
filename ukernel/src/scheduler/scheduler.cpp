#include "scheduler.h"


ISR(TIMER1_COMPA_vect, ISR_NAKED)
{
    portSAVE_CONTEXT();

    scheduler_schedule();
    scheduler_dispatch();
}

void scheduler_schedule(void)
{
    for (int i = 0; i < N_TASKS; i++)
    {
        if (tasks[i].delay)
            tasks[i].delay--;
        else
        {
            tasks[i].state = TASK_STATE_RUNNING;
            tasks[i].delay = tasks[i].period - 1;
        }
    }
}

void scheduler_dispatch(void)
{
    current_task = MAX_NUMBER;

    // Update the Current Task Variable
    for (int i = 0; i < N_TASKS; i++)
    {
        if (tasks[i].state == TASK_STATE_RUNNING)
        {
            current_task = i;
            break;
        }
    }

    current_task_stack_pointer = &tasks[current_task].stack_pointer;
    portRESTORE_CONTEXT();

    // return to execution of the function
    // PC <- STACK
    asm volatile("ret");
}


void scheduler_yield_save_context(void)
{
    portSAVE_CONTEXT();

    scheduler_schedule();
    scheduler_dispatch();
}

extern volatile void *volatile yield_func = &scheduler_yield_save_context;

/**
 * Dont Call Dispatcher Here. Wait For the Tick to Do That Logic
 */
void scheduler_yield(void)
{
    tasks[current_task].state = TASK_STATE_IDLE;

    asm volatile ("CALL yield_func");

    return;
}

//-----------------
task_t add_task(uint8_t priority)
{
    task_t task_to_return;

    task_to_return.priority = priority;
    task_to_return.state = TASK_STATE_IDLE;

    task_to_return.stack_pointer = &stack[TASK_STACK_SIZE * (priority + 1) - 1];

    // TODO: Add StackPointer
    switch (priority)
    {
    case 0:

        task_to_return.par_value.scheduler_yield = scheduler_yield;
        task_to_return.par_value.dummy_num = 20;

        task_to_return.func = task_1;
        task_to_return.delay = 0;
        task_to_return.period = 20;

        break;
    case 1:
        task_to_return.par_value.scheduler_yield = scheduler_yield;
        task_to_return.par_value.dummy_num = 20;

        task_to_return.func = task_2;
        task_to_return.delay = 0;
        task_to_return.period = 20;

        break;
    default:
        exit(EXIT_FAILURE);
        break;
    }

    return task_to_return;
}