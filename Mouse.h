#if !defined(MouseH)
#define MouseH

#include "Underground.h"
#include "Nut.h"
#include "MoveableGridItem.h"
#include "constants.h"
#include "RandomNumberGenerator.h"

class Mouse : public MoveableGridItem{
	public:
		//constructor
		Mouse();
		bool isAlive() const;
		bool hasEscaped() const;
		bool hasReachedAHole(const Underground& ug) const;		
		bool canCollectNut() const;
		void getPosition();
		//mutators
		void die();
		void escapeIntoHole();
		void scamper(char k);
	private:
		//data members
		bool alive_;
		bool escaped_;
		bool gotNut_;
		
		//void positionInMiddleOfGrid();
};

#endif // !defined(MouseH)
