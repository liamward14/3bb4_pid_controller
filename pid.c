#include "pid.h"

void pid_controller_loop(void){
  //TODO: adjust signal via (kp*e+kd*del_T/del+ki*int(e,0,t)
  //The error signal: e = T_s - Tprime(t) (T_s from matlab, Tprime from ADC)
  //Note: Could translate T_s into 8-bit char BEFORe transmission
  //Note: if e<0 -> reverse current (H-bridge)
  //Note: de/dt = (dTs-Tprime)/dt = -del_Tprime/del_t
  //Note: average a few of the finite difference derivative points to get less jittery control
  
  //First, define error signal
  //Measure 5 signals and avg. to smooth out noise / errors
  read_ADC10(read_buff,5);
  T_meas = avg_buffer(read_buff,5);
  error = set_point - T_meas;
  
  //Determine Proportional term
  
  //Determine Integral term
  
  //Determine Derivative term
  
}

short derivative(unsigned char start_idx){
  //TODO
}

short integral(unsigned char start_idx, unsigned char end_idx){
  //TODO
}