#ifndef __MEASURE_H__
#define __MEASURE_H__

#include "math.h"

#define CONTINUOUS_SAMPLING     5
#define SINGLE_SAMPLE           6
#define CAPACITY               100
#define N_POINTS               40
#define VREFP                 2.5
#define VSS                   0

//Define measurement
extern short T_Meas;

//Read ADC10MEM register into this buffer
extern short* read_buff[CAPACITY]; //to store past values
extern short* temp_read_buff[N_POINTS]; //to compute avg value on every loop

// Store index of array
extern int index;

//Subroutines
void init_ADC10(unsigned int mode);
void read_ADC10(unsigned short* v, unsigned char samples, unsigned char start);
short avg_buffer(unsigned short* v);
short convert_temp(short meas); //Convert ADC measurements -> voltage -> temperature

//Read / Access subroutines
void store(short d);


#endif