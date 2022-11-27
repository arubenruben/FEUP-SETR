#include <Arduino.h>
#include <timer/timer.h>
#include <timer/handler.h>

void setup()
{
  Serial.begin(9600);

  // Fire a tick each second
  timer_init(1, tick_handler);
}

void loop()
{
}