#include "task.h"

void *task_idle(void *args)
{
    while (true){
        add_measure(micros());
    }
        

    return 0;
}