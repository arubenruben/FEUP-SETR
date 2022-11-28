#include "leds.h"

void leds_init()
{
    pinMode(d4, OUTPUT);
    pinMode(d3, OUTPUT);
    pinMode(d2, OUTPUT);
    pinMode(d1, OUTPUT);
    
    digitalWrite(d4, HIGH);
    digitalWrite(d3, HIGH);
    digitalWrite(d2, HIGH);
    digitalWrite(d1, HIGH);
}