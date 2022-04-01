#include "gamelogic.h"
#include "player.h"
#include "monster.h"
#include "player.h"
#include "seed.h"

#include <iostream>

Game::Game(Player *player){
	this->player=player;
	this->seed=new Seed();
	this->levels=new Level*[MAX_LEVELS];
	for (int i=0; i<MAX_LEVELS; i++){
		this->levels[i]=new Level(i+1, this->seed);
	}
	//enter level
	this->player->downLevel();
	this->levels[this->player->getFloor()]->enterStart(this->player);
}

Game::~Game(){
	delete this->player;
	delete this->seed;
	delete [] this->levels;
}

void Game::render(){
	std::system("cls");
	
	struct Point playerPos=this->player->getPos();
	this->seed->getSeed();
	
	this->levels[this->player->getFloor()]->setTile(playerPos.x, playerPos.y, '@');
	
	int startx=playerPos.x - 10;
	int endx=playerPos.x + 11;
	
	int starty=playerPos.y - 5;
	int endy=playerPos.y + 6;
	
	for (int i=starty; i<endy; i++){
		for (int j=startx; j<endx; j++){
			int x=j;
			int y=i;
			if (x < 0){
				x=0;
			}
			if (y < 0){
				y=0;
			}
			
			if (x >= X_MAX){
				x=X_MAX-1;
			}
			if (y >= Y_MAX){
				y=Y_MAX-1;
			}
			
			std::cout << this->levels[this->player->getFloor()]->getTile(x, y);
		}
		std::cout << std::endl;
	}
	
	this->levels[this->player->getFloor()]->setTile(playerPos.x, playerPos.y, '.');
	this->player->drawInfo();
}

void Game::doControls(char in){
	struct Point playerPos=this->player->getPos();
	
	switch (in){
		case 'w':
			playerPos.y--;
			break;
		case 's':
			playerPos.y++;
			break;
		case 'a':
			playerPos.x--;
			break;
		case 'd':
			playerPos.x++;
			break;
		case 'f':
			player->levelUp();
			break;
	}
	//collision detection
	switch (this->levels[this->player->getFloor()]->getTile(playerPos.x, playerPos.y)){
		case '.': //ground
			this->player->setPos(playerPos);
			break;
		case '/': //downstairs
			this->player->downLevel();
			this->levels[this->player->getFloor()]->enterStart(this->player);
			break;
		case ']': //upstairs
			this->player->upLevel();
			this->levels[this->player->getFloor()]->enterEnd(this->player);
			break;
	}
}
