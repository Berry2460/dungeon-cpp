#include "player.h"
#include "item.h"

#include <iostream>

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
	this->dlevel=1;
	this->pos.x=1;
	this->pos.y=1;
	this->points=0;
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

Point Player::getPos(){
	return this->pos;
}

unsigned char Player::getFloor(){
	return this->dlevel-1;
}

void Player::setPos(Point playerPos){
	this->pos=playerPos;
}

void Player::downLevel(){
	this->dlevel++;
}

void Player::upLevel(){
	this->dlevel--;
}

void Player::levelUp(){
	this->level++;
	this->points+=6;
}

void Player::hitMonster(Monster *target){
}

void Player::drawInfo(){
	std::cout << "Dungeon Level: " << (int)this->dlevel << std::endl;
	std::cout << "HP: " << this->hp << "/" << this->hpMax << std::endl;
}
