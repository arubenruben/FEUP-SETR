#include <scheduler.h>
#include "timer.h"
#include "context.h"

#define TASK_STATE_NOT_INIT 0
#define TASK_STATE_IDLE 1
#define TASK_STATE_RUNNING 2

typedef struct {
  uint8_t priority;
  uint8_t period;
  uint8_t delay;
  void (*func)(void);
  uint16_t sp;
  uint8_t state;
} task_t;

task_t tasks[N_TASKS];
uint16_t current_task;

void scheduler_tick_handler(void)
{
    SAVE_CONTEXT();
    scheduler_schedule();
    scheduler_dispatch();
}

int scheduler_init(void)
{
    for (int i = 0; i < N_TASKS; i++)
    {
        tasks[i] = {};
    }

    timer_init(TICK_RATE, scheduler_tick_handler);
    return 1;
}

int scheduler_add_task(void (*func)(void), int period, int delay)
{
    for (int i = 0; i < N_TASKS; i++)
    {
        if (tasks[i].func == 0)
        {
            tasks[i].delay = delay;
            tasks[i].period = period;
            tasks[i].func = func;
            tasks[i].priority = i;
            tasks[i].state = TASK_STATE_NOT_INIT;
            return i;
        }
    }
    return -1;
}

void scheduler_schedule(void)
{
    for (int i = 0; i < N_TASKS; i++)
    {
        if (tasks[i].func)
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
}

void scheduler_yield(void)
{
    //Context switch«
    SAVE_CONTEXT();
    tasks[current_task].state = TASK_STATE_IDLE;
    scheduler_dispatch();

}

void scheduler_dispatch(void)
{
    //Update the Current Task Variable
    for (int i = 0; i < N_TASKS; i++)
    {
        if (tasks[i].func && tasks[i].state == TASK_STATE_RUNNING)
        {
            current_task = i;
            break;
        }
    }

    if (tasks[current_task].state == TASK_STATE_NOT_INIT)
    {
        (tasks[current_task].func)();
    }
    else
    {
        RESTORE_CONTEXT();
        interrupts();
        // Set the PC
    }

}
