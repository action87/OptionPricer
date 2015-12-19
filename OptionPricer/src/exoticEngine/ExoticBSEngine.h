/*
 * ExoticBSEngine.h
 *
 *  Created on: 2015. dec. 15.
 *      Author: Gabor
 */

#ifndef EXOTICENGINE_EXOTICBSENGINE_H_
#define EXOTICENGINE_EXOTICBSENGINE_H_

#include "ExoticEngine.h"
#include "../random/Random.h"

class ExoticBSEngine : public ExoticEngine {
public:
	ExoticBSEngine(	const Wrapper<PathDependent>& TheProduct_,
					const Parameters& R_,
					const Parameters& D_,
					const Parameters& Vol_,
					const Wrapper<RandomBase>& TheGenerator_,
					double Spot_);

	virtual void GetOnePath(MJArray& SpotValues);
	virtual ~ExoticBSEngine(){}

private:
	Wrapper<RandomBase> TheGenerator;
	MJArray Drifts;
	MJArray StandardDeviations;
	double LogSpot;
	unsigned long NumberOfTimes;
	MJArray Variates;

};


#endif /* EXOTICENGINE_EXOTICBSENGINE_H_ */
