#include <Arduino.h>
#include "constants.h"
#include "timer.h"
#include "handler.h"
#include "segments.h"
#include "leds.h"


uint8_t stack[N_TASKS * TASK_STACKSIZE];

void setup()
{
  Serial.begin(9600);

  // Initializes the 7 Segments
  segments_init();
  leds_init();

  // Fire a tick each second
}

void loop()
{
}