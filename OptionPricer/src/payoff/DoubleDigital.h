#ifndef DOUBLEDIGITAL_H_INCLUDED
#define DOUBLEDIGITAL_H_INCLUDED

#include "PayOff.h"

class PayOffDoubleDigital: public PayOff
{
    public:
        PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
        virtual double operator()(double Spot) const;
        virtual ~PayOffDoubleDigital(){};
        virtual PayOff* clone() const;

    private:
        double LowerLevel;
        double UpperLevel;

};


#endif // DOUBLEDIGITAL_H_INCLUDED
