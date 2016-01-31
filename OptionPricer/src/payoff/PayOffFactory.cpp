/*
 * PayOffFactory.cpp
 *
 *  Created on: 2016. jan. 31.
 *      Author: Gabor
 */

#include "PayOffFactory.h"
#include <iostream>

using namespace std;


PayOffFactory& PayOffFactory::Instance(){
	static PayOffFactory theFactory;
	return theFactory;
}

void PayOffFactory::RegisterPayOff(string PayOffId, CreatePayOffFunction CreatorFunction){
	TheCreatorFunctions.insert(pair<string, CreatePayOffFunction>(PayOffId, CreatorFunction));
}

PayOff* PayOffFactory::CreatePayOff(std::string PayOffId, double Strike){
	map<string, CreatePayOffFunction>::const_iterator i = TheCreatorFunctions.find(PayOffId);

	if(i==TheCreatorFunctions.end()){
		cout<< PayOffId <<" is an unknown payoff" << endl;
		return NULL;
	}

	return (i->second)(Strike);
}

