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
  
  //Assign byte to negative indication
  //char neg = 0x0;
  if(T_meas < 0){ return; }
  //pc(neg);
  
  //Transmit absolute value of T_meas
  //T_meas = abs(T_meas);
  
  /* Send 2 bytes corresponding to 16 bit int storing temp in milli deg C if MATLAB is ready */
  char read;
  if(ready_to_write){ 
    for(int i=0;i<sizeof(T_meas);i++){
      read = T_meas >> (i*8);
      //pc(T_meas >> (i*8));
      pc(read);
    }
    ready_to_write = 0;
  }
  

  
  // Define the error signal
  error = (set_point*1000) - (float)T_meas;
  
  /* Store measured temperature (milliC) in storage array */
  circshift_single_insert(read_buff, error, CAPACITY);
    
  // Determine Proportional term
  pe = Kp*error;
  
  // Determine Integral term
  ie = Ki*(float)integral();
  
  // Determine Derivative term
  de = Kd*derivative();
  
  // Effect change on thermocooler with PWM interface
  error = pe + ie + de;
  
  // TODO pwm

}

float derivative(void){
  //TODO
  // User centered difference approach of past error values
  // Take derivative of last 'y' points where y == TODO
 
  //Check if enough data is present
  if(!read_buff[CAPACITY-3]){ return 0; }
  
  // TODO: Measure the time between T_meas samples
  float sample_time = 0.001; //TODO determine proper
  
  float DT_meas = 0;
  DT_meas = (read_buff[CAPACITY-3]-read_buff[CAPACITY-1])/(2*sample_time);
  
  return DT_meas;

}

int integral(void){ //return milliC
  //TODO: test
  // Take integral of the stored error functions

  int Int_meas = 0;
  for (int i = 0; i < CAPACITY; ++i){
    Int_meas = Int_meas + read_buff[i];
  }
  
  return Int_meas;
}

void circshift_single_insert(float* array, int element, int size){
    //TODO: test

  //iterate from 0-(length-2)
  for(int i=0;i<size-1;i++){
    array[i] = array[i+1]; //left shift
  }
  
  // Assign element
  array[size-1] = element;
  
}

