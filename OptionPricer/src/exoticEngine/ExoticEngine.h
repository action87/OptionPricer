/*
 * ExoticEngine.h
 *
 *  Created on: 2015. dec. 15.
 *      Author: Gabor
 */

#ifndef EXOTICENGINE_EXOTICENGINE_H_
#define EXOTICENGINE_EXOTICENGINE_H_

#include "../utils/Wrapper.h"
#include "../utils/Parameters.h"
#include "PathDependent.h"
#include "../utils/Arrays.h"
#include "../mc/MCStatistics.h"
#include <vector>

class ExoticEngine{

public:
	ExoticEngine(const Wrapper<PathDependent>& TheProduct_, const Parameters& r_);

	virtual void GetOnePath(MJArray& SpotValues)=0;
	void DoSimulation(StatisticsMC& TheGatherer, unsigned long NumberOfPaths);
	virtual ~ExoticEngine(){}
	double DoOnePath(const MJArray& SpotValues) const;



private:
	Wrapper<PathDependent> TheProduct;
	Parameters r;
	MJArray Discounts;
	mutable std::vector<CashFlow> TheseCashFlows;

};



#endif /* EXOTICENGINE_EXOTICENGINE_H_ */
