
#include "../random/AntiThehetic.h"
#include "../random/ParkMiller.h"
#include "../mc/SimpleMC.h"
#include "../payoff/DoubleDigital.h"
#include "../payoff/Vanilla.h"
#include "../mc/MCStatistics.h"
#include "../mc/ConvergenceTable.h"
#include <iostream>

using namespace std;

void testingRandom(){
	double Expiry=1;
	double Strike=100;
	double Spot=100;
	ParametersConstant VolParam(0.1);
	ParametersConstant rParam(0);
	unsigned long NumberOfPaths=100000;

	PayOffCall payOffCall(Strike);

	VanillaOption theOption(payOffCall, Expiry);

	StatisticsMean gatherer;
	ConvergenceTable gathererTwo(gatherer);

	RandomParkMiller generator(1, 1564);
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

}

void testingMoments(){

	double Expiry=1;
	double Strike=100;
	double Spot=100;
	ParametersConstant VolParam(0.1);
	ParametersConstant rParam(0);
	unsigned long NumberOfPaths=10000;

	PayOffCall payOffCall(Strike);

	VanillaOption theOption(payOffCall, Expiry);

	StatiticsMoments gatherer;

	RandomParkMiller generator(15);
	AntiThetic GenTwo(generator);

	SimpleMonteCarlo(theOption, Spot,VolParam,rParam,NumberOfPaths, gatherer, GenTwo);

	vector<vector<double> > results = gatherer.GetResultSoFar();

	cout <<"\nThe moments are: " << endl;

	for (unsigned long i=0; i < results.size(); i++)
		{
			for (unsigned long j=0; j < results[i].size(); j++)
			cout << results[i][j] << " ";
			cout << "\n";
		}

	cout << endl;


}

void testingMean(){

	double Expiry=1;
	double Strike=100;
	double Spot=100;
	ParametersConstant VolParam(0.1);
	ParametersConstant rParam(0);
	unsigned long NumberOfPaths=10000;

	PayOffCall payOffCall(Strike);

	VanillaOption theOption(payOffCall, Expiry);

	StatisticsMean gatherer;

	RandomParkMiller generator(15);
	AntiThetic GenTwo(generator);

	SimpleMonteCarlo(theOption, Spot,VolParam,rParam,NumberOfPaths, gatherer, GenTwo);

	vector<vector<double> > results = gatherer.GetResultSoFar();

	cout <<"\nThe moments are: " << endl;

	for (unsigned long i=0; i < results.size(); i++)
		{
			for (unsigned long j=0; j < results[i].size(); j++)
			cout << results[i][j] << " ";
			cout << "\n";
		}

	cout << endl;


}

void testingVar(){
	double Expiry=1;
		double Strike=100;
		double Spot=100;
		ParametersConstant VolParam(0.1);
		ParametersConstant rParam(0);
		unsigned long NumberOfPaths=10000;

		PayOffCall payOffCall(Strike);

		VanillaOption theOption(payOffCall, Expiry);

		StatisticsVaR gatherer(0.95);

		RandomParkMiller generator(15);
		AntiThetic GenTwo(generator);

		SimpleMonteCarlo(theOption, Spot,VolParam,rParam,NumberOfPaths, gatherer, GenTwo);

		vector<vector<double> > results = gatherer.GetResultSoFar();

		cout <<"\nThe moments are: " << endl;

		for (unsigned long i=0; i < results.size(); i++)
			{
				for (unsigned long j=0; j < results[i].size(); j++)
				cout << results[i][j] << " ";
				cout << "\n";
			}

		cout << endl;


}


int main(){

	testingRandom();
    return 0;
}

