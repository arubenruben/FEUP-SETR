#include "task.h"

/**
 * Done According to FEUP Ricardo Fontao
 * Credits: Ricardo Fontao
 * https://github.com/rfontao/FEUP-SETR/blob/main/kernel/task.cpp
 *
 */

void initialize_task_stack_bytes(task_t *task)
{
    uint16_t usAddress = (uint16_t)task->func;
    *task->stack_pointer = (uint16_t)(usAddress & (uint16_t)0x00ff);
    task->stack_pointer--;

    usAddress >>= 8;
    *task->stack_pointer = (uint16_t)(usAddress & (uint16_t)0x00ff);
    task->stack_pointer--;

    *task->stack_pointer = (uint8_t)0x00; /* R0 */
    task->stack_pointer--;
    /**
     * Assume only the bit 7 of Status Register Is Active
     * Bit 7 is Interrupts Enabled
     * According To: http://www.rjhcoding.com/avr-asm-sreg.php
     *
     */
    *task->stack_pointer = (uint8_t)0x80;
    task->stack_pointer--;

    /* Now the remaining registers.   The compiler expects R1 to be 0. */
    *task->stack_pointer = (uint8_t)0x00; /* R1 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)2; /* R2 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)3; /* R3 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)4; /* R4 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)5; /* R5 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)6; /* R6 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)7; /* R7 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)8; /* R8 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)9; /* R9 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)10; /* R10 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)11; /* R11 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)12; /* R12 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)13; /* R13 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)14; /* R14 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)15; /* R15 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)16; /* R16 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)17; /* R17 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)18; /* R18 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)19; /* R19 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)20; /* R20 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)21; /* R21 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)22; /* R22 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)23; /* R23 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)24; /* R24 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)25; /* R25 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)26; /* R26 X */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)27; /* R27 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)28; /* R28 Y */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)29; /* R29 */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)30; /* R30 Z */
    task->stack_pointer--;
    *task->stack_pointer = (uint8_t)31; /* R31 */
    task->stack_pointer--;
}