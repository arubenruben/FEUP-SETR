#include "main.h"

volatile unsigned long seconds_counter = 0;
volatile uint8_t number_leds = 0;

void *task_test_mutex(void *args)
{
  mutex_t *mutex = &mutexes[0];
  while (1)
  {
    if (!digitalRead(A3))
    {
      Serial.println("Trying to lock");
      mutex_lock(mutex);
      Serial.println("locked");

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
      while (digitalRead(A3)) {
        scheduler_yield();
      }

      mutex_unlock(mutex);
      Serial.println("unlocked");
    }
    scheduler_yield();
  }
}

void setup()
{
  Serial.begin(BAUD_RATE);
  while (!Serial);
  Serial.flush();
  
  leds_init();
  segments_init();
  pinMode(BUZZER_DIO,OUTPUT);
  digitalWrite(BUZZER_DIO, HIGH);

  kernel_init();
  kernel_start();
}

void register_tasks(void)
{
  scheduler_add_task(1, task_1, (void *)&seconds_counter, 0, 10);
  task_t *task2 = scheduler_add_task(2, task_2, (void *)&number_leds, 0, 30);
  scheduler_add_task(3, task_3, (void *)&number_leds, 0, 30);
  scheduler_add_task(4, task_4, NULL, 0, 5);
  scheduler_add_task(0, task_5, NULL, 0, 30);
  scheduler_add_task(5, task_6, (void *)&seconds_counter, 0, 1);
  task_t *task_test = scheduler_add_task(10, task_test_mutex, NULL, 0, 30);

  scheduler_add_task(MAX_PRIORITY, task_idle, NULL, 0, 1);

  mutex_register_task(&mutexes[0], task2);
  mutex_register_task(&mutexes[0], task_test);
}

void loop()
{
  // Do Nothing
}