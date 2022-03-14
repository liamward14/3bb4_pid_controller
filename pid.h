#ifndef __PID_H__
#define __PID_H__

extern short Kp;
extern short Ki;
extern short Kd;

void update_pid_values(short Kp_arg, short Ki_arg, short Kd_arg);

#endif