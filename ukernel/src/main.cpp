#include "main.h"

void setup()
{
  Serial.begin(BAUD_RATE);
  while (!Serial);
  Serial.flush();
  
  leds_init();
  segments_init();

  kernel_init();
  kernel_start();
}

void loop()
{
  // Do Nothing
}