/*
 * TreeEuropean.h
 *
 *  Created on: 2015. dec. 23.
 *      Author: Bertalan
 */

#ifndef TREEPRODUCTS_TREEEUROPEAN_H_
#define TREEPRODUCTS_TREEEUROPEAN_H_

#include "../payoff/PayOffBridge.h"
#include "TreeProducts.h"

class TreeEuropean : public TreeProduct{
public:
	TreeEuropean(double FinalTime_, const PayOffBridge& ThePayOff_);
	virtual TreeProduct* clone() const;
	virtual double FinalPayOff(double Spot) const;
	virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const;
	virtual ~TreeEuropean(){}

private:
	PayOffBridge ThePayOff;
};



#endif /* TREEPRODUCTS_TREEEUROPEAN_H_ */
