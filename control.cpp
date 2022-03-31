#include "control.h"
#include "player.h"

namespace Control{
	void gameControl(Player *player, char in){
		switch (in){
			case 'w':
				player->y--;
				break;
			case 's':
				player->y++;
				break;
			case 'a':
				player->x--;
				break;
			case 'd':
				player->x++;
				break;
		}
	}
}
