#include "MCStatistics.h"
#include <math.h>		// pow, sqrt
#include <numeric>      // std::accumulate
#include <algorithm>    // std::sort
//#include <iostream>

using namespace std;

StatisticsMean::StatisticsMean():RunningSum(0.0),PathsDone(0UL){}

void StatisticsMean::DumpOneResult(double result){
    PathsDone++;
    RunningSum += result;
}

vector<vector<double> > StatisticsMean::GetResultSoFar() const{
    vector<vector<double> > Results(1);
    Results[0].resize(1);
    Results[0][0] = RunningSum/ PathsDone;

    return Results;
}

StatisticsMC* StatisticsMean::clone() const{
    return new StatisticsMean(*this);
}

StatiticsMoments::StatiticsMoments(){}

void StatiticsMoments::DumpOneResult(double result){
	values.push_back(result);
}

StatisticsMC* StatiticsMoments::clone() const{
    return new StatiticsMoments(*this);
}

vector<vector<double> > StatiticsMoments::GetResultSoFar() const{
    vector<vector<double> > Results(4);

    double NumberOfPath = (values.size() * 1.0);
    //mean
    Results[0].resize(2);
    Results[0][0] = 1;
    Results[0][1] = 0;
    Results[0][1] = accumulate(values.begin(), values.end(), 0.0) / NumberOfPath;

    //variance
    Results[1].resize(2);
    Results[1][0] = 2;
    Results[1][1] = inner_product(values.begin(), values.end(), values.begin(), 0.0) / NumberOfPath - Results[0][0] * Results[0][0];

    //Skewness
    Results[2].resize(2);
    Results[2][0] = 3;
    Results[2][1] = 0;

    for(vector<double>::const_iterator it = values.begin();it!=values.end();it++){
    	Results[2][1] += *it * *it * *it;
    }

    Results[2][1] /= NumberOfPath;
    Results[2][1] -= 3 * Results[0][1] * Results[1][1];
    Results[2][1] -= Results[0][1]*Results[0][1]*Results[0][1];

    Results[2][1]/= pow(sqrt(Results[1][1]),3);

    //Kurtosis
    Results[3].resize(2);

    Results[3][0] = 4;
    Results[3][1] = 0;

    for(vector<double>::const_iterator it = values.begin();it!=values.end();it++){
       	Results[3][1] += pow(*it - Results[0][1]  ,4);
    }
    Results[3][1] /= NumberOfPath;
    Results[3][1] /= pow(Results[1][1],2);

    return Results;
}

StatisticsVaR::StatisticsVaR(double _percentile):percentile(_percentile){}

void StatisticsVaR::DumpOneResult(double result){
	values.push_back(result);
}

vector<vector<double> > StatisticsVaR::GetResultSoFar() const{

	vector<double> copyOfValues = values;
	sort(copyOfValues.begin(), copyOfValues.end());

    vector<vector<double> > Results(1);
    Results[0].resize(2);

    int indexOfPathMappedToPercentile = percentile * values.size();
    //cout<< "indexOfPathMappedToPercentile: "<< indexOfPathMappedToPercentile << endl;

    Results[0][0] = percentile;
    Results[0][1] = copyOfValues[indexOfPathMappedToPercentile];

    /*for(vector<double>::const_iterator it = values.begin();it!=values.end();it++){
    	cout<< "values[] "<< *it << endl;
    }*/

    return Results;
}

StatisticsMC* StatisticsVaR::clone() const{
    return new StatisticsVaR(*this);
}
