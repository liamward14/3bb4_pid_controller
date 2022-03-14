#include "comms.h"

/*Interrupt for MATLAB PID Gain update*/
#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR(void){ //ISR
  //TODO: Read values and update them
  
}

/* UART Setup function for Serial Bus communication */
void UART_setup(void){
  // TODO
  //Configure P1 pins for serial communications
  P1SEL = 0x06;
  P1SEL2 = 0x06;
  
  // select UART clock source
  UCA0CTL1 = 0xC0;
  
  //Set baud rate to baud_rate w/ prescaler value
  // divide by  104 for 9600b with  1MHz clock
  // divide by 1667 for 9600b with 16MHz clock
  // divide by  139 for 115200b with 16MHz clock
  //unsigned int divider = 16000000/baud_rate;
  UCA0BR1 = 0;
  UCA0BR0  = 139;
  
  //Release UART control reset bit
  UCA0CTL1_bit.UCSWRST = 0;
}

/*Send 10 bits in 2 char transmissions per "sample"*/
void send_ADC10_samples(unsigned short* buff, unsigned char samples){
  //TODO
  for(int i=0;i<samples;i++){
  }
}

/* Base methods for sending / recieving a char*/
void pc(unsigned char a){
  while(!IFG2_bit.UCA0TXIFG); //wait for transmit buffer to empty
  UCA0TXBUF = a; //push character to transmit buffer
}

char gc(void){
  while(!IFG2_bit.UCA0RXIFG); //wait for character recieved
  return UCA0RXBUF; //empty buffer to caller
}

// Interrupt Capability 
void setup_interrupt_capability(void){
  
  //enable interrupts in general
  __enable_interrupt();
  
  P1IE_bit.P3 = 1; //enable interrupt on RX pin TODO check
}

