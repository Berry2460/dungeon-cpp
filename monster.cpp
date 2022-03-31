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
}

const monsterData[]={
	{"Rat", 'r', 1, 1, 2, 1, 3, 0, 50},
	{"Spider", 'p', 1, 1, 3, 1, 3, 1, 50}
};

Monster::Monster(){}

Monster::Monster(unsigned char index, unsigned int seed){
	this->monsterIndex=index;
	this->x=1;
	this->y=1;
	unsigned int var=monsterData[this->monsterIndex].maxHp - monsterData[this->monsterIndex].minHp + 1;
	this->hp=monsterData[this->monsterIndex].minHp + seed%var;
}

Monster::~Monster(){
}
