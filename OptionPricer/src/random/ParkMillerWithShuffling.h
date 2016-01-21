/*
 * ParkMillerWithShuffling.h
 *
 *  Created on: 2016. jan. 21.
 *      Author: Gabor
 */

#ifndef RANDOM_PARKMILLERWITHSHUFFLING_H_
#define RANDOM_PARKMILLERWITHSHUFFLING_H_

#include "Random.h"
#include "../utils/Arrays.h"

class ParkMillerWithShuffle{
    public:
		ParkMillerWithShuffle(long Seed = 1);

        long GetOneRandomInteger();
        void SetSeed(long Seed);

        static unsigned long Max();
        static unsigned long Min();


    private:
        long Seed;
        MJArray shuffleTable;
        unsigned long nextElement;

};

class RandomParkMillerWithShuffle : public RandomBase{
    public:
		RandomParkMillerWithShuffle(unsigned long Dimensionality, unsigned long Seed=1);

        virtual RandomBase* clone() const;
        virtual void GetUniforms(MJArray& variates);
        virtual void Skip(unsigned long numberOfPaths);
        virtual void SetSeed(unsigned long Seed);
        virtual void Reset();

        virtual void ResetDimensionality(unsigned long NewDimensionality);

    private:
        ParkMillerWithShuffle InnerGenerator;
        unsigned long InitialSeed;
        double Reciprocal;
};

#endif /* RANDOM_PARKMILLERWITHSHUFFLING_H_ */
