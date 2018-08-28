#include "FixedGridItem.h"

FixedGridItem::FixedGridItem(const char s, int x, int y)
	: GridItem(s) ,x_(x), y_(y)
{}
int FixedGridItem::getX() const{
	return x_;
}
int FixedGridItem::getY() const{
	return y_;
}
bool FixedGridItem::isAtPosition(int x, int y)const{
	return (x_ == x) && (y_ == y);
}