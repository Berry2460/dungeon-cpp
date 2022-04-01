#pragma once

struct Point{
	char x;
	char y;
};

const static int MAX_LEVELS=255;

const static char X_MAX=48;
const static char Y_MAX=32;

const static unsigned char MAX_MONSTERS=255;

class Monster;
class Seed;
class Player;

class Level{
	public:
		Level();
		Level(unsigned char level, Seed *seed);
		~Level();
		char getTile(unsigned char x, unsigned char y);
		void setTile(unsigned char x, unsigned char y, char t);
		void enterStart(Player *player);
		void enterEnd(Player *player);
	private:
		Monster *monsters;
		char map[Y_MAX][X_MAX];
		Point start;
		Point end;
		unsigned char level;
		
		void generate(Seed *seed);
		void carveRoom(Point start, Point end);
		void carveHall(Point start, Point end);
};
