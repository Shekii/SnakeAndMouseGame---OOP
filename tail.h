#if !defined(Tailh)
#define Tailh

#include "Snake.h"
class Tail
{
public:
	Tail(int x, int y);
	int getX() const;
	int getY() const;
	char getSymbol() const;
	void updatePosition(int dx, int dy);
private:
	char symbol_;
	int  x_, y_;
};

#endif