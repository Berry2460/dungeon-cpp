#include "seed.h"

Seed::Seed(){
	this->seed=12345;
}

Seed::~Seed(){
}

unsigned int Seed::getSeed(){
	this->seed=(seed+(seed>>2)+1)%4294967295; //random seed function
	return this->seed;
}
