#pragma once

#include "level.h"

const static unsigned char MAX_MONSTERS=255;

class Player;
class Monster;

const int MAX_LEVELS=10;

class Game{
	public:
		Game(Player *player);
		~Game();
		void render();
		void doControls(char in);
		
	private:
		Player *player;
		Level *levels[MAX_LEVELS];
};
