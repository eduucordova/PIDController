#include "i_controller.cpp"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){

  printf( ".:Integral Controller Test:.\n" );

  double output;
  double max = 70;
  double min = -70;
  printf( "\t- setting values for variables Ki, pv and setpoint\n" );
  double ki = 1.65;
  double dt = 0.5;
  double pv = 20;
  double setpoint = 50;
  printf( "\t\tKi = %.2f, pv = %.2f, setpoint = %.2f\n", ki, pv, setpoint);

  printf( "\t- Initializing I controller\n" );
  I* ictrl = new I(ki, dt, max, min);

  printf( "\t- Calculating I output\n" );
  output = ictrl->calculate(setpoint, pv);

  printf( "\t- I output = %.2f\n", output);

  printf( "\tExinting I test..\n\t\tBye!\n" );

  return 0;
}
