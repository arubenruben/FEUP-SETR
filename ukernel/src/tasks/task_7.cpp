#include "task.h"
#include "scheduler.h"

void *task_7(void * parms)
{
    mutex_t *mutex = &mutexes[0];
    while (1)
    {
        if (!digitalRead(A3))
        {
            // Serial.println("Trying to lock");
            mutex_lock(mutex);
            // Serial.println("locked");

            digitalWrite(D1, HIGH);
            digitalWrite(D2, HIGH);
            digitalWrite(D3, HIGH);
            digitalWrite(D4, HIGH);

            scheduler_yield();
            digitalWrite(D4, LOW);
            scheduler_yield();
            digitalWrite(D3, LOW);
            scheduler_yield();
            digitalWrite(D2, LOW);
            scheduler_yield();
            digitalWrite(D1, LOW);

            scheduler_yield();
            while (digitalRead(A3))
            {
                scheduler_yield();
            }

            mutex_unlock(mutex);;
        }
        scheduler_yield();
    }
}