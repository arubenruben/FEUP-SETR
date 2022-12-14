#include "kernel.h"

volatile uint16_t stack[STACK_SIZE];

task_t tasks[1];

volatile uint16_t *volatile cur_TCB;

volatile uint16_t *volatile cur_BOTTOM;

ISR(TIMER1_COMPA_vect, ISR_NAKED)
{
    portRESTORE_CONTEXT();

    asm volatile("reti");
}

void init_stack()
{
    for (size_t i = 0; i < STACK_SIZE; i++)
    {
        stack[i] = (uint16_t)0;
    }
}

void init_task()
{
    task_t task;

    task.func = task_1;

    task.stack_pointer = (uint16_t *)&stack[STACK_SIZE - 1];

    init_task_stack(&task);

    tasks[0] = task;
}

void init_stack_pointer()
{
    cur_TCB = tasks[0].stack_pointer;
}

void init_kernel(void)
{
    init_stack();
    init_task();
    init_stack_pointer();
}