#include "seed.h"
#include <iostream>

Seed::Seed(){
	this->seed=12345;
}

Seed::~Seed(){
}

unsigned int Seed::getSeed(){
	this->nextSeed();
	return this->seed;
}

void Seed::nextSeed(){
	this->seed=(seed+(seed>>2)+1)%4294967295; //random seed function
	std::cout << this->seed << std::endl;
}
