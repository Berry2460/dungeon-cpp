#pragma once

struct Point{
	char x;
	char y;
};

const char X_MAX=64;
const char Y_MAX=32;

class Monster;

class Level{
	public:
		Level();
		Level(unsigned char level, unsigned int seed);
		~Level();
		char getTile(unsigned char x, unsigned char y);
		void setTile(unsigned char x, unsigned char y, char t);
	private:
		Monster *monsters;
		char map[Y_MAX][X_MAX];
		Point start;
		Point end;
};
