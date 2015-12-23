/*
 * BinomialTree.h
 *
 *  Created on: 2015. dec. 23.
 *      Author: Bertalan
 */

#ifndef TREEPRODUCTS_BINOMIALTREE_H_
#define TREEPRODUCTS_BINOMIALTREE_H_

#include "../treeProducts/TreeProducts.h"
#include <vector>
#include "../utils/Parameters.h"
#include "../utils/Arrays.h"

class SimpleBinomialTree{
public:
	SimpleBinomialTree(double Spot, const Parameters& r_, const Parameters& d_, double Volatility_, unsigned long Steps, double Time );
	double GetPrice(const TreeProduct& TheProduct);

protected:
	void BuildTree();

private:
	double Spot;
	Parameters r;
	Parameters d;
	double Volatility;
	unsigned long Steps;
	double Time;
	bool TreeBuilt;

	std::vector<std::vector<std::pair<double, double> > > TheTree;
	MJArray Discounts;

};



#endif /* TREEPRODUCTS_BINOMIALTREE_H_ */
