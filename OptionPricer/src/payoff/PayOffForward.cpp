/*
 * PayOffForward.cpp
 *
 *  Created on: 2016. jan. 5.
 *      Author: Gabor
 */

#include "PayOffForward.h"

double PayOffForward::operator () (double Spot) const {
	return Strike-Spot;
}


PayOffForward::PayOffForward(double Strike_) : Strike(Strike_){

}

PayOff* PayOffForward::clone() const{
	return new PayOffForward(*this);
}
