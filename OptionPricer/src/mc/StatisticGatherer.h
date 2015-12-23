
/*
 * StatisticGatherer.h
 *
 *  Created on: 2015. dec. 15.
 *      Author: Gabor
 */

#ifndef MC_STATISTICGATHERER_H_
#define MC_STATISTICGATHERER_H_

#include <string>
#include "MCStatistics.h"
#include "../utils/Wrapper.h"
#include <map>


//TODO Implement the exercise 5.3.
class StatisticGatherer : public StatisticsMC{
	public:
		StatisticGatherer(const std::map<std::string, Wrapper<StatisticsMC> > InnerStatistics_);
		StatisticGatherer(const std::vector<Wrapper<StatisticsMC> > StatisticClasses_);
		virtual void DumpOneResult(double result);
		virtual std::vector<std::vector<double> > GetResultSoFar() const;
		virtual const std::string name() const;
		virtual StatisticsMC* clone() const;
		virtual ~StatisticGatherer(){}
		std::vector<std::string> getStatOrder();

	private:
		std::map<std::string, Wrapper<StatisticsMC> > InnerStatistics;
		mutable std::vector<std::string> ResultOrder;

};


#endif /* MC_STATISTICGATHERER_H_ */
