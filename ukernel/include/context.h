#pragma once

#include <Arduino.h>

extern volatile void *volatile px_current_TCB;

#define portRESTORE_CONTEXT()              \
    asm volatile(                          \
        "lds  r26, px_current_TCB      \n\t"      \
        "lds  r27, px_current_TCB + 1  \n\t"      \
        "ld   r28, x+                \n\t" \
        "out  __SP_L__, r28          \n\t" \
        "ld   r29, x+                \n\t" \
        "out  __SP_H__, r29          \n\t" \
        "pop  r31                    \n\t" \
        "pop  r30                    \n\t" \
        "pop  r29                    \n\t" \
        "pop  r28                    \n\t" \
        "pop  r27                    \n\t" \
        "pop  r26                    \n\t" \
        "pop  r25                    \n\t" \
        "pop  r24                    \n\t" \
        "pop  r23                    \n\t" \
        "pop  r22                    \n\t" \
        "pop  r21                    \n\t" \
        "pop  r20                    \n\t" \
        "pop  r19                    \n\t" \
        "pop  r18                    \n\t" \
        "pop  r17                    \n\t" \
        "pop  r16                    \n\t" \
        "pop  r15                    \n\t" \
        "pop  r14                    \n\t" \
        "pop  r13                    \n\t" \
        "pop  r12                    \n\t" \
        "pop  r11                    \n\t" \
        "pop  r10                    \n\t" \
        "pop  r9                     \n\t" \
        "pop  r8                     \n\t" \
        "pop  r7                     \n\t" \
        "pop  r6                     \n\t" \
        "pop  r5                     \n\t" \
        "pop  r4                     \n\t" \
        "pop  r3                     \n\t" \
        "pop  r2                     \n\t" \
        "pop  r1                     \n\t" \
        "pop  r0                     \n\t" \
        "out  __SREG__, r0           \n\t" \
        "pop  r0                     \n\t");