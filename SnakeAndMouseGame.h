#include "Snake.h"
#include "Nut.h"
#include "Underground.h"
#include "Interface.h"
#include "Player.h"
#include "constants.h"
#include "RandomNumberGenerator.h"

class SnakeAndMouseGame 
{
	public:
		SnakeAndMouseGame(Interface* pui, string);
		Mouse mouse_;
		Snake snake_;
		void run();
		void playAgainMessage(char gameOver, string&);
		void savePositions(int& Sx, int& Sy, int& Mx, int& My);
		void applyRules();
		bool isArrowKeyCode(int& keycode);
		bool findHoleNumberAtPosition(int& x, int& y);
		bool hasEnded(char key);
		string prepareEndMessage();
		string prepareGrid();
private:
		Nut nut_;
		const Underground underground_;
		Interface* p_ui;		
		Player play_;
		int key_;
		void reset();
		bool wantsToCheat(char key);
		string cheat;
		bool cheatMode = false;
};
	ostream& operator<<(ostream& os, const SnakeAndMouseGame&);
	istream& operator>>(istream& is, SnakeAndMouseGame&);