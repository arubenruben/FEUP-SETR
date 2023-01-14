#include "measurements.h"
#ifdef MEASUREMENTS

typedef struct
{
    unsigned long start;
    unsigned long end;

} measurement_t;

measurement_t measurements[MEASUREMENTS_SIZE];
uint16_t measurements_size;
measurement_t *measurements_head;

void
init_measurements()
{
    measurements_size = 0;

    for (size_t i = 0; i < MEASUREMENTS_SIZE; i++)
    {
        measurements[i].start = 0;
        measurements[i].end = 0;
    }
    measurements_head = measurements;
}

void start_measure(unsigned long measurement)
{
    measurements_head->start = measurement;
}

void end_measure(unsigned long measurement)
{
    measurements_head->end = measurement;
    measurements_head++;
    measurements_size++;

    if (measurements_size > 100) {
        noInterrupts();
        print_measures();
    }
}

void print_measures()
{
    Serial.flush();
    
    Serial.print("Ended Execution. ");
    Serial.print(MEASUREMENTS_SIZE);
    Serial.println(" Measurements Reached. Print Then Exit");
    Serial.println("------------------");

    Serial.print("Begin(ms)");
    Serial.print("\t");
    Serial.print("End(ms)");
    Serial.print("\n");

    for (size_t i = 0; i < MEASUREMENTS_SIZE; i++)
    {
        Serial.print(measurements[i].start);
        Serial.print("\t");
        Serial.print(measurements[i].end);
        Serial.print("\n");
    }

    Serial.println("------------------");
    
    Serial.flush();

    exit(0);
}
#endif