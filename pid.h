#ifndef __PID_H__
#define __PID_H__

extern short Kp;
extern short Ki;
extern short Kd;
extern short set_point;

// Subroutine to run basic pid control loop
short pid_controller_loop(void);

#endif