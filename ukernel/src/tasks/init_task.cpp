#include "task.h"

void push_stack(task_t *task, uint8_t value)
{
    *(task->stack_pointer) = value;
    (task->stack_pointer)--;
}

void task_stack_init(task_t *task)
{
    uint16_t func_addr = (uint16_t) task->func;

    push_stack(task, (uint8_t) func_addr); // Push lower func addr byte 
    push_stack(task, (uint8_t) (func_addr >> 8)); // Push upper func addr byte

    push_stack(task, (uint8_t) 0); // R0

    // SREG with "Bit 7: Global Interrupt Enable" set to 1
    // Refer to http://www.rjhcoding.com/avr-asm-sreg.php
    push_stack(task, (uint8_t) 0x80);

    push_stack(task, (uint8_t) 0); // R1 is assumed to be 1

    for (int i = 2; i <= 23; i++) // R2 -> R23
    {
        push_stack(task, (uint8_t) i);
    }
                            
    uint16_t params_addr = (uint16_t) task->params;

    // R24->R25 hold the params struct addr 
    push_stack(task, (uint8_t) params_addr); // Push lower params addr byte 
    push_stack(task, (uint8_t) (params_addr >> 8)); // Push upper params addr byte

    for (int i = 26; i <= 31; i++) // R26 -> R31
    {
        push_stack(task, (uint8_t) i);
    }
}