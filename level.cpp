#include "level.h"
#include "monster.h"
#include "player.h"
#include "seed.h"

Level::Level(unsigned char level, Seed *seed){
	this->level=level;
	this->generate(seed);
	this->monsters=nullptr;
}

Level::~Level(){
	if (this->monsters != nullptr){
		delete [] this->monsters;
	}
}

void Level::generate(Seed *seed){
	//fill
	for (int i=0; i<Y_MAX; i++){
		for (int j=0; j<X_MAX; j++){
			this->map[i][j]='#';
		}
	}
	
	unsigned int rng;
	bool done=false;
	int startxVar=0;
	int startyVar=0;
	int endxVar=0;
	int endyVar=0;
	int floor=1;
	Point prevConnect;
	int prevX;
	
	bool startPlaced=false;
	bool endPlaced=false;
	int placex;
	int placey;
	
	//room counter to place start/end
	int roomCount=0;
	//place start
	rng=seed->getSeed();
	int startAfter=rng%3;
	//place end
	rng=seed->getSeed();
	int endAfter=rng%4+3;
	//swap start/end
	rng=seed->getSeed();
	if (rng%2 == 0){
		int temp=startAfter;
		startAfter=endAfter;
		endAfter=temp;
	}
	//for hall gen
	bool newRow;
	
	//carve rooms
	while (!done){
		prevX=startxVar; //for shifting back rows
		prevConnect={(char)(endxVar), (char)startyVar}; //for connecting halls
		
		//gen start point
		rng=seed->getSeed();
		startxVar+=rng%4+3;
		
		rng=seed->getSeed();
		startyVar=floor+rng%3+1;
		
		//gen end point
		rng=seed->getSeed();
		endxVar=startxVar + rng%5+6;
		
		rng=seed->getSeed();
		endyVar=startyVar + rng%4+4;
		
		//detect new row
		if (endxVar >= X_MAX-1){
			startxVar-=prevX;
			endxVar-=prevX;
			floor+=endyVar-startyVar+3;
			//update for new row halls
			prevConnect.x-=prevX;
			newRow=true;
			continue;
		}
		else{
			newRow=false;
		}
		
		//check if done
		if (endyVar >= Y_MAX-1){
			done=true;
		}
		else{ //carve room
			placex=startxVar-1 + ((endxVar-startxVar)>>1);
			placey=startyVar + ((endyVar-startyVar)>>1);
			
			Point start={(char)startxVar, (char)startyVar};
			Point end={(char)endxVar, (char)endyVar};
			
			this->carveRoom(start, end);
			
			rng=seed->getSeed();
			prevConnect.y+=rng%3+1; //avoid akward looking halls
			if (roomCount > 0){
				if (newRow){
					prevConnect.x+=4;
				}
				this->carveHall(prevConnect, start);
			}
			
			startxVar+=endxVar-startxVar;
			//place start
			if (!startPlaced && roomCount >= startAfter){
				if (this->level > 1){
					this->map[placey][placex]=']';
				}
				startPlaced=true;
				this->start={(char)(placex+1), (char)placey}; //offset by 1
			}
			//place end
			else if (!endPlaced && roomCount > endAfter && this->level < MAX_LEVELS){
				rng=seed->getSeed();
				this->map[placey][placex]='/';
				endPlaced=true;
				this->end={(char)(placex+1), (char)placey}; //offset by 1
			}
		}
		roomCount++;
	}
}

void Level::carveHall(Point start, Point end){
	int bigX;
	int smallX;
	int bigY;
	int smallY;
	
	if (start.x > end.x){
		bigX=start.x;
		smallX=end.x;
	}else{
		bigX=end.x;
		smallX=start.x;
	}
	
	if (start.y > end.y){
		bigY=start.y;
		smallY=end.y;
	}else{
		bigY=end.y;
		smallY=start.y;
	}
	
	for (int i=smallY; i<=bigY; i++){
		if (this->map[i][end.x] == '#'){
			this->map[i][end.x]='.';
		}
	}
	
	for (int i=smallX; i<=bigX; i++){
		if (this->map[start.y][i] == '#'){
			this->map[start.y][i]='.';
		}
	}
}

void Level::carveRoom(Point start, Point end){
	for (int i=start.y; i<end.y; i++){
		for (int j=start.x; j<end.x; j++){
			this->map[i][j]='.';
		}
	}
}

void Level::enterStart(Player *player){
	player->setPos(this->start);
}

void Level::enterEnd(Player *player){
	player->setPos(this->end);
}

char Level::getTile(unsigned char x, unsigned char y){
	return this->map[y][x];
}

void Level::setTile(unsigned char x, unsigned char y, char t){
	this->map[y][x]=t;
}
