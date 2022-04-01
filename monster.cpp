#include "monster.h"

struct monsterData{
	const char *name;
	const char graphic;
	unsigned char level;
	unsigned char dmgMin;
	unsigned char dmgMax;
	short minHp;
	short maxHp;
	unsigned char ac;
	unsigned char hit;
	monsterType type;
}

const static monsterData[]={
	{"Rat", 'r', 1, 1, 4, 1, 3, 0, 50, BEAST},
	{"Spider", 'p', 1, 2, 3, 2, 3, 1, 50, BEAST},
	{"Skeleton", 's', 1, 1, 4, 2, 4, 1, 50, UNDEAD},
	{"Fallen", 'f', 1, 2, 4, 2, 4, 1, 50, DEMON},
};

Monster::Monster(){}

Monster::Monster(unsigned char index, unsigned int seed){
	this->monsterIndex=index;
	this->pos.x=1;
	this->pos.y=1;
	unsigned int var=monsterData[this->monsterIndex].maxHp - monsterData[this->monsterIndex].minHp + 1;
	this->hp=monsterData[this->monsterIndex].minHp + seed%var;
}

Monster::~Monster(){
}
