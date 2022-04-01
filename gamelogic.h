#pragma once

#include "level.h"

class Player;
class Monster;
class Seed;

class Game{
	public:
		Game(Player *player);
		~Game();
		void render();
		void doControls(char in);
		
	private:
		Player *player;
		Level **levels;
		Seed *seed;
};
