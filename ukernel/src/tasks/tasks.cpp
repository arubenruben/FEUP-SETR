#include "tasks.h"

void init_task_stack(task_t *task)
{
    uint16_t usAddress = (uint16_t)task->stack_pointer;
    *task->stack_pointer = (uint16_t)(usAddress & (uint16_t)0x00ff);
    task->stack_pointer--;

    usAddress >>= 8;
    *task->stack_pointer = (uint16_t)(usAddress & (uint16_t)0x00ff);
    task->stack_pointer--;

    *task->stack_pointer = (uint16_t)0x00; /* R0 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x80;
    task->stack_pointer--;

    /* Now the remaining registers.   The compiler expects R1 to be 0. */
    *task->stack_pointer = (uint16_t)0x00; /* R1 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x02; /* R2 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x03; /* R3 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x04; /* R4 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x05; /* R5 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x06; /* R6 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x07; /* R7 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x08; /* R8 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x09; /* R9 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x10; /* R10 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x11; /* R11 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x12; /* R12 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x13; /* R13 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x14; /* R14 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x15; /* R15 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x16; /* R16 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x17; /* R17 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x18; /* R18 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x19; /* R19 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x20; /* R20 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x21; /* R21 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x22; /* R22 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x23; /* R23 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x24; /* R24 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x25; /* R25 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x26; /* R26 X */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x27; /* R27 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x28; /* R28 Y */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x29; /* R29 */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x30; /* R30 Z */
    task->stack_pointer--;
    *task->stack_pointer = (uint16_t)0x031; /* R31 */
    task->stack_pointer--;
}