#ifndef _P_CONTROLLER_H_
#define _P_CONTROLLlER_H_

#include <stdio.h>
class P {
  public:

    P(double kp, double max, double min);

    ~P();

    /*
     * @param setpoint target
     * @param pv = process value read from a sensor
     * @return proportional result
     */
    double calculate( double setpoint, double pv );

  private:
    double _max;
    double _min;
    // kp = proportional gain
    double _kp;
    // previous error
    double _prev_error;
};

#endif
