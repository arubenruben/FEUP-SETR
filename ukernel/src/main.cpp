#include "main.h"

void setup()
{
  Serial.begin(BAUD_RATE);
  initialize_kernel();
  initialize_timer(DEFAULT_FREQ);
}

void loop()
{
}