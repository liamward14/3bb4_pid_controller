#ifndef __COMMS_H__
#define __COMMS_H__

void UART_setup(void);
void send_ADC10_samples(unsigned short* buff, unsigned char samples);
void pc(unsigned char c);
char gc(void);

//TODO: set up interrupt for receiving new Kp,Ki,Kd values

#endif