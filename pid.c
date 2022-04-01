#include "pid.h"
#include "measure.h"
#include "comms.h"

void pid_controller_loop(void){
  //TODO: adjust signal via (kp*e+kd*del_T/del+ki*int(e,0,t)
  //The error signal: e = T_s - Tprime(t) (T_s from matlab, Tprime from ADC)
  //Note: Could translate T_s into 8-bit char BEFORe transmission
  //Note: if e<0 -> reverse current (H-bridge)
  //Note: de/dt = (dTs-Tprime)/dt = -del_Tprime/del_t
  //Note: average a few of the finite difference derivative points to get less jittery control
  
  /*First, define error signal*/
  // Measure 40 (N_POINTS) signals and avg. to smooth out noise / errors
  read_ADC10(temp_read_buff);
  
  //Assuming calibration TODO: check
  // Next, average the read-in values
  T_meas = convert_temp(avg_buffer(temp_read_buff));
  
  pc(T_meas);
/*
  
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
*/
}

short derivative(void){
  //TODO
  // User centered difference approach of past error values
  // Take derivative of last 'y' points where y == TODO
 
  // Initialize Dpointer, pointer, and DT_meas
  // TODO: Measure the time between T_meas samples
  int sample_time = 0.001;
  
// pointer for where to save the derivative value
  if point = 0
    Dpointer = length(T_meas);
  else
    Dpointer = pointer - 1;
  
// pointer will need to change from 0 to length(T_meas)
// saves derivative at Dpointer (pointer-1) based on T(point) and T(point-2) 
// Consider running the sampling a bunch of times before evaluating any derivatives or integrals
  
  if pointer < 2
    DT_meas[Dpointer] = (T_meas[pointer]-T_meas[length(T_meas)+pointer-1])/(2*sample_time);
  else
    DT_meas[Dpointer] = (T_meas[pointer]-T_meas[pointer-2])/(2*sample_time);
  
  return 0;
}

short integral(void){
  //TODO: test
  // Take integral of the stored error functions
/*
  short sum = 0;
  if(index < CAPACITY - 1){
    for(int i=0;i<index;i++){
      sum += read_buff[i];
    }
  }
  else{
    for(int i=0;i<CAPACITY-1;i++){
      sum += read_buff[i];
    }
  }
  return sum;
*/
  return 0;
}