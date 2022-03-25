#ifndef __MEASURE_H__
#define __MEASURE_H__

#include "math.h"

#define CONTINUOUS_SAMPLING     5
#define SINGLE_SAMPLE           6
#define CAPACITY               100
#define N_POINTS               40
#define VCC                   3.3
#define VREFP                 2.5
#define VSS                   0
#define R1                   10000

//Define measurement
extern float T_Meas;

//Read ADC10MEM register into this buffer
extern float read_buff[CAPACITY]; //to store past values
extern float temp_read_buff[N_POINTS]; //to compute avg value on every loop

// Store index of array
extern int index;

//Subroutines
void init_ADC10(unsigned int mode);
void read_ADC10(float* v);
float avg_buffer(float* v);
float convert_temp(float meas); //Convert ADC measurements -> voltage -> temperature

//Read / Access subroutines


#endif