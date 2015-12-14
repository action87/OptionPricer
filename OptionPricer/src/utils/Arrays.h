#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#ifdef USE_VAL_ARRAY

#include <valarray>

typedef std::valarray<double> MJArray;

#else // ifdef USE_VAL_ARRAY

class MJArray {

    public:
        explicit MJArray(unsigned long size=0);
        MJArray(const MJArray& original);

        ~MJArray();

        MJArray& operator=(const MJArray& original);
        MJArray& operator=(const double& val);

        MJArray& operator+=(const MJArray& operand);
        MJArray& operator-=(const MJArray& operand);
        MJArray& operator/=(const MJArray& operand);
        MJArray& operator*=(const MJArray& operand);

        MJArray& operator+=(const double& operand);
        MJArray& operator-=(const double& operand);
        MJArray& operator/=(const double& operand);
        MJArray& operator*=(const double& operand);

        MJArray apply(double f(double)) const;

        inline double operator[](unsigned long i) const;
        inline double& operator[](unsigned long i);

        inline unsigned long size() const;

        void resize(unsigned long newSize);

        double sum() const;
        double max() const;
        double min() const;

        double* begin() const;
        double* end() const;

    private:
        double* ValuesPtr;
        double* EndPtr;
        unsigned long Size;
        unsigned long Capacity;
};

inline double MJArray::operator[](unsigned long i) const{

    #ifdef RANGE_CHECKING
        if(i>=Size){
            throw("Index out of bounds");
        }
    #endif

    return ValuesPtr[i];
}

inline double& MJArray::operator[](unsigned long i){

    #ifdef RANGE_CHECKING
        if(i>=Size){
            throw("Index out of bounds");
        }
    #endif

    return ValuesPtr[i];
}

inline unsigned long MJArray::size() const{
    return Size;
}

#endif //USE_VAL_ARRAY
#endif // ARRAYS_H_INCLUDED
