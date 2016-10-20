#ifndef _I_CONTROLLER_
#define _I_CONTROLLER_

#include "i_controller.h"
#include <stdio.h>

I::I(double ki, double dt, double max, double min){
	_max = max;
	_min = min;
	_ki = ki;
	_dt = dt;
	_prev_error = 0;
	_integral = 0;
	printf("_ki = %.2f\n", _ki);
	printf("_dt = %.2f\n", _dt);
	printf("_prev_error = %.2f\n", _prev_error);
	printf("_integral = %.2f\n", _integral);
}

I::~I() { }

double I::calculate ( double setpoint, double pv ) {
	printf("params (setpoint = %.2f, pv = %.2f)\n", setpoint, pv);
	// calculate error
	double error = setpoint - pv;
	printf("error = %.2f\n", error);

	// Integral result
    _integral += error * _dt;
    double iOut = _ki * _integral;

	// Restrict to max/min
	if( iOut > _max ){
	    iOut = _max;
	    printf("updated to the max value: iOut = %.2f\n", iOut);
	}
	else if( iOut < _min ){
	    iOut = _min;
	    printf("updated to the min value: iOut = %.2f\n", iOut);
	}

	_prev_error = error;
	printf("_prev_error = %.2f\n", _prev_error);

  return iOut;
}

#endif
