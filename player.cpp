#include "player.h"
#include "item.h"

const static unsigned int XP_CHART[]={
	100,
	250,
	500,
	1100,
	2000,
	3000,
	5000
};

Player::Player(char *name){
	this->name=name;
	this->level=1;
	this->x=1;
	this->y=1;
	this->xp=0;
	this->xpMax=XP_CHART[this->level];
	this->potions=2;
	this->str=5;
	this->dex=5;
	this->vit=5;
	this->ac=0;
	this->hp=50;
	this->hpMax=this->hp;
	
}

Player::~Player(){
	delete this->name;
}

void Player::hitMonster(Monster *target){
}
