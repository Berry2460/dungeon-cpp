#pragma once

#include "level.h"

enum monsterType: unsigned char{
	UNDEAD,
	BEAST,
	DEMON
};

class Monster{
	public:
		Monster();
		Monster(unsigned char index, unsigned int seed);
		~Monster();

	private:
		struct Point pos;
		short hp;
		unsigned char monsterIndex;
};
