#include <Arduino.h>
#include "timer/timer.h"
#include "timer/handler.h"
#include "segments/segments.h"

void setup()
{
  Serial.begin(9600);

  // Initializes the 7 Segments
  segments_init();

  // Fire a tick each second
  timer_init(1, tick_handler);
}

void loop()
{
}