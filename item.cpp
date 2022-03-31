#include "item.h"

Item::Item(){
}

Item::~Item(){
	if (this->name != nullptr){
		delete this->name;
	}
}
