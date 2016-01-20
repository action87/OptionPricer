/*
 * BSCallClass.cpp
 *
 *  Created on: 2016. jan. 5.
 *      Author: Gabor
 */

#include "BsCallClass.h"
#include "BlackScholesFormulas.h"

BSCall::BSCall(double r_, double d_, double T_, double Spot_, double Strike_):
				r(r_),d(d_), T(T_), Spot(Spot_), Strike(Strike_){

}

double BSCall::operator ()(double Vol) const{
	return BlackScholesCall(Spot, Strike, r, d, Vol, T);
}

double BSCall::Price(double Vol) const{
	return BlackScholesCall(Spot, Strike, r, d, Vol, T);
}

double BSCall::Vega(double Vol) const{
	return BlackScholesCallVega(Spot, Strike, r, d, Vol, T);
}
