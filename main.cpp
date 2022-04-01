#include "player.h"
#include "item.h"
#include "monster.h"
#include "gamelogic.h"

#include <iostream>
#include <string>

Game *game;

void newGame();

int main(){
	char in;
	while (1){
		newGame();
		
		while(game->isAlive()){
			game->render();
			std::cin >> in;
			game->doControls(in);
		}
		delete game;
	}
	return 0;
}


void newGame(){
	Player *player=new Player("test");
	
	unsigned int seed;
	std::cout << "Starting seed:";
	std::cin >> seed;
	game=new Game(player, seed);
}