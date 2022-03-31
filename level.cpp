#include "level.h"
#include "monster.h"
#include "player.h"

Level::Level(){
}

Level::Level(unsigned char level, unsigned int seed){
	for (int i=0; i<Y_MAX; i++){
		for (int j=0; j<X_MAX; j++){
			this->map[i][j]='.';
			
			if ((i*j+level)%13==1){
				this->map[i][j]='#';
			}
		}
	}
	this->map[5][5]='/';
}

Level::~Level(){
	delete [] this->monsters;
}

char Level::getTile(unsigned char x, unsigned char y){
	return this->map[y][x];
}

void Level::setTile(unsigned char x, unsigned char y, char t){
	this->map[y][x]=t;
}
