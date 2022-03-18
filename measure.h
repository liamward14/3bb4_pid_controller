#ifndef __MEASURE_H__
#define __MEASURE_H__

#define CONTINUOUS_SAMPLING     5
#define SINGLE_SAMPLE           6
#define CAPACITY               100

//Read ADC10MEM register into this buffer
extern short* read_buff[CAPACITY];

// Store index of array
extern int front;
extern int read;

//Subroutines
void init_ADC10(unsigned int mode);
void read_ADC10(unsigned short* v, unsigned char samples, unsigned char start);
short avg_buffer(unsigned short* v, unsigned char num_points);


#endif