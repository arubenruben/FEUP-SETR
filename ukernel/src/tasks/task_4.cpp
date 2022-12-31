#include "task.h"
#include "scheduler.h"

/**
 * @brief When button A1 is pressed it triggers the Arduino Buzzer
 * 
 * @param args 
 * @return void* 
 */
void *task_4(void *args)
{
    while (true)
    {
        digitalWrite(BUZZER_DIO, digitalRead(A1));

        scheduler_yield();
    }
}