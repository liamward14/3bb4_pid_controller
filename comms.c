#include "comms.h"
#include "pid.h"
#include "io430.h"

/*Interrupt for MATLAB PID Gain update*/
#pragma vector = USCIAB0RX_VECTOR
__interrupt void USCIRX_ISR(void){ //ISR triggered when character recieved
  //TODO: Determine appropriate Kp, Ki, Kd values from start and stop codes from matlab
  //TODO: Read values and update them
  //First: determine parameter type
  //Second: determine parameter value
  //When interrupt triggers: read 6 chars
  //TODO: test whether interrupt flag is reset manually for USCI RX interrupt
  
  //First, read transmission char to deterimine whether to update gain values or setpoint
  //Note: bit shifts are to read in 16-bit integer values
  //Note: gain and setpoint not limited by read indiciators
  char read = gc();
  if(read == GAIN_UPDATE){
      Kp = gc();
    Kp = Kp + (gc() << 8);
    Ki = gc();
    Ki = Ki + (gc() << 8);
    Kd = gc();
    Kd = Kd + (gc() << 8);
  }
  else if(read == SETPOINT_UPDATE){
    set_point = gc();
    set_point = set_point + (gc() << 8); 
  }

  P1OUT_bit.P0 ^= 1; //toggle green LED status to indicate successful transmission

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
  UCA0BR0  = 104;
  
  //Release UART control reset bit
  UCA0CTL1_bit.UCSWRST = 0;
}

/*Send 8 bits in 1 char transmissins per "sample" (i.e. ignore 2 LSB)*/
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
  
  //For testing w/ LED
  P1DIR_bit.P0 = 1; //green
  P1OUT_bit.P0 = 0; //init off
  
  //enable interrupts in general
  __enable_interrupt();
  
  //Enable recieve interrupts for UART interface
  IE2_bit.UCA0RXIE = 1;
}

