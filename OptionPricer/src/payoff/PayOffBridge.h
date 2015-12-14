#ifndef PAYOFFBRIDGE_H_INCLUDED
#define PAYOFFBRIDGE_H_INCLUDED

#include "PayOff.h"

class PayOffBridge{

public:
    PayOffBridge(const PayOffBridge& original);
    PayOffBridge(const PayOff& innerPayOff);

    inline double operator()(double Spot) const;
    ~PayOffBridge();
    PayOffBridge& operator=(const PayOffBridge& original);

private:
    PayOff* ThePayOffPtr;

};

inline double PayOffBridge::operator()(double Spot) const{
    return ThePayOffPtr->operator ()(Spot);
}

#endif // PAYOFFBRIDGE_H_INCLUDED
