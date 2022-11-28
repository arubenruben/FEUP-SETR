#include <Arduino.h>
#include "timer.h"
#include "handler.h"
#include "segments.h"
#include "leds.h"

void setup()
{
  Serial.begin(9600);

  // Initializes the 7 Segments
  segments_init();
  leds_init();

  // Fire a tick each second
  timer_init(1, tick_handler);
}

void loop()
{
}