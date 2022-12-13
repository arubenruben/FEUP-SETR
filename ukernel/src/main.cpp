#include "main.h"

void setup()
{
  Serial.begin(BAUD_RATE);

  while (!Serial)
  {
    ;
  }

  initialize_kernel();

  initialize_timer(DEFAULT_FREQ);
}

void loop()
{
}