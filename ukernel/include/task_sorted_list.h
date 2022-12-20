#pragma once

#include "constants.h"
#include "task.h"
#include "Arduino.h"

typedef struct
{
    task_t *elements[MAX_TASKS];
    uint8_t size;
} task_sorted_list_t;

uint8_t task_sorted_list_insert(task_sorted_list_t *list, task_t *task);

void task_sorted_list_remove(task_sorted_list_t *list, task_t *task);