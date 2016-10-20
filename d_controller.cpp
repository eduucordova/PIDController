#ifndef _D_CONTROLLER_
#define _D_CONTROLLER_

#include "d_controller.h"
#include <stdio.h>

D::D(double kd, double dt, double max, double min){
	_max = max;
	_min = min;
	_kd = kd;
	_dt = dt;
	_prev_error = 0;
	printf("_kd = %.2f\n", _kd);
	printf("_dt = %.2f\n", _dt);
	printf("_prev_error = %.2f\n", _prev_error);
}

D::~D() { }

double D::calculate ( double setpoint, double pv ) {
	printf("params (setpoint = %.2f, pv = %.2f)\n", setpoint, pv);
	// calculate error
	double error = setpoint - pv;
	printf("error = %.2f\n", error);

	
    // Derivative term
    double derivative = (error - _prev_error) / _dt;
    double dOut = _kd * derivative;

	// Restrict to max/min
	if( dOut > _max ){
	    dOut = _max;
	    printf("updated to the max value: dOut = %.2f\n", dOut);
	}
	else if( dOut < _min ){
	    dOut = _min;
	    printf("updated to the min value: dOut = %.2f\n", dOut);
	}

	_prev_error = error;
	printf("_prev_error = %.2f\n", _prev_error);

  return dOut;
}

#endif
