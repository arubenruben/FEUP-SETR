#include "utils.h"

void print_task(Task task)
{
    Serial.println(task.priority);
    Serial.println(task.init);
    Serial.println("-------");
}