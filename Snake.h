// Snake.h: interface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH


#include "Mouse.h"
#include <vector>
#include "MoveableGridItem.h"
#include "tail.h"

#include "RandomNumberGenerator.h"
class Tail;
class Snake : public MoveableGridItem{
	public:
		
		Snake();
		bool hasCaughtMouse() const;
		void spotMouse(Mouse* p_mouse);
		void chaseMouse();


		char getTailSymbol();
		void moveTail(int dx, int dy);
		void restartTail(int x, int y);
		vector<int> getTailX();
		vector<int> getTailY();
		void setTailPosition(int x, int y);
		
private:
		void initialiseTail();
		//Tail vector
		vector<Tail> tail_;
		//tail symbol
		char symbolT_;
		void setDirection(int& dx, int& dy);
		Mouse* p_mouse_;
		

};	

#endif // !defined(SnakeH)
