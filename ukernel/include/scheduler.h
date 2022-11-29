#pragma once

#include <Arduino.h>
#include "constants.h"

typedef struct {
  uint8_t priority;
  uint8_t period;
  uint8_t delay;
  void (*func)(void);
  uint16_t sp;
  uint8_t state;
} task_t;

task_t tasks[N_TASKS];

/**
 * @brief Setup the tasks array and initialize the timer to the desired frequency
 * 
 * @return int -1 if error, 1 if success;
 */
int scheduler_init();

/**
 * @brief Adds a new task to the task array in the first empty position
 * @param func Function with the task's code
 * @param period Tasks period
 * @param delay Start up offset of the first time execution
 * 
 * @return int -1 if error, the priority if success
 */
int scheduler_add_task(void (*func)(void), int period, int delay);

/**
 * @brief 
 * 
 */
void scheduler_schedule(void);

/**
 * @brief 
 * 
 */
void scheduler_yield();