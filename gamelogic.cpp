#include "gamelogic.h"
#include "player.h"
#include "monster.h"
#include "player.h"
#include "control.h"

#include <iostream>

Game::Game(Player *player){
	this->player=player;
	for (int i=0; i<MAX_LEVELS; i++){
		this->levels[i]=new Level(i+1, 1);
	}
}

Game::~Game(){
	delete this->player;
	delete [] this->levels;
}

void Game::render(){
	std::system("cls");
	
	struct Point playerPos=this->player->getPos();
	
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
			if (y >= X_MAX){
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
	Control::gameControl(this->player, this->levels[this->player->getFloor()], in);
}
