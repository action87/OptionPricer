/*
 * Bisection.h
 *
 *  Created on: 2016. jan. 5.
 *      Author: Gabor
 */

#ifndef UTILS_BISECTION_H_
#define UTILS_BISECTION_H_

#include <iostream>

template <class T>
double Bisection(double Target, double Low, double High, double Tolerance, T TheFunction){

	double x= 0.5*(Low+High);
	std::cout << "x = " << x << std::endl;
	double y=TheFunction(x);
	std::cout << "y = " << y << std::endl;

	do{

		if(y<Target){
			Low=x;
		}

		if(y>Target){
			High=x;
		}

		x= 0.5*(Low+High);
		std::cout << "x = " << x << std::endl;
		y=TheFunction(x);
		//std::cout << "y = " << y << std::endl;

	}while((fabs(y-Target)>Tolerance));


	return x;
}



#endif /* UTILS_BISECTION_H_ */
