/*
 * PayOffForward.h
 *
 *  Created on: 2016. jan. 5.
 *      Author: Gabor
 */

#ifndef PAYOFF_PAYOFFFORWARD_H_
#define PAYOFF_PAYOFFFORWARD_H_

#include "PayOff.h"

class PayOffForward : public PayOff{
public:
	PayOffForward(double Strike_);

	virtual double operator()(double Spot) const;
	virtual PayOff* clone() const;
	virtual ~PayOffForward(){}

private:
	double Strike;
};


#endif /* PAYOFF_PAYOFFFORWARD_H_ */
