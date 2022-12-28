#include "Arduino.h"

void *task_idle(void *args)
{
    while (true)
        ;

    return 0;
}