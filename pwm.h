#ifndef __PWM_H__
#define __PWM_H__

#define TAR_MAX 0xFFFF; //(65535)_(10) Max value of TimerA count register -> ued to define duty cycle

// Tested & Working

//Configuration subroutine
void config_PWM(void);

//Adjust output voltage during runtime with TACCR0 register value
void change_duty_cycle(char percentage);

#endif