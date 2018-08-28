// Snake.cpp: implementation of the Snake class
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////

#include "Snake.h"


Snake::Snake():MoveableGridItem(SNAKEHEAD,x_,y_) {

	positionAtRandom();
	
	p_mouse_ = nullptr; //to make the pointer is safe before the snake spots the mouse
	symbolT_ = TAIL;
	initialiseTail();

}

bool Snake::hasCaughtMouse() const {
	assert(p_mouse_ != 0);  //Pre-condition: The snake needs to know where the mouse is 
	return isAtPosition(p_mouse_->getX(), p_mouse_->getY());
}
void Snake::spotMouse(Mouse* p_mouse) {
	p_mouse_ = p_mouse;		
	
}
void Snake::chaseMouse() {	 
	int snakeDX, snakeDY;
	//identify direction of travel
	setDirection(snakeDX, snakeDY);
	//go in that direction
	updatePosition(snakeDX, snakeDY);
}

//void Snake::positionAtRandom() {
//
//	
//	static RandomNumberGenerator rng;
//	x_ = rng.getRandomValue(SIZE);        
//	y_ = rng.getRandomValue(SIZE);
//}


//////////////////////////////////////////////////////////////////////
// Private functions
//////////////////////////////////////////////////////////////////////


void Snake::setDirection(int& dx, int& dy)
{
	assert(p_mouse_ != 0);  //Pre-condition: The snake needs to know where the mouse is 
	//assume snake only move when necessary
	dx = 0; dy = 0;
	//update coordinate if necessary
	if (x_ < p_mouse_->getX())             //if snake on left of mouse
		dx = 1;                          //snake should move right
	else                                    //otherwise
		if (x_ > p_mouse_->getX())         //if snake on left of mouse
			dx = -1;                     //snake should move left
	if (y_ < p_mouse_->getY())             //if snake is above mouse
		dy = 1;                          //snake should move down
	else                                    //otherwise
		if (y_ > p_mouse_->getY())         //if snake is below mouse
			dy = -1;                     //snake should move up
}

void Snake::restartTail(int x, int y){
	tail_[2] = { x, y };
	tail_[1] = { x, y };
	tail_[0] = { x, y };
}

char Snake::getTailSymbol() {
	return symbolT_;
}

vector<int> Snake::getTailX(){
	vector<int> x;
	for (int i = 0; i < 3; i++)
	{
		x.push_back(tail_[i].getX());
	}

	return x;
}

vector<int> Snake::getTailY(){
	vector<int> y;
	for (int i = 0; i < 3; i++)
	{
		y.push_back(tail_[i].getY());
	}
	return y;
}

void Snake::initialiseTail(){
	//creates 3 tail elements
	tail_.push_back(Tail(x_, y_));
	tail_.push_back(Tail(x_, y_));
	tail_.push_back(Tail(x_, y_));

}

void Snake::setTailPosition(int x, int y){
	//sets the position of tail so it follows snake

	tail_[2] = { tail_[1].getX(), tail_[1].getY() };
	tail_[1] = { tail_[0].getX(), tail_[0].getY() };
	tail_[0] = { x, y };
}