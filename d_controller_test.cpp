#include "d_controller.cpp"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){

  printf( ".:Derivative Controller Test:.\n" );

  double output;
  double max = 70;
  double min = -70;
  printf( "\t- setting values for variables kd, pv and setpoint\n" );
  double kd = 1.65;
  double dt = 0.5;
  double pv = 20;
  double setpoint = 50;
  printf( "\t\tkd = %.2f, pv = %.2f, setpoint = %.2f\n", kd, pv, setpoint);

  printf( "\t- Initializing D controller\n" );
  D* dctrl = new D(kd, dt, max, min);

  printf( "\t- Calculating D output\n" );
  output = dctrl->calculate(setpoint, pv);

  printf( "\t- D output = %.2f\n", output);

  printf( "\tExinting D test..\n\t\tBye!\n" );

  return 0;
}
