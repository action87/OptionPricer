#ifndef MCSTATISTICS_H_INCLUDED
#define MCSTATISTICS_H_INCLUDED

#include <vector>
#include <string>

class StatisticsMC{
    public:
        StatisticsMC(){}

        virtual void DumpOneResult(double result)=0;
        virtual std::vector<std::vector<double> > GetResultSoFar() const=0;
        virtual std::string name() const=0;
        virtual StatisticsMC* clone() const=0;
        virtual ~StatisticsMC(){}


    private:
};

class StatisticsMean : public StatisticsMC{
    public:
        StatisticsMean();

        virtual void DumpOneResult(double result);
        virtual std::vector<std::vector<double> > GetResultSoFar() const;
        virtual std::string name() const;
        virtual StatisticsMC* clone() const;

    private:
        double RunningSum;
        unsigned long PathsDone;
};

class StatiticsMoments : public StatisticsMC{
	public:
		StatiticsMoments();

		virtual void DumpOneResult(double result);
		virtual std::vector<std::vector<double> > GetResultSoFar() const;
		virtual std::string name() const;
		virtual StatisticsMC* clone() const;

	private:
		std::vector<double> values;

};

class StatisticsVaR : public StatisticsMC{
	public:
		StatisticsVaR(double percentile);

		virtual void DumpOneResult(double result);
		virtual std::vector<std::vector<double> > GetResultSoFar() const;
		virtual std::string name() const;
		virtual StatisticsMC* clone() const;

	private:
		std::vector<double> values;
		double percentile;
};

#endif // MCSTATISTICS_H_INCLUDED
