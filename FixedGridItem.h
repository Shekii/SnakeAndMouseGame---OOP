#if !defined(FixedGridItemh)
#define FixedGridItemh
#include "GridItem.h"
class FixedGridItem : public GridItem {
public:
	FixedGridItem(const char s, int x, int y);
	int getX() const;
	int getY() const;
	bool isAtPosition(int x, int y) const;

protected:
	//data members
	const int x_, y_;
};

#endif