#include "Parameters.h"
#include <algorithm>
#include <iostream>

Parameters::Parameters(const ParametersInner& innerObject){
    InnerObjectPtr=innerObject.clone();
}

Parameters::Parameters(const Parameters& original){
    InnerObjectPtr=original.InnerObjectPtr->clone();
}


Parameters& Parameters::operator=(const Parameters& original){
    if(this != &original){
        delete InnerObjectPtr;
        InnerObjectPtr = original.InnerObjectPtr->clone();
    }

    return (*this);
}

Parameters::~Parameters(){
    delete InnerObjectPtr;
}


 double Parameters::Mean(double time1, double time2) const{
    return Integral(time1, time2)/(time2-time1);
 }

 double Parameters::RootMeanSquare(double time1, double time2) const{
    return IntegralSquare(time1, time2)/(time2-time1);
 }

ParametersConstant::ParametersConstant(double constant){
    Constant=constant;
    ConstantSquare=constant*constant;
}

ParametersInner* ParametersConstant::clone() const{
    return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time1, double time2) const{
    return (time2-time1)*Constant;
}

double ParametersConstant::IntegralSquare(double time1, double time2) const{
    return (time2-time1)*ConstantSquare;
}

ParametersPieceWiseConstant::ParametersPieceWiseConstant(MJArray SplittingPoints_){
    SplittingPoints=SplittingPoints_;
    std::sort(SplittingPoints.begin(), SplittingPoints.end());
}

ParametersInner* ParametersPieceWiseConstant::clone() const{
    return new ParametersPieceWiseConstant(*this);
}

double ParametersPieceWiseConstant::Integral(double time1, double time2) const{

    double integral=0;

    bool lessThanTime1=true;
    bool greaterThanTime2 = false;

    for(unsigned long i=0; i< SplittingPoints.size(); i++){
        if(SplittingPoints[i]>time2&&!greaterThanTime2){
            greaterThanTime2=true;
            if(i!=0){
                integral += (time2 - std::max(SplittingPoints[i-1],time1))*i;
            }
        }

        if(!lessThanTime1&&!greaterThanTime2){
            integral += (SplittingPoints[i] - SplittingPoints[i-1])*i;
        }

        if(SplittingPoints[i]>time1&&lessThanTime1&&!greaterThanTime2){
            lessThanTime1=false;
            integral += (std::min(SplittingPoints[i], time2) - time1)*i;
        }

    }
    if(!greaterThanTime2&&lessThanTime1){
        integral += (time2 - time1)*SplittingPoints.size();
    }else if(!greaterThanTime2){
        integral += (time2 - SplittingPoints[SplittingPoints.size()-1])*SplittingPoints.size();
    }else if(greaterThanTime2&&!lessThanTime1&&SplittingPoints.size()==1){
        integral += (time2 - SplittingPoints[SplittingPoints.size()-1])*(SplittingPoints.size()-1);
    }


    return integral;
}

double ParametersPieceWiseConstant::IntegralSquare(double time1, double time2) const{

    double integralSquare=0;

    bool lessThanTime1=true;
    bool greaterThanTime2 = false;

    for(unsigned long i=0; i< SplittingPoints.size(); i++){
        if(SplittingPoints[i]>time2&&!greaterThanTime2){
            greaterThanTime2=true;
            if(i!=0){
                integralSquare += (time2 - std::max(SplittingPoints[i-1],time1))*i*i;
            }
        }

        if(!lessThanTime1&&!greaterThanTime2){
            integralSquare += (SplittingPoints[i] - SplittingPoints[i-1])*i*i;
        }

        if(SplittingPoints[i]>time1&&lessThanTime1&&!greaterThanTime2){
            lessThanTime1=false;
            integralSquare += (std::max(SplittingPoints[i], time2) - time1)*i*i;
        }

    }

    if(!greaterThanTime2&&lessThanTime1){
        integralSquare += (time2 - time1)*SplittingPoints.size()*SplittingPoints.size();
    }else if(!greaterThanTime2&&SplittingPoints.size()==1){
        integralSquare += (time2 - SplittingPoints[SplittingPoints.size()-1])*SplittingPoints.size()*SplittingPoints.size();
    }else if(greaterThanTime2&&!lessThanTime1&&SplittingPoints.size()==1){
        integralSquare += (time2 - SplittingPoints[SplittingPoints.size()-1])*(SplittingPoints.size()-1)*(SplittingPoints.size()-1);
    }

    return integralSquare;

}
