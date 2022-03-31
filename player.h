#pragma once

const static char INV_SIZE=10;

class Item;
class Monster;

class Player{
	public:
		Player(char *name);
		~Player();
		void hitMonster(Monster *target);
		int x;
		int y;
		char *name;
		
	private:
		short hp;
		short hpMax;
		unsigned char dmgMin;
		unsigned char dmgMax;
		unsigned char ac;
		unsigned char hit;
		unsigned char level;
		unsigned int xp;
		unsigned int xpMax;
		unsigned char potions;
		Item *inv;
		unsigned char str;
		unsigned char dex;
		unsigned char vit;
};
