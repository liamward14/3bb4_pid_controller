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
  
  // Next, average the read-in values & apply calibration
  T_meas = convert_temp(avg_buffer(temp_read_buff));
  
  /* Send 2 bytes corresponding to 16 bit int storing temp in milli deg C */
  for(int i=0;i<sizeof(T_meas);i++){
    pc(T_meas >> (i*8));
  }
  
  /* Store measured temperature (milliC) in storage array */
  circshift_single_insert(temp_read_buff, T_meas, CAPACITY);

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

float derivative(void){
  //TODO
  // User centered difference approach of past error values
  // Take derivative of last 'y' points where y == TODO
 
  // Initialize DT_meas
  // TODO: Measure the time between T_meas samples
  float sample_time = 0.001;
  
  float DT_meas = 0;
  DT_meas = (read_buff[CAPACITY-3]-read_buff[CAPACITY-1])/(2*sample_time);
  
  return DT_meas;

}

short integral(void){
  //TODO: test
  // Take integral of the stored error functions

  int Int_meas = 0;
  for (int i = 0; i < CAPACITY; ++i){
    Int_meas = Int_meas + read_buff[i];
  }
  
  return Int_meas;
}

void circshift_single_insert(int* array, int element, int size){
    //TODO: test

  //iterate from 0-(length-2)
  for(int i=0;i<size-1;i++){
    array[i] = array[i+1]; //left shift
  }
  
  // Assign element
  array[size-1] = element;
  
}

