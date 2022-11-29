#include "tasks.h"
#include "leds.h"

void *task_2(void *args)
{
    // TODO: Change this. It will be a shared resourced
    int number_leds = (int)args;
    Serial.write("Teste");

    while (true)
    {
        if (number_leds > 0)
        {
            digitalWrite(d1, !digitalRead(d1));            
        }
        if (number_leds > 1)
        {
            digitalWrite(d2, !digitalRead(d2));            
        }
        if (number_leds > 2)
        {
            digitalWrite(d3, !digitalRead(d3));            
        }
        if (number_leds > 3)
        {
            digitalWrite(d4, !digitalRead(d4));            
        }
    }

    return NULL;
}