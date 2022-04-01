#include "seed.h"

Seed::Seed(){
	this->seed=1;
}

Seed::~Seed(){
}

unsigned int Seed::getSeed(){
	this->nextSeed();
	return this->seed;
}

void Seed::nextSeed(){
	this->seed=(seed*seed*317)%47 + (seed*seed+1)%2147483647; //random seed function
}
