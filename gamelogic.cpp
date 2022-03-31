#include "gamelogic.h"
#include "player.h"
#include "monster.h"
#include "level.h"

#include <iostream>

Game::Game(Player *player){
	this->player=player;
	this->monsters=new Monster[MAX_MONSTERS];
	this->level=new Level(0, 0);
	
}

Game::~Game(){
	//delete this->player;
	delete [] this->monsters;
}

void Game::render(){
	std::system("cls");
	
	level->setTile(this->player->x, this->player->y, '@');
	
	int startx=this->player->x - 10;
	int endx=this->player->x + 11;
	
	int starty=this->player->y - 5;
	int endy=this->player->y + 6;
	
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
			
			std::cout << level->getTile(x, y);
		}
		std::cout << std::endl;
	}
	
	level->setTile(this->player->x, this->player->y, '.');
}
