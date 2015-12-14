#ifndef ANTITHEHETIC_H_INCLUDED
#define ANTITHEHETIC_H_INCLUDED

#include "Random.h"
#include "../utils/Wrapper.h"


class AntiThetic : public RandomBase{
    public:
        AntiThetic(const Wrapper<RandomBase>& innerGenerator);

        virtual RandomBase* clone() const;
        virtual void GetUniforms(MJArray& variates);
        virtual void Skip(unsigned long numberOfPaths);
        virtual void SetSeed(unsigned long Seed);
        virtual void Reset();

        virtual void ResetDimensionality(unsigned long NewDimensionality);

    private:
        Wrapper<RandomBase> InnerGenerator;
        bool OddEven;
        MJArray NextVariates;

};

#endif // ANTITHEHETIC_H_INCLUDED
