#include "tasks.h"

void *task_6(void *args)
{
    static byte seg = 0;

    int number_to_display = (int)args;

    while (true)
    {
        switch (seg)
        {
        case 0:
            WriteNumberToSegment(3, number_to_display % 10);
            seg = 1;
            break;

        case 1:
            WriteNumberToSegment(2, (number_to_display / 10) % 10);
            seg = 2;
            break;

        case 2:
            WriteNumberToSegment(1, (number_to_display / 100) % 10);
            seg = 3;
            break;

        case 3:
            WriteNumberToSegment(0, (number_to_display / 1000) % 10);
            seg = 0;
            break;
        }
    }

    return NULL;
}