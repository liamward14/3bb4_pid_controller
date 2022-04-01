#ifndef __PID_H__
#define __PID_H__

#include <stdlib.h>
#include <time.h>

extern int Kp;
extern int Ki;
extern int Kd;
extern float pe; // proportional error
extern float ie; // integral error
extern float de; // derivative error
extern float set_point;
extern float error;

// Subroutine to run basic pid control loop
void pid_controller_loop(void);

//PID data processing subroutines
float derivative(void);
int integral(void);
void circshift_single_insert(float* array, int element, int size);


#endif