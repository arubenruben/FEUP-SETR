#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include <Arduino.h>

#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8

    void segments_init();

    void write_integer_to_segments(int number);

    void WriteNumberToSegment(byte Segment, byte Value);

#ifdef __cplusplus
}
#endif