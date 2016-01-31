/*
 * PayOffConstructible.h
 *
 *  Created on: 2016. jan. 31.
 *      Author: Gabor
 */

#ifndef PAYOFF_PAYOFFCONSTRUCTIBLE_H_
#define PAYOFF_PAYOFFCONSTRUCTIBLE_H_

#include "PayOff.h"
#include <string>
#include "PayOffFactory.h"

template <class T>
class PayOffHelper{
public:
	PayOffHelper(std::string);
	static PayOff* Create(double Strike);
};

template <class T>
PayOff* PayOffHelper<T>::Create(double Strike){
	return new T(Strike);
}

template <class T>
PayOffHelper<T>::PayOffHelper(std::string id){
	PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
	thePayOffFactory.RegisterPayOff(id, PayOffHelper<T>::Create);
}


#endif /* PAYOFF_PAYOFFCONSTRUCTIBLE_H_ */
