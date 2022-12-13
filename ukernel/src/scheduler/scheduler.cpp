#include "scheduler.h"

void scheduler_tick_handler(void)
{
    scheduler_schedule();
    scheduler_dispatch();
}

void scheduler_schedule(void)
{
    for (size_t i = 0; i < N_TASKS; i++)
    {

        if (tasks[i].delay > 0)
        {
            tasks[i].delay--;
        }
        else
        {
            /**
             * TODO: This Code Is Different From Campanha Suggestion.
             * Campanha was tasks[i].period-1
             */
            tasks[i].delay = tasks[i].period;
            tasks[i].state = TASK_STATE_RUNNING;
        }
    }
}

void scheduler_dispatch(void)
{
    current_task = MAX_NUMBER;

    for (size_t i = 0; i < N_TASKS; i++)
    {
        if (tasks[i].state == TASK_STATE_RUNNING)
        {
            current_task = i;
            break;
        }
    }

    if (current_task == MAX_NUMBER)
        return;

    if (tasks[current_task].init == 0)
    {
        Serial.println("Apos Condicao");
        Serial.println(tasks[current_task].init);
        Serial.println("---------------");
        /**
         * TODO: DANGER DANGER DANGER
         * THIS IS NOT A GOOD PLACE TO PLACE INITIALIZATIONS
         */
        tasks[current_task].init = 1;

        tasks[current_task].task_user_level_stack_pointer = &stack[tasks[current_task].priority * TASK_STACK_SIZE];
        tasks[current_task].scheduler_yield = scheduler_yield;

        Serial.println("Antes");
        print_task(tasks[current_task]);
        /**
         * DANGER DANGER DANGER
         * FUNC CALL MUST BE THE LAST LINE EXECUTED.
         * Consider .func() as a Return for Scheduler Dispatch
         */
        (tasks[current_task].func)(&tasks[current_task]);
    }
    else
    {
        // TODO:Restore Context
    }
}

void scheduler_yield(void)
{
    /**
     * Curr_Stack is Used inside context.h as extern variable embedded in the ASM Code as The Reference Wher
     *
     */
    curr_stack = tasks[current_task].task_user_level_stack_pointer;
    SAVE_CONTEXT();

    tasks[current_task].state = TASK_STATE_IDLE;
    scheduler_dispatch();
}
