/*
*  PID Control Implemented using MSP430G2553
*  PID Control done on the embedded platform
*  PID parameters & output communicated via serial bus (to MATLAB)
*/

#include "io430.h"
#include "comms.h"
#include "measure.h"
#include "pwm.h"
#include "pid.h"

short Kp = 0;
short Ki = 0;
short Kd = 0;
short set_point = 0;

// Entry point
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  // Utilize 1MHz clock
  DCOCTL  = CALDCO_1MHZ;
  BCSCTL1 = CALBC1_1MHZ;
  
  // Initialize UART interface
  UART_setup();
  
  // Configure interrupts through comms interface
  setup_interrupt_capability();
  
  // Intialize ADC10
  //init_ADC10(SINGLE_SAMPLE);
  
  //Setup PWM
  //config_PWM();
  
  
  //Run PID Loop TODO
  while(1){
    //TODO: run PID controller
    //pc('3');
    //while(n--);
    //n = 100000;
  }
  

  return 0;
}


