/*
uses source files
        AntiThetic.cpp
        Arrays.cpp,
        ConvergenceTable.cpp,
        MCStatistics.cpp
        Normals.cpp
        Parameters.cpp,
        ParkMiller.cpp
        PayOff.cpp,
        PayOffBridge.cpp,
        Random.cpp,
        SimpleMC.cpp
        Vanilla.cpp,
*/


#include "../random/AntiThehetic.h"
#include "../random/ParkMiller.h"
#include "../mc/SimpleMC.h"
#include "../payoff/DoubleDigital.h"
#include "../payoff/Vanilla.h"
#include "../mc/MCStatistics.h"
#include "../mc/ConvergenceTable.h"
#include <iostream>
#include <conio.h>
using namespace std;


int main()
{
    double Expiry=1;
    double Strike=100;
    double Spot=100;
    ParametersConstant VolParam(0.1);
    ParametersConstant rParam(0);
    unsigned long NumberOfPaths=10000;

    PayOffCall payOffCall(Strike);

    VanillaOption theOption(payOffCall, Expiry);

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

    RandomParkMiller generator(1);
    AntiThetic GenTwo(generator);

    SimpleMonteCarlo(theOption, Spot,VolParam,rParam,NumberOfPaths, gathererTwo, GenTwo);

    vector<vector<double> > results = gathererTwo.GetResultSoFar();

    cout <<"\nFor the call price the results are " << endl;

    for (unsigned long i=0; i < results.size(); i++)
        {
            for (unsigned long j=0; j < results[i].size(); j++)
            cout << results[i][j] << " ";
            cout << "\n";
        }

    cout << endl;


    return 0;
}
