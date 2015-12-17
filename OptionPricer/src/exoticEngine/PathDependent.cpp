/*
 * PathDependent.cpp
 *
 *  Created on: 2015. dec. 15.
 *      Author: Gabor
 */

#include "PathDependent.h"

PathDependent::PathDependent(const MJArray& LookAtTimes_): LookAtTimes(LookAtTimes_){}

const MJArray& PathDependent::GetLookAtTimes() const{
	return LookAtTimes;
}

