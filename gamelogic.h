#pragma once

const static unsigned char MAX_MONSTERS=255;

class Player;
class Monster;
class Level;

class Game{
	public:
		Game(Player *player);
		~Game();
		void render();
	private:
		Player *player;
		Monster *monsters;
		Level *level;
};
