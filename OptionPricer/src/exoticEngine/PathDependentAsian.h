/*
 * PathDependantAsian.h
 *
 *  Created on: 2015. dec. 19.
 *      Author: Bertalan
 */

#ifndef EXOTICENGINE_PATHDEPENDENTASIAN_H_
#define EXOTICENGINE_PATHDEPENDENTASIAN_H_

#include "PathDependent.h"
#include "../payoff/PayOffBridge.h"

class PathDependentAsian : public PathDependent{
public:
	PathDependentAsian(const MJArray& LookAtTimes
						,double DeliveryTime_
						,const PayOffBridge& ThePayOff_);

	virtual unsigned long MaxNumberOfCashFlows() const;
	virtual MJArray PossibleCashFlowTimes() const;
	virtual unsigned long CashFlows(const MJArray& SpotValues
									,std::vector<CashFlow>& GeneratedCashFlows) const;

	virtual ~PathDependentAsian(){}
	virtual PathDependent* clone() const;

private:
	double DeliveryTime;
	PayOffBridge ThePayOff;
	unsigned long NumberOfTimes;
};



#endif /* EXOTICENGINE_PATHDEPENDENTASIAN_H_ */
