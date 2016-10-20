#include "p_controller.cpp"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void){

  printf( ".:Proportional Controller Test:.\n" );

  double output;
  double max = 70;
  double min = -70;
  printf( "\t- setting values for variables Kp, pv and setpoint\n" );
  double kp = 1.65;
  double pv = 20;
  double setpoint = 50;
  printf( "\t\tKp = %.2f, pv = %.2f, setpoint = %.2f\n", kp, pv, setpoint);

  printf( "\t- Initializing P controller\n" );
  P* pctrl = new P(kp, max, min);

  printf( "\t- Calculating P output\n" );
  output = pctrl->calculate(setpoint, pv);

  printf( "\t- P output = %.2f\n", output);

  printf( "\tExinting P test..\n\t\tBye!\n" );

  /////////////////////////////////////////////

  // printf( ".:Proportional Controller Test:.\n" );

  // double output;
  // double precision = 0.5;
  // double max = 70;
  // double min = -70;

  // printf( "\t- setting values for variables Kp, pv and setpoint\n" );
  // double kp = 1.5;
  // double pv = 20; // pv não é realimentado com o output, saida de P e sim com a leitura do sensor(precisa ser simulado)
  // double setpoint = 50;
  // printf( "\t\tKp = %.2f, pv = %.2f, setpoint = %.2f\n", kp, pv, setpoint);

  // printf( "\t- Initializing P controller\n" );
  // P* pctrl = new P(kp, max, min);
  
  // do {
  //   printf( "\t- Calculating P output\n" );
  //   output = pctrl->calculate(setpoint, pv);
  //   printf( "\t- P output = %.2f\n", output);

  //   if( output > setpoint + precision ){
  //     kp -= 0.2;
  //   } else {//if (output < setpoint - precision ){
  //     kp += 0.01;
  //   }
  //   printf( "\t- updated Kp = %.2f\n", kp);
    
  //   printf( "\t- inform a value to simulate the next  value read from the sensor\n");
  //   double sensorValue;
  //   std::cin >> sensorValue;

  //   // pv = output;
  //   pv = sensorValue;
  //   printf( "\t- updated pv = %.2f\n", pv);

  //   // char stop;
  //   // std::cin >> stop;
  // } while( output != 0 );
  
  // printf( "\tExinting P test..\n\t\tBye!\n" );

  return 0;
}
