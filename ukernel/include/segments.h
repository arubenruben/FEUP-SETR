#pragma once

#include <Arduino.h>

#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8

void segments_init();

void WriteNumberToSegment(byte Segment, byte Value);
