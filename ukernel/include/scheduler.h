#pragma once

#include <Arduino.h>
#include "constants.h"


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

void scheduler_dispatch(void);