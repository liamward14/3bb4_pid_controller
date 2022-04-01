#ifndef __PID_H__
#define __PID_H__

#include <stdlib.h>
#include <time.h>

extern short Kp;
extern short Ki;
extern short Kd;
extern short pe; // proportional error
extern short ie; // integral error
extern short de; // derivative error
extern float set_point;
extern float error;

// Subroutine to run basic pid control loop
void pid_controller_loop(void);

//PID data processing subroutines
short derivative(void);
short integral(void);


#endif