#include "kernel.h"

task_t tasks[N_TASKS];

uint8_t stack[N_TASKS * TASK_STACK_SIZE];

volatile uint8_t current_task;

volatile void *volatile stack_pointer;

void initialize_stack()
{
    for (size_t i = 0; i < N_TASKS * TASK_STACK_SIZE; i++)
    {
        stack[i] = (uint8_t)0;
    }
}

void initialize_tasks()
{
    for (uint8_t i = 0; i < N_TASKS; i++)
    {
        tasks[i] = add_task(i);

        initialize_task_stack_bytes(&tasks[i]);
    }
}

void initialize_current_task()
{
    current_task = MAX_NUMBER;
}

void initialize_kernel()
{
    initialize_stack();
    initialize_tasks();
    initialize_current_task();
}

//--------------------------
void print_all_stack()
{
    for (size_t i = 0; i < N_TASKS * TASK_STACK_SIZE; i++)
    {
        Serial.print(i);
        Serial.print("\t");
        Serial.println(stack[i]);

        if (i > 0 && i % (TASK_STACK_SIZE - 1) == 0)
            Serial.println("$$$$$$$$$$$$$$$$$$");
    }
}

void print_stack_task(uint8_t task_to_print)
{
    for (size_t i = TASK_STACK_SIZE * (task_to_print + 1); i < TASK_STACK_SIZE * (task_to_print + 2); i++)
    {
        Serial.println(stack[i]);
    }
}