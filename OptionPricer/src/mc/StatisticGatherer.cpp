/*
 * StatisticGatherer.cpp
 *
 *  Created on: 2015. dec. 19.
 *      Author: Bertalan
 */

#include "StatisticGatherer.h"

using namespace std;

StatisticGatherer::StatisticGatherer(const map<string, Wrapper<StatisticsMC> > InnerStatistics_)
			:
			InnerStatistics(InnerStatistics_)
{
}

StatisticGatherer::StatisticGatherer(const vector<Wrapper<StatisticsMC> > StatisticClasses_){
	for(unsigned int i=0; i < StatisticClasses_.size();i++){
		InnerStatistics.insert(pair<string, Wrapper<StatisticsMC> >(StatisticClasses_[i]->name(), StatisticClasses_[i]) );
	}
}

void StatisticGatherer::DumpOneResult(double result){

	for (map<string, Wrapper<StatisticsMC> >::iterator it=InnerStatistics.begin(); it!=InnerStatistics.end(); ++it){
		it->second->DumpOneResult(result);
	}
}

string StatisticGatherer::name() const {
	return "Statistics Gatherer";
}

//TODO The main part is commented and not checked
vector<vector<double> > StatisticGatherer::GetResultSoFar() const{

	vector<vector<double> > results;
	unsigned int resultsSize=0UL;

	for (map<string, Wrapper<StatisticsMC> >::const_iterator it=InnerStatistics.begin(); it!=InnerStatistics.end(); ++it){
		vector<vector<double> > innerResult = it->second->GetResultSoFar();
		//results.push_back(innerResult);
		for(unsigned int i=0;i<innerResult.size();i++){
			//ResultOrder[resultsSize + i] = name;
		}
		resultsSize = results.size();
	}

	return results;
}

StatisticsMC* StatisticGatherer::clone() const{
    return new StatisticGatherer(*this);
}




