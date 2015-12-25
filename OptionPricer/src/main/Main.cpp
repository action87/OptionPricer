
#include "../random/AntiThehetic.h"
#include "../random/ParkMiller.h"
#include "../mc/SimpleMC.h"
#include "../payoff/DoubleDigital.h"
#include "../payoff/Vanilla.h"
#include "../mc/MCStatistics.h"
#include "../mc/ConvergenceTable.h"
#include <iostream>
#include "../exoticEngine/PathDependentAsian.h"
#include "../exoticEngine/ExoticBSEngine.h"
#include "../mc/StatisticGatherer.h"
#include "../tree/BinomialTree.h"
#include "../treeProducts/TreeProducts.h"
#include "../treeProducts/TreeAmerican.h"
#include "../treeProducts/TreeEuropean.h"
#include "../bs/BlackScholesFormulas.h"


using namespace std;

void testingEquityFX();
void testingRandom();
void testingMoments();
void testingMean();
void testingVar();
void testingStatisticGatherer();
void treeMain();

int main(){

	cout << "treeMain: "<<endl;
	treeMain();

	cout<<"\ntestingMean: "<< endl;
	testingMean();

	//TODO: the differences among BS pricer, Binomial tree and MC need to be checked
    return 0;
}

void treeMain(){
	double Expiry=2;
	double Strike=100;
	double Spot=100;
	double Vol=0.01;
	unsigned long Steps = 1000;
	double r=0.0;
	double d=0.0;
	ParametersConstant rParam(r);
	ParametersConstant dParam(d);

	PayOffCall thePayOff(Strike);

	TreeEuropean europeanOption(Expiry, thePayOff);
	TreeAmerican americanOption(Expiry, thePayOff);
	SimpleBinomialTree theTree(Spot, rParam, dParam, Vol, Steps, Expiry);

	double euroPrice=theTree.GetPrice(europeanOption);
	double americanPrice = theTree.GetPrice(americanOption);

	cout<< "European Price: " << euroPrice << ", American price: " << americanPrice<< endl;

	double BSPrice = BlackScholesCall(Spot, Strike, r,d, Vol, Expiry );
	cout << "BS formula euro price " << BSPrice<< endl;
}

void testingStatisticGatherer(){
	double Expiry=1;
	double Strike=100;
	double Spot=100;
	ParametersConstant VolParam(0.1);
	ParametersConstant rParam(0.05);
	unsigned long NumberOfPaths=10000;

	PayOffCall payOffCall(Strike);

	VanillaOption theOption(payOffCall, Expiry);

	StatisticsMean gathererMean;
	StatiticsMoments gathererMoments;
	StatisticsVaR gathererVar(0.95);
	ConvergenceTable gathererTwo(gathererMean);
	vector<Wrapper<StatisticsMC> > statisticGatherer;
	statisticGatherer.push_back(gathererMean);
	statisticGatherer.push_back(gathererMoments);
	statisticGatherer.push_back(gathererVar);
	statisticGatherer.push_back(gathererTwo);

	StatisticGatherer gatherer(statisticGatherer);

	RandomParkMiller generator(1);
	AntiThetic GenTwo(generator);

	SimpleMonteCarlo(theOption, Spot,VolParam,rParam,NumberOfPaths, gatherer, GenTwo);

	vector<vector<double> > results = gatherer.GetResultSoFar();
	vector<string> resultOrder = gatherer.getStatOrder();

	cout <<"\nThe statistics are: " << endl;

	for (unsigned long i=0; i < results.size(); i++)
		{
			cout<< resultOrder[i] << " : ";
			for (unsigned long j=0; j < results[i].size(); j++)
			cout << results[i][j] << " ";
			cout << "\n";
		}

	cout << endl;


}

void testingEquityFX(){
	double Expiry=1;
	double Strike=100;
	double Spot=200;
	ParametersConstant VolParam(0.1);
	ParametersConstant rParam(0);
	ParametersConstant dParam(0);
	unsigned long NumberOfDates = 6;
	unsigned long NumberOfPaths=100000;

	PayOffCall thePayOff(Strike);
	MJArray times(NumberOfDates);

	for(unsigned long i=0;i<NumberOfDates;i++){
		times[i]=(i+1.0) *Expiry*NumberOfDates;
	}

	PathDependentAsian theOption(times, Expiry, thePayOff);

	StatisticsMean gatherer;
	ConvergenceTable gathererTwo(gatherer);

	RandomParkMiller generator(1, 1564);
	AntiThetic GenTwo(generator);

	ExoticBSEngine theEngine(theOption, rParam, dParam, VolParam, GenTwo, Spot);

	theEngine.DoSimulation(gathererTwo, NumberOfPaths);

	vector<vector<double> > results = gathererTwo.GetResultSoFar();

	cout <<"\nFor the Asian call price the results are " << endl;

	for (unsigned long i=0; i < results.size(); i++)
		{
			for (unsigned long j=0; j < results[i].size(); j++){
				cout << results[i][j] << " ";
			}

			cout << "\n";
		}
}

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

	double Expiry=2;
	double Strike=100;
	double Spot=100;
	ParametersConstant VolParam(0.01);
	ParametersConstant rParam(0.0);
	unsigned long NumberOfPaths=10000;

	PayOffCall payOffCall(Strike);

	VanillaOption theOption(payOffCall, Expiry);

	StatisticsMean gatherer;

	RandomParkMiller generator(1);
	AntiThetic GenTwo(generator);

	SimpleMonteCarlo(theOption, Spot,VolParam,rParam,NumberOfPaths, gatherer, GenTwo);

	vector<vector<double> > results = gatherer.GetResultSoFar();

	cout <<"\nThe mean is: " << endl;

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
