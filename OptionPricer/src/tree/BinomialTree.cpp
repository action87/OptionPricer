/*
 * BinomialTree.cpp
 *
 *  Created on: 2015. dec. 23.
 *      Author: Bertalan
 */

#include "BinomialTree.h"
#include "../utils/Arrays.h"
#include <cmath>

#if !defined(_MSC_VER)
	using namespace std;
#endif

SimpleBinomialTree::SimpleBinomialTree(	double Spot_,
										const Parameters& r_,
										const Parameters& d_,
										double Volatility_,
										unsigned long Steps_,
										double Time_)
										:Spot(Spot_),
										 r(r_),
										 d(d_),
										 Volatility(Volatility_),
										 Steps(Steps_),
										 Time(Time_),
										 Discounts(Steps)
{
	TreeBuilt = false;
}

void SimpleBinomialTree::BuildTree(){
	TreeBuilt=true;
	TheTree.resize(Steps + 1);

	double InitialLogSpot = log(Spot);

	for(unsigned long i=0; i<=Steps;i++){
		TheTree[i].resize(i+1);
		double thisTime = (i*Time)/Steps;

		double movedLogSpot = InitialLogSpot + r.Integral(0.0, thisTime) - d.Integral(0.0, thisTime);
		movedLogSpot -= 0.5 * Volatility *thisTime;
		double sd = Volatility * sqrt(Time/Steps);

		for(long j = - static_cast<long>(i), k=0 ; j<= static_cast<long>(i); j=j+2, k++  ){
			TheTree[i][k].first = exp(movedLogSpot + j*sd);
		}
	}

	for (unsigned long l=0; l<Steps;l++){
		Discounts[l]= exp(-r.Integral(l*Time/Steps,(l+1)*Time/Steps ));
	}
}

