#include "MoveableGridItem.h"

MoveableGridItem::MoveableGridItem(const char s, int x, int y)
	:GridItem(s), x_(x), y_(y), prex(x_), prey(y_)
{
	currentx = x_;
	currenty = y_;
}


int MoveableGridItem::getX ()const{
	return x_;
}
int MoveableGridItem::getY()const{
	return y_;
}
bool MoveableGridItem::isAtPosition(int x, int y) const{
	return (x_ == x) && (y_ == y);
}
void MoveableGridItem::updatePosition(int& dx, int& dy) {
	x_ += dx;
	y_ += dy;
}
void MoveableGridItem::resetPosition(int x, int y) {
	x_ = x;
	y_ = y;
}
void MoveableGridItem::undo(){
	if (prex != x_ || prey!=y_)
	{
		prex = currentx;
		prey = currenty;
		currentx = x_;
		currenty = y_;
		
	}


}
void MoveableGridItem::setundo()
{
	x_ = prex;
	y_ = prey;
	currentx = x_;
	currenty = y_;
}

void MoveableGridItem::positionAtRandom() {


	static RandomNumberGenerator rng;
	x_ = rng.getRandomValue(SIZE);
	y_ = rng.getRandomValue(SIZE);
}