#ifndef __PID_H__
#define __PID_H__

extern short Kp;
extern short Ki;
extern short Kd;
extern short set_point;
extern short error;

// Subroutine to run basic pid control loop
short pid_controller_loop(void);

//PID data processing subroutines
short derivative(unsigned char start_idx);
short integral(unsigned char start_idx, unsigned char end_idx);


#endif