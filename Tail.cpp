using namespace std;

#include "Tail.h"


Tail::Tail(int x, int y) : symbol_(TAIL), x_(x), y_(y) {

}

int Tail::getX() const{
	return x_;
}
int Tail::getY() const{
	return y_;
}
char Tail::getSymbol() const{
	return symbol_;
}



void Tail::updatePosition(int x, int y){
	x_ = x;
	y_ = y;
}

