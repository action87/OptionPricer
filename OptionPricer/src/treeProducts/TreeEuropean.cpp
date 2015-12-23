/*
 * TreeEuropean.cpp
 *
 *  Created on: 2015. dec. 23.
 *      Author: Bertalan
 */

#include "TreeEuropean.h"
#include <algorithm>

TreeEuropean::TreeEuropean(double FinalTime_, const PayOffBridge& ThePayOff_):TreeProduct(FinalTime_), ThePayOff(ThePayOff_)
{
}

TreeProduct* TreeEuropean::clone() const{
	return new TreeEuropean(*this);
}

double TreeEuropean::FinalPayOff(double Spot) const{
	return ThePayOff(Spot);
}

double TreeEuropean::PreFinalValue(double , double , double DiscountedFutureValue) const {
	return  DiscountedFutureValue;
}





