#ifndef _I_CONTROLLER_H_
#define _I_CONTROLLER_H_

#include <stdio.h>
class I {
  public:

    I(double ki, double dt, double max, double min);

    ~I();

    /*
     * @param setpoint target
     * @param pv = process value read from a sensor
     * @return proportional result
     */
    double calculate( double setpoint, double pv );

  private:
    double _max;
    double _min;
    // ki -  Integral gain
    double _ki;

     // dt -  loop interval time
    double _dt;

    // integral value
    double _integral;
    // previous error
    double _prev_error;
};

#endif
