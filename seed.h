#pragma once

class Seed{
	public:
		Seed(unsigned int start);
		~Seed();
		unsigned int getSeed();
	private:
		unsigned int seed;
};
