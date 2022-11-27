
#include <Arduino.h>
#include <stdio.h>
#include <time.h>
#include "handler.h"
#include "segments/segments.h"

void tick_handler()
{
    unsigned long now = millis();

    write_integer_to_segments(1);

    return;
}