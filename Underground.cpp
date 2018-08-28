// Underground.cpp: implementation of the Underground class 
//////////////////////////////////////////////////////////////////////

#include "Underground.h"

//////////////////////////////////////////////////////////////////////
Underground::Underground() : 
	hole1_(4, 3), 
	hole2_(15, 10),
	hole3_(7, 15),
	holeSymbol_(HOLE)
 
{}

bool Underground::isValidHoleNumber(int no) const {
	return (no >= 1) && (no <= 3); 
}

bool Underground::isAtHolePosition(int x, int y) const
{
	return hole1_.isAtPosition(x, y) || hole2_.isAtPosition(x, y) || hole3_.isAtPosition(x, y);
}

char Underground::getHoleSymbol() const {
	return holeSymbol_;
}
