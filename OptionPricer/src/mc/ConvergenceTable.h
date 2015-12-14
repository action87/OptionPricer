#ifndef CONVERGENCETABLE_H_INCLUDED
#define CONVERGENCETABLE_H_INCLUDED

#include "MCStatistics.h"
#include "../utils/Wrapper.h"
#include <vector>

class ConvergenceTable : public StatisticsMC{
    public:
        ConvergenceTable(const Wrapper<StatisticsMC>& Inner_);

        virtual void DumpOneResult(double result);
        virtual std::vector<std::vector<double> > GetResultSoFar() const;
        virtual StatisticsMC* clone() const;

    private:
        Wrapper<StatisticsMC> Inner;
        std::vector<std::vector<double> > ResultSoFar;
        unsigned long StoppingPoint;
        unsigned long PathsDone;

};

#endif // CONVERGENCETABLE_H_INCLUDED
