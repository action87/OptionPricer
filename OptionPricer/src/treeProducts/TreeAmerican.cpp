/*
 * TreeAmerican.cpp
 *
 *  Created on: 2015. dec. 23.
 *      Author: Bertalan
 */

#include "TreeAmerican.h"
#include <algorithm>

TreeAmerican::TreeAmerican(double FinalTime_, const PayOffBridge& ThePayOff_):TreeProduct(FinalTime_), ThePayOff(ThePayOff_)
{
}

TreeProduct* TreeAmerican::clone() const{
	return new TreeAmerican(*this);
}

double TreeAmerican::FinalPayOff(double Spot) const{
	return ThePayOff(Spot);
}

double TreeAmerican::PreFinalValue(double Spot, double , double DiscountedFutureValue) const {
	return std::max(ThePayOff(Spot), DiscountedFutureValue);
}


