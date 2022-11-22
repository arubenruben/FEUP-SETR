#include <Arduino.h>

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int i;
  i = 1;
  Serial.println("Hello World");
}