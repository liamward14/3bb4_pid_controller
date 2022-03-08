#include "comms.h"

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

