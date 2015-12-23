/*
 * TreeAmerican.h
 *
 *  Created on: 2015. dec. 23.
 *      Author: Bertalan
 */

#ifndef TREEPRODUCTS_TREEAMERICAN_H_
#define TREEPRODUCTS_TREEAMERICAN_H_

#include "../payoff/PayOffBridge.h"
#include "TreeProducts.h"

class TreeAmerican: public TreeProduct{
public:
	TreeAmerican(double FinalTime_, const PayOffBridge& ThePayOff_);
	virtual TreeProduct* clone() const;
	virtual double FinalPayOff(double Spot) const;
	virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const;
	virtual ~TreeAmerican(){}

private:
	PayOffBridge ThePayOff;
};



#endif /* TREEPRODUCTS_TREEAMERICAN_H_ */
