/*
 * TreeProducts.h
 *
 *  Created on: 2015. dec. 23.
 *      Author: Bertalan
 */

#ifndef TREEPRODUCTS_TREEPRODUCTS_H_
#define TREEPRODUCTS_TREEPRODUCTS_H_

class TreeProduct{
public:
	TreeProduct(double FinalTime_);
	virtual double FinalPayOff(double Spot) const=0;
	virtual double PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const=0;

	virtual ~TreeProduct(){}
	virtual TreeProduct* clone() const=0;
	double GetFinalValue() const;

private:
	double FinalTime;
};



#endif /* TREEPRODUCTS_TREEPRODUCTS_H_ */
