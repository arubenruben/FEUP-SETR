#include "main.h"

void setup()
{
  Serial.begin(BAUD_RATE);

  init_kernel();

  px_current_TCB = &tasks[0].stack_pointer;

  portRESTORE_CONTEXT();
}

void loop()
{
  
}