#include "main.h"

volatile unsigned long seconds_counter = 0;
volatile uint8_t number_leds = 0;

void setup()
{
  Serial.begin(BAUD_RATE);
  while (!Serial)
    ;
  Serial.flush();

  leds_init();
  segments_init();
  pinMode(BUZZER_DIO, OUTPUT);
  digitalWrite(BUZZER_DIO, HIGH);

  kernel_init();
  kernel_start();
}

void register_tasks(void)
{
  #define N_TASKS 5
  int i = 0;
  scheduler_add_task(1, task_measure_1, NULL, 0, 100);
  for (i = 0; i < N_TASKS - 2; i++)
    scheduler_add_task(i + 2, task_measure_2, NULL, 0, 100);
  scheduler_add_task(N_TASKS + 2, task_measure_3, NULL, 0, 100);
  // scheduler_add_task(1, task_1, (void *)&seconds_counter, 0, 1000);
  // task_t *task2 = scheduler_add_task(2, task_2, (void *)&number_leds, 0, 150);
  // task_t *task3 = scheduler_add_task(3, task_3, (void *)&number_leds, 0, 150);
  // scheduler_add_task(4, task_4, NULL, 0, 25);
  // scheduler_add_task(0, task_5, NULL, 0, 150);
  // scheduler_add_task(5, task_6, (void *)&seconds_counter, 0, 5);
  // task_t *task7 = scheduler_add_task(10, task_7, NULL, 0, 150);

  // mutex_register_task(&mutexes[0], task2);
  // mutex_register_task(&mutexes[0], task7);
  // mutex_register_task(&mutexes[1], task2);
  // mutex_register_task(&mutexes[1], task3);
}

void loop()
{
  // Do Nothing
}