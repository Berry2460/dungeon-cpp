#pragma once

#include "level.h"

const static char INV_SIZE=10;

struct Point;

class Item;
class Monster;

class Player{
	public:
		Player(char *name);
		~Player();
		void hitMonster(Monster *target);
		Point getPos();
		void setPos(Point pos);
		unsigned char getFloor();
		void downLevel();
		void upLevel();
		void levelUp();
		void drawInfo();
	private:
		char *name;
		Point pos;
		short hp;
		short hpMax;
		unsigned char points;
		unsigned char dmgMin;
		unsigned char dmgMax;
		unsigned char ac;
		unsigned char hit;
		unsigned char level;
		unsigned char dlevel;
		int xp;
		int xpMax;
		unsigned char potions;
		Item **inv;
		unsigned char str;
		unsigned char dex;
		unsigned char vit;
};
