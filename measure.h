#ifndef __MEASURE_H__
#define __MEASURE_H__

#include "math.h"

//Measures from PIN 1.4

#define CONTINUOUS_SAMPLING     5
#define SINGLE_SAMPLE           6
#define CAPACITY               79
#define N_POINTS               40
#define VCC                   3.3
#define VREFP                 2.5
#define VSS                   0
#define R1                   10000

//Define measurement
extern long T_meas; // milli deg C

//Read ADC10MEM register into this buffer
extern float read_buff[CAPACITY]; //to store past values (of error)
extern int temp_read_buff[N_POINTS]; //to compute avg value on every loop (milliC)

// Store index of array
extern int index;

//Subroutines
void init_ADC10(unsigned int mode);
void read_ADC10(int* v);
float avg_buffer(int* v);
long convert_temp(float meas); //Convert ADC measurements -> voltage -> temperature

//Read / Access subroutines


#endif