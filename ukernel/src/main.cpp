#include "main.h"

void setup()
{
  Serial.begin(BAUD_RATE);
  init_kernel();
  // init_timer();
}

void loop()
{
  Serial.println(*(cur_TCB - 1));
  Serial.println(*cur_TCB);
  Serial.println(*(cur_TCB + 1));
  Serial.flush();
  
  Serial.println("----------------");

  for (size_t i = 0; i < STACK_SIZE; i++)
  {
    Serial.print(i);
    Serial.print("|||");
    Serial.print(stack[i]);
    Serial.print("|||");
    Serial.print((long)&stack[i]);
    Serial.print("\n");
  }
  Serial.println("-------------");
  load_stack_pointer();

  /*
   */
}