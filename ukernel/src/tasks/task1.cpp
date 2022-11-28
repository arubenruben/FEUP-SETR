#include "tasks.h"

void *task_1(void *args)
{
    static byte seg = 0;

    int count = (int) args;

    Serial.println(count);

    while (true)
    {
        switch (seg)
        {
        case 0:
            WriteNumberToSegment(3, count % 10);
            seg = 1;
            break;

        case 1:
            WriteNumberToSegment(2, (count / 10) % 10);
            seg = 2;
            break;

        case 2:
            WriteNumberToSegment(1, (count / 100) % 10);
            seg = 3;
            break;

        case 3:
            WriteNumberToSegment(0, (count / 1000) % 10);
            seg = 0;
            break;
        }
    }

    return NULL;
}