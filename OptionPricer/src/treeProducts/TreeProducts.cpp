/*
 * TreeProducts.cpp
 *
 *  Created on: 2015. dec. 23.
 *      Author: Bertalan
 */

#include "TreeProducts.h"


TreeProduct::TreeProduct(double FinalTime_): FinalTime(FinalTime_){}

double TreeProduct::GetFinalValue() const{
	return FinalTime;
}
