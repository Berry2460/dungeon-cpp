#include "control.h"
#include "player.h"
#include "level.h"

namespace Control{
	void gameControl(Player *player, Level *level, char in){
		struct Point playerPos=player->getPos();
		
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
				//player->downLevel();
				break;
		}
		//collision detection
		switch (level->getTile(playerPos.x, playerPos.y)){
			case '.': //ground
				player->setPos(playerPos);
				break;
			case '/': //stairs
				player->downLevel();
				break;
		}
	}
}
