// Mouse.cpp: implementation of the Mouse class
//////////////////////////////////////////////////////////////////////

#include "Mouse.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Mouse::Mouse():MoveableGridItem(MOUSE,x_,y_),   
alive_(true), escaped_(false), gotNut_(false)
{
	positionAtRandom();
}
//////////////////////////////////////////////////////////////////////
// Public functions
//////////////////////////////////////////////////////////////////////

bool Mouse::isAlive() const {
	return alive_;
}
bool Mouse::hasEscaped() const {
	return escaped_;
}
bool Mouse::hasReachedAHole(const Underground& ug) const {

	return (ug.isAtHolePosition(x_, y_));
}
bool Mouse::canCollectNut() const {
	bool canCollect = false;

	if (!gotNut_)
		canCollect = true;

	return canCollect;
}
void Mouse::die() {
	alive_ = !alive_;
}
void Mouse::escapeIntoHole() 
{
	escaped_ = !escaped_;
}
void Mouse::scamper(char k) { //move mouse in required direction
  //pre: Key is an arrow representing the direction in which the mouse moves
	//find direction indicated by key
	int mouseDX_;
	int mouseDY_;
	switch(k)               //...depending on the selected key...
	{
		case LEFT:           //when LEFT arrow pressed...
			mouseDX_ = -1;    //decrease the X coordinate
			mouseDY_ = 0;
			break;
		case RIGHT:          //when RIGHT arrow pressed...
			mouseDX_ = +1;    //increase the X coordinate
			mouseDY_ = 0;
			break;
		case UP:             //when UP arrow pressed...
			mouseDX_ = 0;
			mouseDY_ = -1;    //decrease the Y coordinate
			break;
		case DOWN:           //when DOWN arrow pressed...
			mouseDX_ = 0;
			mouseDY_ = +1;    //increase the Y coordinate
			break;
	}
	//update mouse coordinates if move is possible
	if (((x_ + mouseDX_) >= 1) && ((x_ + mouseDX_) <= SIZE) &&
		 ((y_ + mouseDY_) >= 1) && ((y_ + mouseDY_) <= SIZE) )
	{
		updatePosition(mouseDX_, mouseDY_);		//go in that direction
	}
}
////////////////////////////////////////////////////////////////////
// Private functions
//////////////////////////////////////////////////////////////////////
//void Mouse::positionInMiddleOfGrid() {
//	x_ = SIZE /2;
//	y_ = SIZE /2;
//}
