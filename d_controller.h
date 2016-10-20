#ifndef _D_CONTROLLER_H_
#define _D_CONTROLLER_H_

#include <stdio.h>
class D {
  public:

    D(double ki, double dt, double max, double min);

    ~D();

    /*
     * @param setpoint target
     * @param pv = process value read from a sensor
     * @return derivative result
     */
    double calculate( double setpoint, double pv );

  private:
    // max/min output
    double _max;
    double _min;

    // ki -  Derivative gain
    double _kd;

     // dt -  loop interval time
    double _dt;

    // previous error
    double _prev_error;
};

#endif
