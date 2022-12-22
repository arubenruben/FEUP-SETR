#include "task.h"
#include "scheduler.h"

void fake_task_2()
{
    Serial.println("Task 2");
    Serial.flush();
    digitalWrite(D2, !digitalRead(D2));
}

void true_task_2(volatile uint8_t *number_leds)
{
    switch ((*number_leds))
    {
    case 0:
        digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH);
        break;
    case 1:
        digitalWrite(D1, LOW);

        digitalWrite(D2, HIGH);
        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH);
        break;
    case 2:
        digitalWrite(D1, LOW);
        digitalWrite(D2, LOW);

        digitalWrite(D3, HIGH);
        digitalWrite(D4, HIGH);
        break;
    case 3:
        digitalWrite(D1, LOW);
        digitalWrite(D2, LOW);
        digitalWrite(D3, LOW);

        digitalWrite(D4, HIGH);
        break;
    case 4:
        digitalWrite(D1, LOW);
        digitalWrite(D2, LOW);
        digitalWrite(D3, LOW);
        digitalWrite(D4, LOW);
        break;
    default:
        Serial.println("Unexpected Error in Task 2");
        break;
    }
}

void *task_2(void *args)
{

    volatile uint8_t *number_leds = (volatile uint8_t *)args;

    while (true)
    {
        true_task_2(number_leds);
        // fake_task_2();
        scheduler_yield();
    }
    return NULL;
}