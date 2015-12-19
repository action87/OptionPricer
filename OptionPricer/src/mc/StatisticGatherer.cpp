/*
 * StatisticGatherer.cpp
 *
 *  Created on: 2015. dec. 19.
 *      Author: Bertalan
 */

#include "StatisticGatherer.h"
#include <iostream>
#include <vector>

using namespace std;

StatisticGatherer::StatisticGatherer(const map<string, Wrapper<StatisticsMC> > InnerStatistics_)
			:
			InnerStatistics(InnerStatistics_)
{
	ResultOrder.resize(1000);
}

StatisticGatherer::StatisticGatherer(const vector<Wrapper<StatisticsMC> > StatisticClasses_){
	for(unsigned int i=0; i < StatisticClasses_.size();i++){
		InnerStatistics.insert(pair<const string, Wrapper<StatisticsMC> >(StatisticClasses_[i]->name(), StatisticClasses_[i]) );
	}
	ResultOrder.resize(1000);
}

void StatisticGatherer::DumpOneResult(double result){

	for (map<string, Wrapper<StatisticsMC> >::iterator it=InnerStatistics.begin(); it!=InnerStatistics.end(); ++it){
		it->second->DumpOneResult(result);
	}
}

const string StatisticGatherer::name() const {
	return "Statistics Gatherer";
}

//TODO The main part is commented and not checked
vector<vector<double> > StatisticGatherer::GetResultSoFar() const{

	vector<vector<double> > results;
	unsigned int resultsSize=0UL;


	for (map<string, Wrapper<StatisticsMC> >::const_iterator it=InnerStatistics.begin(); it!=InnerStatistics.end(); ++it){
		vector<vector<double> > innerResult = it->second->GetResultSoFar();
		results.insert(results.end(), innerResult.begin(), innerResult.end());
		for(unsigned int i=0;i<innerResult.size();i++){
			;
			ResultOrder[resultsSize+i] = it->first;
		}
		resultsSize = results.size();
	}

	return results;
}

StatisticsMC* StatisticGatherer::clone() const{
    return new StatisticGatherer(*this);
}

vector<string> StatisticGatherer::getStatOrder(){
	return ResultOrder;
}



