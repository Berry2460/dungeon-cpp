#pragma once

class Monster{
	public:
		Monster();
		Monster(unsigned char index, unsigned int seed);
		~Monster();
		
		int x;
		int y;
		
	private:
		short hp;
		unsigned char monsterIndex;
};
