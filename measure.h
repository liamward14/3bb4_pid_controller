#ifndef __MEASURE_H__
#define __MEASURE_H__

#define CONTINUOUS_SAMPLING     5
#define SINGLE_SAMPLE           6

//Read ADC10MEM register into this buffer
static unsigned short* read_buff[100];

//Subroutines
void init_ADC10(unsigned int mode);
void read_ADC10(unsigned short* v, unsigned char samples);


#endif