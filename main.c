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
//TODO: change
int Kp = 10;
int Ki = 1;
int Kd = 1;
float pe = 0;
float ie = 0;
float de = 0;
float set_point = 30;
float error = 0;
uint8_t ready_to_write = 0;
int MAX_ERROR = 0; 

// To store values for integration and diffrentiation
float read_buff[CAPACITY] = {0}; //Init with all zeros
int temp_read_buff[N_POINTS] = {0};// ""
int index = 0;

//Temp init
long T_meas = 0;

// Entry point
int main( void )
{
  //TODO; remove (for testing)
  //srand(time(NULL));
  MAX_ERROR = 50*Kd+CAPACITY*Ki+Kp;
  
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
    //run PID controller
    pid_controller_loop();
  }
  return 0;
}


