#ifndef __COMMS_H__
#define __COMMS_H__
#include <stdint.h>

#define GAIN_UPDATE      'g'
#define SETPOINT_UPDATE  's'
#define READY            'r'
#define SAMPLES              100 //Samples to send per transmission

//vars
extern uint8_t ready_to_write;

//subroutines
void UART_setup(void);
void send_ADC10_samples(unsigned short* buff, unsigned char samples);
void pc(unsigned char c);
char gc(void);


#endif