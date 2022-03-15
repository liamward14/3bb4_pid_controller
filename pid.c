#include "pid.h"

void update_pid_values(short Kp_arg, short Ki_arg, short Kd_arg){
  Kp = Kp_arg;
  Ki = Ki_arg;
  Kd = Kd_arg;
}
