#ifndef SIMPLEMC_H_INCLUDED
#define SIMPLEMC_H_INCLUDED

#include "../payoff/Vanilla.h"
#include "../utils/Parameters.h"
#include "../random/Random.h"
#include "MCStatistics.h"

void SimpleMonteCarlo(const VanillaOption& TheOption,
                         double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         unsigned long NumberOfPaths,
                         StatisticsMC& gatherer,
                         RandomBase& generator);


#endif // SIMPLEMC_H_INCLUDED
