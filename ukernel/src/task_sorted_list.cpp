#include "task_sorted_list.h"

uint8_t task_sorted_list_insert(task_sorted_list_t *list, task_t *task)
{
    uint8_t i;
    for (i = 0; i < list->size; i++)
    {
        if (list->elements[i]->dynamic_priority > task->dynamic_priority)
        {
            for (uint8_t j = list->size; j > i; j--)
            {
                list->elements[j] = list->elements[j - 1];
            }
            break;
        }
    }
    list->elements[i] = task;
    list->size++;
    return i;
}

void task_sorted_list_remove(task_sorted_list_t *list, task_t *task)
{
    for (uint8_t i = 0; i < list->size; i++)
    {
        if (list->elements[i] == task)
        {
            for (uint8_t j = i; j < list->size; j++)
            {
                list->elements[j] = list->elements[j + 1];
                list->size--;
            }
            break;
        }
    }
}