#include "level.h"

Level::Level(unsigned char level, unsigned int seed){
	for (int i=0; i<Y_MAX; i++){
		for (int j=0; j<X_MAX; j++){
			this->map[i][j]='#';
		}
	}
}

Level::~Level(){
}

char Level::getTile(unsigned char x, unsigned char y){
	return this->map[y][x];
}

void Level::setTile(unsigned char x, unsigned char y, char t){
	this->map[y][x]=t;
}
