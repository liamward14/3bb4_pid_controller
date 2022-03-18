#include "pid.h"

void pid_controller_loop(void){
  //TODO: adjust signal via (kp*e+kd*del_T/del+ki*int(e,0,t)
  //The error signal: e = T_s - Tprime(t) (T_s from matlab, Tprime from ADC)
  //Note: Could translate T_s into 8-bit char BEFORe transmission
  //Note: if e<0 -> reverse current (H-bridge)
  //Note: de/dt = (dTs-Tprime)/dt = -del_Tprime/del_t
  //Note: average a few of the finite difference derivative points to get less jittery control
  
  /*First, define error signal*/
  // Measure 40 (N_POINTS) signals and avg. to smooth out noise / errors
  read_ADC10(temp_read_buff,N_POINTS);
  
  //Assuming calibration TODO: check
  // Next, average the read-in values
  T_meas = avg_buffer(temp_read_buff);
  
  // Define the error signal
  error = set_point - T_meas;
  
  // Determine Proportional term
  pe = Kp*error;
  
  // Determine Integral term
  ie = integral()*error;
  
  // Determine Derivative term
  de = derivative*error;
  
  // Effect change on thermocooler with PWM interface
  // TODO
}

short derivative(void){
  //TODO
  // User centered difference approach of past error values
  // Take derivative of last 'y' points where y == TODO
  return 0;
}

short integral(void){
  //TODO: test
  // Take integral of the stored error functions
  short sum = 0;
  if(index < CAPACITY - 1){
    for(int i=0;i<index;i++){
      sum += readBuff[i];
    }
  }
  else{
    for(int i=0;i<CAPACITY-1;i++){
      sum += readBuff[i];
    }
  }
  return sum;
}