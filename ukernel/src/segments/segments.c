#include <Arduino.h>
#include "segments.h"

/* Segment byte maps for numbers 0 to 9 */
const byte SEGMENT_MAP[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0X80, 0X90};
/* Byte maps to select digit 1 to 4 */
const byte SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8};

void segments_init()
{
    pinMode(LATCH_DIO, OUTPUT);
    pinMode(CLK_DIO, OUTPUT);
    pinMode(DATA_DIO, OUTPUT);
}

void write_integer_to_segments(int number)
{
    WriteNumberToSegment(3, number % 10);
    WriteNumberToSegment(2, (number / 10) % 10);
    WriteNumberToSegment(1, (number / 100) % 10);
    WriteNumberToSegment(0, (number / 1000) % 10);
}

void WriteNumberToSegment(byte Segment, byte Value)
{
    digitalWrite(LATCH_DIO, LOW);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment]);
    digitalWrite(LATCH_DIO, HIGH);
}