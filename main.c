/*
*  PID Control Implemented using MSP430G2553
*  PID Control done on the embedded platform
*  PID parameters & output communicated via serial bus (to MATLAB)
*/

#include "io430.h"
#include "pid.h"
#include "comms.h"
#include "measure.h"

// Entry point
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  // Utilize 16MHz clock to maximize baud rate
  DCOCTL  = CALDCO_16MHZ;
  BCSCTL1 = CALBC1_16MHZ;
  
  // Initialize UART interface
  UART_setup();
  
  // Intialize ADC10
  init_ADC10(SINGLE_SAMPLE);
  

  return 0;
}


