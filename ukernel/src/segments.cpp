#include "segments.h"

void segments_init()
{
    pinMode(LATCH_DIO, OUTPUT);
    pinMode(CLK_DIO, OUTPUT);
    pinMode(DATA_DIO, OUTPUT);
}

void WriteNumberToSegment(byte Segment, byte Value)
{
    /* Segment byte maps for numbers 0 to 9 */
    const byte SEGMENT_MAP[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0X80, 0X90};
    /* Byte maps to select digit 1 to 4 */
    const byte SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8};

    digitalWrite(LATCH_DIO, LOW);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
    shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment]);
    digitalWrite(LATCH_DIO, HIGH);
}