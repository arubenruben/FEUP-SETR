#pragma once
#include <Arduino.h>
#include "constants.h"
#include "task.h"
#include "task_sorted_list.h"

typedef struct _mutex_t
{
    uint8_t ceiling;
    uint8_t locked;
    task_sorted_list_t blocked_tasks;
} mutex_t;


void mutex_init(mutex_t *mutex);

void mutex_lock(mutex_t *mutex, task_t *task);

void mutex_unlock(mutex_t *mutex, task_t *task);