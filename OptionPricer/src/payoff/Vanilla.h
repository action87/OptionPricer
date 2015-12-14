#ifndef VANILLA_H_INCLUDED
#define VANILLA_H_INCLUDED

#include "PayOffBridge.h"

class VanillaOption{
    public:
        VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);
        double OptionPayOff(double Spot) const;
        double GetExpiry() const;

    private:
        PayOffBridge ThePayOff;
        double Expiry;
};

#endif // VANILLA_H_INCLUDED
