#include "main.h"

void setup()
{
  Serial.begin(BAUD_RATE);

  while (!Serial)
  {
    ;
  }

  init_kernel();

  init_timer(DEFAULT_FREQ);
}

void loop()
{
  // Do Nothing
}