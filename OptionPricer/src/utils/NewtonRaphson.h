/*
 * NewtonRaphson.h
 *
 *  Created on: 2016. jan. 20.
 *      Author: Gabor
 */

#ifndef UTILS_NEWTONRAPHSON_H_
#define UTILS_NEWTONRAPHSON_H_

//#include <iostream>

template<class T, double (T::*Value)(double) const, double (T::*Derivative)(double) const>
double NewtonRaphson(double Target, double Start, double Tolerance, const T& TheObject){
	double y=(TheObject.*Value)(Start);
	//std::cout << "y = " << y << std::endl;
	double x=Start;
	//std::cout << "x = " << x << std::endl;

	while(fabs(y-Target)>Tolerance){
		double d = (TheObject.*Derivative)(x);
		//std::cout << "d = " << d << std::endl;
		x+=(Target - y)/d;
		//std::cout << "x = " << x << std::endl;
		y=(TheObject.*Value)(x);
	}

	return x;
}



#endif /* UTILS_NEWTONRAPHSON_H_ */
