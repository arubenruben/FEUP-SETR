#include "main.h"

void setup()
{
  Serial.begin(BAUD_RATE);
  while (!Serial);
  Serial.flush();

  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT);
  
  digitalWrite(D4, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D1, HIGH);
  
  kernel_init();
  kernel_start();
}

void loop()
{
  // Do Nothing
}