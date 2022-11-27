
#include "handler.h"
#include <Arduino.h>
#include <stdio.h>
#include <time.h>

void tick_handler()
{

    unsigned long now = millis();

    Serial.println(now);

    return;
}