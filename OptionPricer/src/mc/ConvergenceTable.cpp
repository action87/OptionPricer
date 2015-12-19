#include "ConvergenceTable.h"

ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC>& Inner_): Inner(Inner_){
    StoppingPoint = 2;
    PathsDone = 0;
}

void ConvergenceTable::DumpOneResult(double result){
    Inner->DumpOneResult(result);
    ++PathsDone;

    if(PathsDone == StoppingPoint){
        StoppingPoint *=2;
        std::vector<std::vector<double> > thisResult(Inner->GetResultSoFar());

        for(unsigned long i=0;i<thisResult.size();i++){
            thisResult[i].push_back(PathsDone);
            ResultSoFar.push_back(thisResult[i]);
        }

    }

    return;
}

const std::string ConvergenceTable::name() const {
	return "ConvergenceTable";
}

std::vector<std::vector<double> > ConvergenceTable::GetResultSoFar() const{
    std::vector<std::vector<double> > tmp(ResultSoFar);

     if(PathsDone != StoppingPoint){
        std::vector<std::vector<double> > thisResult(Inner->GetResultSoFar());

        for(unsigned long i=0;i<thisResult.size();i++){
            thisResult[i].push_back(PathsDone);
            tmp.push_back(thisResult[i]);
        }

    }

    return tmp;
}

StatisticsMC* ConvergenceTable::clone() const{
    return new ConvergenceTable(*this);
}
