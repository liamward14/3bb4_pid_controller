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

// Necessary external variable definitions
short Kp = 0;
short Ki = 0;
short Kd = 0;
short pe = 0;
short ie = 0;
short de = 0;
float set_point = 0;
float error = 0;

// To store values for integration and diffrentiation
float read_buff[CAPACITY] = {0}; //Init with all zeros
float temp_read_buff[N_POINTS] = {0};// ""
int index = 0;

//Temp init
int T_meas = 0;

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
  init_ADC10(CONTINUOUS_SAMPLING);
  
  //Setup PWM
  config_PWM();
  
  
  //Run PID Loop TODO
  while(1){
    //TODO: run PID controller
    //TODO: Transmit 'N' samples
    pid_controller_loop();
  }
  

  return 0;
}


