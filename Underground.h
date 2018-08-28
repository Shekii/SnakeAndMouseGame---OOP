// Underground.h: interface for the Underground class 

#if !defined(UndergroundH)
#define UndergroundH
#include <cassert>
#include "Hole.h"


class Underground {
public:
	Underground();
	void setHoleNoAtPosition(int no, int x, int y);
	bool isValidHoleNumber(int n) const;
	bool isAtHolePosition(int x, int y) const;
	char getHoleSymbol() const;

private:
	const Hole hole1_, hole2_, hole3_;
	const char holeSymbol_;
};	

#endif // !defined(UndergroundH) 
