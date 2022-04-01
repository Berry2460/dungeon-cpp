#pragma once

#include "level.h"

class Player;
class Monster;
class Seed;

class Game{
	public:
		Game(Player *player, unsigned int seed);
		~Game();
		void render();
		void doControls(char in);
		bool isAlive();
		
	private:
		Player *player;
		Level **levels;
		Seed *seed;
		bool alive;
};
