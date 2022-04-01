#include "player.h"
#include "item.h"

#include <iostream>

const static char LEVEL_CAP=40;

Player::Player(char *name){
	this->name=name;
	this->level=1;
	this->dlevel=0;
	this->pos.x=1;
	this->pos.y=1;
	this->points=0;
	this->xp=0;
	this->xpMax=100;
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
	delete this->inv;
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
	if (this->dlevel < MAX_LEVELS){
		this->dlevel++;
	}
}

void Player::upLevel(){
	if (this->dlevel > 1){
		this->dlevel--;
	}
}

void Player::levelUp(){
	this->xp-=this->xpMax;
	if (this->xp < 0){
		this->xp=0;
	}
	if (this->level < LEVEL_CAP){
		this->level++;
		this->xpMax+=this->xpMax>>1;
		this->hpMax+=2;
		this->hp=this->hpMax;
		this->points+=6;
	}
}

void Player::hitMonster(Monster *target){
}

void Player::drawInfo(){
	std::cout << "Dungeon Level: " << (int)this->dlevel << std::endl;
	std::cout << "Level: " << (int)this->level << std::endl;
	std::cout << "HP: " << this->hp << "/" << this->hpMax << std::endl;
	std::cout << "XP: " << this->xp << "/" << this->xpMax << std::endl;
	std::cout << "Points: " << (int)this->points << std::endl;
	
	std::cout << "X: " << (int)this->pos.x << " Y: " << (int)this->pos.y << std::endl;
}
