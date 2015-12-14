#include "MCStatistics.h"
#include <math.h>		// pow, sqrt
#include <numeric>      // std::accumulate

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
	values.push_back (result);
}

StatisticsMC* StatiticsMoments::clone() const{
    return new StatiticsMoments(*this);
}

vector<vector<double> > StatiticsMoments::GetResultSoFar() const{
    vector<vector<double> > Results(4);

    //mean
    Results[0].resize(1);
    Results[0][0] = accumulate(values.begin(), values.end(), 0) / values.size();

    //variance
    Results[1].resize(1);
    Results[1][0] = inner_product(values.begin(), values.end(), values.begin(), 0.0) / values.size() - Results[0][0] * Results[0][0];

    //Skewness
    Results[2].resize(1);
    Results[2][0] = 0;

    for(vector<double>::const_iterator it = values.begin();it!=values.end();it++){
    	Results[2][0] += *it * *it * *it;
    }

    Results[2][0] /= values.size();
    Results[2][0] -= 3 * Results[0][0] * Results[1][0];
    Results[2][0] -= Results[0][0]*Results[0][0]*Results[0][0];

    Results[2][0]/= pow(sqrt(Results[1][0]),3);

    //Kurtosis
    Results[3].resize(1);

    for(vector<double>::const_iterator it = values.begin();it!=values.end();it++){
       	Results[3][0] += pow(*it - Results[0][0]  ,4);
    }
    Results[3][0] /= values.size();
    Results[3][0] /= pow(Results[1][0],2);

    return Results;
}
