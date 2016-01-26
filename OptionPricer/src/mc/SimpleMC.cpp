#include "SimpleMC.h"
#include <cmath>
#include "../utils/Arrays.h"
#include <iostream>

// namespace std but aren’t in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

void SimpleMonteCarlo(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths,
                         StatisticsMC& gatherer,
                         RandomBase& generator)
{
    generator.ResetDimensionality(1);
    double Expiry=TheOption.GetExpiry();

    double variance=Vol.IntegralSquare(0,Expiry);
    //cout<< "variance= " << variance << endl;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;
    //cout<< "itoCorrection= " << itoCorrection << endl;

    double movedSpot = Spot * exp(r.Integral(0,Expiry) + itoCorrection);
    //cout<< "movedSpot= " << movedSpot << endl;
    double thisSpot;
    double discounting=exp(-r.Integral(0,Expiry));

    MJArray VariateArray(1);

    for (unsigned long i=0; i < NumberOfPaths; i++){
        generator.GetGaussians(VariateArray);
        //cout<< "Random = " << VariateArray[0]<< endl;
        thisSpot = movedSpot*exp( rootVariance*VariateArray[0]);
        //cout<< "thisSpot= " << thisSpot << endl;
        double thisPayoff = TheOption.OptionPayOff(thisSpot);
        gatherer.DumpOneResult(thisPayoff * discounting);
    }
 }
