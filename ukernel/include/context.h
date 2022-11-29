#pragma once

#define SAVE_CONTEXT() \
asm("PUSH r0\n\t" \
"PUSH r1\n\t")

#define RESTORE_CONTEXT() \
asm("")

#define RESTORE_PC() \
asm("")