/*
 * BsCallClass.h
 *
 *  Created on: 2016. jan. 5.
 *      Author: Gabor
 */

#ifndef BS_BSCALLCLASS_H_
#define BS_BSCALLCLASS_H_

class BSCall{
public:
	BSCall(double r_, double d_, double T_, double Spot_, double Strike_);

	double operator()(double Vol) const;

	double Price(double Vol) const;
	double Vega(double Vol) const;

private:
	double r;
	double d;
	double T;
	double Spot;
	double Strike;

};



#endif /* BS_BSCALLCLASS_H_ */
