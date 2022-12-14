#include "main.h"

void setup()
{
  Serial.begin(BAUD_RATE);
  init_kernel();
}

void loop()
{
  asm("nop");
}