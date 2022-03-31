#pragma once

const char X_MAX=64;
const char Y_MAX=32;

class Level{
	public:
		Level(unsigned char level, unsigned int seed);
		~Level();
		char getTile(unsigned char x, unsigned char y);
		void setTile(unsigned char x, unsigned char y, char t);
	private:
		char map[Y_MAX][X_MAX];
};
