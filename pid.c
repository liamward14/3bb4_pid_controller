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
  double test = (double)T_meas;
  char bytes[sizeof(double)];
  memcpy(bytes,&test,sizeof(double));
  
  /* Send 2 bytes corresponding to 16 bit int storing temp in milli deg C */
  //For testing: generate random number between 0 and 9
  //int r = rand() % 10;
  //T_meas += r; //todo: remove (just for testing)
  
  for(int i=0;i<sizeof(T_meas);i++){
    pc(T_meas >> (i*8));
  }
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
/*
void circshift(short* array, index){
  // index > 0 -> shift right
  // index < 0 -> shift left
  if(!index){ return; }
  //TODO
}
*/