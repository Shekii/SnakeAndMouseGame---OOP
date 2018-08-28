
#if !defined(MoveableGridItemh)
#define MoveableGridItemh
#include "GridItem.h"
#include "RandomNumberGenerator.h"

class MoveableGridItem : public GridItem {
public:
	MoveableGridItem(const char s, int x, int y);

	// query
	int getX() const;
	int getY() const;
	bool isAtPosition(int x, int y) const;

	// update
	void resetPosition(int x, int y);
	void updatePosition(int& dx, int& dy);
	void undo();
	void setundo();
	void positionAtRandom();

protected:
	//data members
	int x_, y_;
	int currentx, currenty;
	int prex, prey, middlex, middley;
	int count;
	
};

#endif