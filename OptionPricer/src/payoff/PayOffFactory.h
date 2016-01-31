/*
 * PayOffFactory.h
 *
 *  Created on: 2016. jan. 31.
 *      Author: Gabor
 */

#ifndef PAYOFF_PAYOFFFACTORY_H_
#define PAYOFF_PAYOFFFACTORY_H_

#include <map>
#include <string>
#include "PayOff.h"

class PayOffFactory{
public:
	typedef PayOff* (*CreatePayOffFunction)(double);

	static PayOffFactory& Instance();
	void RegisterPayOff(std::string PayOffId, CreatePayOffFunction CreatorFunction);
	PayOff* CreatePayOff(std::string PayOffId, double Strike);
	~PayOffFactory(){};

private:
	std::map<std::string, CreatePayOffFunction> TheCreatorFunctions;
	PayOffFactory(){}
	PayOffFactory(const PayOffFactory&){}
	PayOffFactory& operator= (const PayOffFactory& ){return *this;}
};



#endif /* PAYOFF_PAYOFFFACTORY_H_ */
