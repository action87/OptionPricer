/*
 * ParkMillerWithShuffle.cpp
 *
 *  Created on: 2016. jan. 21.
 *      Author: Gabor
 */


#include "ParkMillerWithShuffling.h"
#include "../utils/Arrays.h"
#include  <iostream>

const long a = 16807;
const long m = 2147483647;
const long q = 127773;
const long r = 2836;
const long ntab = 32;
const long ndiv = (1 + (m-1)/ntab);

/*
 * Set seed
 * Load the shuffling table with 8 warm up (we don't use the first 8 numbers)
 * */
ParkMillerWithShuffle::ParkMillerWithShuffle(long Seed_): Seed(Seed_){
	long k;
	shuffleTable.resize(ntab);

	if(Seed == 0) Seed = 1;
	nextElement=0;

	for(long j=ntab + 7;j>=0;j--){
		//std::cout<< "j= " <<j<< std::endl;
		k=Seed/q;
		Seed = a*(Seed - k*q)- r*k;

		if(Seed<0){
			Seed += m;
		}

		if(j<ntab){
			shuffleTable[j]=Seed;
		}
	}
}


void ParkMillerWithShuffle::SetSeed(long Seed_){
	Seed=Seed_;
	long k;
	shuffleTable.resize(ntab);

	if(Seed == 0) Seed = 1;

	for(long j=ntab + 7;j>=0;j--){
		k=Seed/q;
		Seed = a*(Seed - k*q)- r*k;

		if(Seed<0){
			Seed += m;
		}

		if(j<ntab){
			shuffleTable[j]=Seed;
		}
	}
}

unsigned long ParkMillerWithShuffle::Max(){
    return m-1;
}

unsigned long ParkMillerWithShuffle::Min(){
    return 1;
}

long ParkMillerWithShuffle::GetOneRandomInteger(){
	long k;

	k=Seed/q;
	Seed = a*(Seed - k*q)- r*k;

	if(Seed<0){
		Seed += m;
	}

	nextElement = shuffleTable[nextElement] / ndiv;
	long random = shuffleTable[nextElement];
	shuffleTable[nextElement] = Seed;

	return random;
}

RandomParkMillerWithShuffle::RandomParkMillerWithShuffle(unsigned long Dimensionality, unsigned long Seed) :
        RandomBase(Dimensionality),
        InnerGenerator(Seed),
        InitialSeed(Seed)
{
    //std::cout<< "I am here." << std::endl;
    Reciprocal = 1/(1.0 + InnerGenerator.Max());
}

RandomBase* RandomParkMillerWithShuffle::clone() const{
	return new RandomParkMillerWithShuffle(*this);
}

void RandomParkMillerWithShuffle::GetUniforms(MJArray& variates){
    for (unsigned long j=0;j<GetDimensionality();j++){
        variates[j]=InnerGenerator.GetOneRandomInteger()*Reciprocal;
    }
}

void RandomParkMillerWithShuffle::Skip(unsigned long numberOfPaths){
    MJArray tmp(GetDimensionality());
    for(unsigned long j=0;j<numberOfPaths;j++){
        GetUniforms(tmp);
    }

}

void RandomParkMillerWithShuffle::SetSeed(unsigned long Seed){
    InitialSeed = Seed;
    InnerGenerator.SetSeed(Seed);
}

void RandomParkMillerWithShuffle::Reset(){
    InnerGenerator.SetSeed(InitialSeed);
}

void RandomParkMillerWithShuffle::ResetDimensionality(unsigned long NewDimensionality){
    RandomBase::ResetDimensionality(NewDimensionality);
    InnerGenerator.SetSeed(InitialSeed);
}


