#pragma once

#include <Arduino.h>
#include <errno.h>
#include "constants.h"

typedef struct struct_generic_params
{
    void (*scheduler_yield)(void);
    uint8_t dummy_num;

} params;

//IPCP Ellon Burns programing languages for RTS

typedef struct struct_task
{
    uint8_t priority;
    uint8_t delay;
    uint8_t period;

    uint8_t state;

    volatile uint8_t *stack_pointer;

    void *(*func)(void *);

    params par_value;

} task_t;


task_t add_task(uint8_t priority);

void init_task_bytes(task_t *task);

void *task_1(void *args);

void *task_2(void *args);