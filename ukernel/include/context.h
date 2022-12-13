#pragma once

/**
 * Line 9 and 10 Are Suggested by Joao Costa
 * Credits: FEUP Joao Costa
 * https://github.com/JoaoCostaIFG/SETR/blob/master/uKernel/include/sched/context.h
 *
 */
typedef void stackPtr_t;
extern volatile stackPtr_t *volatile curr_stack;
//

#define SAVE_CONTEXT()                        \
    asm volatile(                             \
        "push r0                        \n\t" \
        "in r0, __SREG__                \n\t" \
        "cli                            \n\t" \
        "in r0, __SREG__                \n\t" \
        "push r0                        \n\t" \
        "push r1                        \n\t" \
        "clr  r1                        \n\t" \
        "push r2                        \n\t" \
        "push r2                        \n\t" \
        "push r3                        \n\t" \
        "push r4                        \n\t" \
        "push r5                        \n\t" \
        "push r6                        \n\t" \
        "push r7                        \n\t" \
        "push r8                        \n\t" \
        "push r9                        \n\t" \
        "push r10                       \n\t" \
        "push r11                       \n\t" \
        "push r12                       \n\t" \
        "push r13                       \n\t" \
        "push r14                       \n\t" \
        "push r15                       \n\t" \
        "push r16                       \n\t" \
        "push r17                       \n\t" \
        "push r18                       \n\t" \
        "push r19                       \n\t" \
        "push r20                       \n\t" \
        "push r21                       \n\t" \
        "push r22                       \n\t" \
        "push r23                       \n\t" \
        "push r24                       \n\t" \
        "push r25                       \n\t" \
        "push r26                       \n\t" \
        "push r27                       \n\t" \
        "push r28                       \n\t" \
        "push r29                       \n\t" \
        "push r30                       \n\t" \
        "push r31                       \n\t" \
        "lds r26, curr_stack            \n\t" \
        "lds r27, curr_stack + 1        \n\t" \
        "in r0, __SP_L__                \n\t" \
        "st x+, r0                      \n\t" \
        "in r0, __SP_H__                \n\t" \
        "st x+, r0                      \n\t");