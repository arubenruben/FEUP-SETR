#pragma once

/* -----Save Context-------
    
    P
    
*/
#define SAVE_CONTEXT()                                                  \
asm(""                                                                  \
/*push r0 to the stack to enable placing the status register in it*/    \
"push r0\n\t"                                                           \
/*Place status register in r0*/                                         \
"in r0, __SREG__\n\t"                                                   \
/*push the remaining 31 registers to the stack*/                        \
"push r0\n\t"                                                           \
"push r1\n\t"                                                           \
"push r2\n\t"                                                           \
"push r3\n\t"                                                           \
"push r4\n\t"                                                           \
"push r5\n\t"                                                           \
"push r6\n\t"                                                           \
"push r7\n\t"                                                           \
"push r8\n\t"                                                           \
"push r9\n\t"                                                           \
"push r10\n\t"                                                          \
"push r11\n\t"                                                          \
"push r12\n\t"                                                          \
"push r13\n\t"                                                          \
"push r14\n\t"                                                          \
"push r15\n\t"                                                          \
"push r16\n\t"                                                          \
"push r17\n\t"                                                          \
"push r18\n\t"                                                          \
"push r19\n\t"                                                          \
"push r20\n\t"                                                          \
"push r21\n\t"                                                          \
"push r22\n\t"                                                          \
"push r23\n\t"                                                          \
"push r24\n\t"                                                          \
"push r25\n\t"                                                          \
"push r26\n\t"                                                          \
"push r27\n\t"                                                          \
"push r28\n\t"                                                          \
"push r29\n\t"                                                          \
"push r30\n\t"                                                          \
"push r31\n\t"                                                          \
""                                                                      \
: ""                                                                    \
: "")
 
#define RESTORE_CONTEXT() \
asm("")

#define RESTORE_PC() \
asm("")