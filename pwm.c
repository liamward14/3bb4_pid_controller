#include "pwm.h"

void config_PWM(void){
  //Utilize pin 9 (P2.1) on MSP430 for Timer Module
  
  // Select primary peripheral function for port 2
  P2SEL2_bit.P1 = 0;
  P2SEL_bit.P1 = 1;
  
  //Select TimerA Mode w/ control registe(selct sub-main clock, 1 input divider & continuous count up
  // Note: continuous count up from 0 to TACCR0
  TA1CTL = TASSEL_2 + ID_0 + MC_2;
  
  // Set output mode (defines how the output pin signal changes when timer counts to TACCRx register values
  //Note: TAR register contains counter of Timer_A
  //Note: When TAR == TACCR1, OUT1 is set (HIGH), when TAR == TACCR0, OUT1 is reset (LOW)
  //Note: Control pulse width with (TACCR0-TACCR1)/frequency (TACCR0 IS higher)
  TA1CCTL1 = OUTMOD_3; //Output mode 3 -> set / reset (set of TACCR1, reset on TACCR0)
  
  //Required count -> 25e3 for 25ms pulse width with 1MHz clock
  TACCR0 = 25000;
  TACCR1 = 0;
  
  // Note: Intialzing with 100% duty cycle
  
  //TODO: test output with scope
}

// Scale TimerA pulse width to control PWM
void change_duty_cycle(unsigned char percentage){
  TACCR0 = (percentage/100)*TAR_MAX;
}