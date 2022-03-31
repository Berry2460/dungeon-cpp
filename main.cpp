#include "player.h"
#include "item.h"
#include "monster.h"
#include "gamelogic.h"
#include "control.h"

#include <iostream>

static bool gameLoop=true;

int main(){
	Player *player=new Player("test");
	Game *game=new Game(player);
	char in;
	while(gameLoop){
		game->render();
		std::cin >> in;
		Control::gameControl(player, in);
	}
	return 0;
}
