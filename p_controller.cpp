#ifndef _P_CONTROLLER_
#define _P_CONTROLLER_

#include "p_controller.h"
#include <stdio.h>

P::P(double kp, double max, double min){
	_max = max;
	_min = min;
	_kp = kp;
	_prev_error = 0;
	printf("_kp = %.2f\n", _kp);
	printf("_prev_error = %.2f\n", _prev_error);
}

P::~P() { }

double P::calculate ( double setpoint, double pv ) {
	printf("params (setpoint = %.2f, pv = %.2f)\n", setpoint, pv);
	// calculate error
	double error = setpoint - pv;
	printf("error = %.2f\n", error);

	// proportional result
	double pOut = _kp * error;
	printf("pOut = %.2f\n", pOut);

	// Restrict to max/min
	if( pOut > _max ){
	    pOut = _max;
	    printf("updated to the max value: pOut = %.2f\n", pOut);
	}
	else if( pOut < _min ){
	    pOut = _min;
	    printf("updated to the min value: pOut = %.2f\n", pOut);
	}

	_prev_error = error;
	printf("_prev_error = %.2f\n", _prev_error);

  return pOut;
}

#endif
