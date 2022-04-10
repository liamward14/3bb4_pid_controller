#ifndef __PID_H__
#define __PID_H__

#include <stdlib.h>
#include <time.h>
#include "io430.h"


//#define MAX_ERROR       100000
#define IN1             P1OUT_bit.P6
#define IN2             P1OUT_bit.P7

extern int Kp;
extern int Ki;
extern int Kd;
extern float pe; // proportional error
extern float ie; // integral error
extern float de; // derivative error
extern float set_point;
extern float error;
extern int MAX_ERROR;

// Subroutine to run basic pid control loop
void pid_controller_loop(void);

//PID data processing subroutines
float derivative(void);
int integral(void);
void circshift_single_insert(float* array, int element, int size);


#endif