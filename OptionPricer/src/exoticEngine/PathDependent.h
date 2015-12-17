/*
 * PathDependant.h
 *
 *  Created on: 2015. dec. 15.
 *      Author: Gabor
 */

#ifndef EXOTICENGINE_PATHDEPENDENT_H_
#define EXOTICENGINE_PATHDEPENDENT_H_

#include "../utils/Arrays.h"
#include <vector>

class CashFlow{

public :
	unsigned long TimeIndex;
	double Amount;

	CashFlow(unsigned long TimeIndex_=0UL, double Amount_=0.0) : TimeIndex(TimeIndex_), Amount(Amount_){} ;

private:

};

class PathDependent{
public:
	PathDependent(const MJArray& LookAtTimes);

	const MJArray& GetLookAtTimes() const;

	virtual unsigned long MaxNumberOfCashFlows() const=0;
	virtual MJArray PossibleCashFlowTimes() const=0;
	virtual unsigned long CashFlows(const MJArray& SpotValues, std::vector<CashFlow>& GeneratedCashFlows) const=0;

	virtual PathDependent* clone() const=0;

	virtual ~PathDependent(){}

private:
	MJArray LookAtTimes;

};


#endif /* EXOTICENGINE_PATHDEPENDENT_H_ */
