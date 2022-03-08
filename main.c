/*
*  PID Control Implemented using MSP430G2553
*  PID Control done on the embedded platform
*  PID parameters & output communicated via serial bus (to MATLAB)
*/

#include "io430.h"
#include "pid.h"
#include "comms.h"

// Entry point
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  // Utilize 16MHz clock to maximize baud rate
  DCOCTL  = CALDCO_16MHZ;
  BCSCTL1 = CALBC1_16MHZ;
  
  // Run UARt setup
  UART_setup();

  return 0;
}


