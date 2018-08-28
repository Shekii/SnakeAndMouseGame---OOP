//--------------------------------
//include standard libraries
#include <iostream>		//for output and input
#include <string>		//for string
#include <sstream>		//for streamstring
#include <fstream>
using namespace std;

#include "SnakeAndMouseGame.h"
						//can not have a global string value
SnakeAndMouseGame::SnakeAndMouseGame(Interface* pui, string name) :
	mouse_(),
	snake_(), nut_(),
	underground_(), 
	p_ui(pui), 
	play_(name)
{
	snake_.setTailPosition(snake_.getX(), snake_.getY());
	snake_.spotMouse(&mouse_);

}
void SnakeAndMouseGame::run() { 
	
	p_ui->drawGridOnScreen(prepareGrid());
	key_ = p_ui->getKeyPressFromUser();
	while (! hasEnded(key_))
	{	
		//==============================UNDO===================================
		if (key_ == UNDO)
		{
			snake_.setundo();
			mouse_.setundo();
			p_ui->drawGridOnScreen(prepareGrid());
		}
		//================================UNDO=================================
		if (isArrowKeyCode(key_))
		{
			mouse_.scamper(key_);
			//========================setting UNDO X and Y=============================
			snake_.undo();
			mouse_.undo();
			//========================end of UNDO======================================
			if (cheatMode == false)		// if cheatMode is turned off.
			{
				snake_.setTailPosition(snake_.getX(), snake_.getY());
				snake_.chaseMouse();
			}
			p_ui->drawGridOnScreen(prepareGrid());
			applyRules();
		}
		else if (wantsToCheat(key_))
		{
			if (cheatMode == false)		// for some reason this works but doesn't make sense to me. 
			{
				cheat = "CHEAT MODE ACTIVATED!";
				p_ui->drawGridOnScreen(prepareGrid());

			}
			else						// this would therefor  be true.
			{
				cheat = "";
				p_ui->drawGridOnScreen(prepareGrid());
				
			}
			
			cheatMode = !cheatMode;	// I reckon *think it is to do with this... Doesn't work properly without it thou	
			
			//This ↑ basically means the if statement below ↓.			
			
			//if (cheatMode == false)
			//{
			//	cheatMode = true;
			//}
			//else
			//{
			//	cheatMode = false;
			//}
		}
		key_ = p_ui->getKeyPressFromUser();
	}
	p_ui->showResultsOnScreen(&prepareEndMessage());
}
string SnakeAndMouseGame::prepareGrid(){
	//prepare a string that holds the grid information

	ostringstream os;

	for (int row(1); row <= SIZE; ++row)	//for each row (vertically)
	{
		for (int col(1); col <= SIZE; ++col)	//for each column (horizontally)
		{
			if (underground_.isAtHolePosition(col, row))
				os << underground_.getHoleSymbol();	//show hole
			else
			if ((row == snake_.getY()) && (col == snake_.getX()))
				os << snake_.getSymbol();	//show snake
			else
			if ((row == snake_.getTailY()[0]) && (col == snake_.getTailX()[0]))
					//// display tail on the grid
					os << snake_.getTailSymbol();	//show tail1
			else
			if ((row == snake_.getTailY()[1]) && (col == snake_.getTailX()[1]))
						os << snake_.getTailSymbol();	//show tail2
			else
			if ((row == snake_.getTailY()[2]) && (col == snake_.getTailX()[2]))
							os << snake_.getTailSymbol();	//show tail3
			else
				if (mouse_.getX() == snake_.getX())
				{
					if (mouse_.getY() == snake_.getY())
					{
						mouse_.positionAtRandom();
					}
				}
			 
			if ((row == mouse_.getY()) && (col == mouse_.getX()))
				os << mouse_.getSymbol();	//show mouse
			else
			if ((nut_.isAtPosition(col,row)) && !nut_.hasBeenCollected())
				os << nut_.getSymbol();	//show nut
			else
				os << FREECELL;	//show free grid cell
		
		} //end of col-loop



		os << endl;
	} //end of row-loop
	os << "Name: " + play_.getName() + "\nScore: ";		
	os << play_.getScoreAmount();
	os << endl << cheat;

	
	return os.str();
} //end prepareGrid
bool SnakeAndMouseGame::isArrowKeyCode(int& keycode) {
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}
void SnakeAndMouseGame::applyRules() {
	if (snake_.hasCaughtMouse())
		mouse_.die();
	else if (mouse_.hasReachedAHole(underground_) && nut_.hasBeenCollected())
		mouse_.escapeIntoHole();
	else if (nut_.getX() == mouse_.getX() && nut_.getY() == mouse_.getY())
		nut_.disappear();
}
void SnakeAndMouseGame::reset() {


	snake_.positionAtRandom();

	mouse_.positionAtRandom();

	nut_.positionAtRandom();

	snake_.restartTail(snake_.getX(), snake_.getY());
	if (nut_.hasBeenCollected() == true) {
		nut_.disappear();
		if (mouse_.hasEscaped() == true)
			mouse_.escapeIntoHole();
	}

	if (mouse_.isAlive() == false) {
		mouse_.die();	
		if (nut_.hasBeenCollected() == true) 
			nut_.disappear();
	}
	
}
bool SnakeAndMouseGame::hasEnded(char key) {
	return ((key == 'Q') || (! mouse_.isAlive()) || (mouse_.hasEscaped()));
}
string SnakeAndMouseGame::prepareEndMessage() {
	ostringstream os;
	string mess;
	if (mouse_.hasEscaped())
	{
		mess = "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND!";
		play_.updateScoreAmount(1);						
		p_ui->drawGridOnScreen(prepareGrid());
		playAgainMessage(key_, mess);
	}
	else
		if (!mouse_.isAlive())
		{
			mess = "\n\nEND OF GAME: THE SNAKE ATE THE MOUSE!";
			play_.updateScoreAmount(-1);
			p_ui->drawGridOnScreen(prepareGrid());
			playAgainMessage(key_, mess);
		}
		else
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
	
	return os.str();
}
void SnakeAndMouseGame::playAgainMessage(char gameOver, string& mess){
		
		cout << mess + "\nWould you like to play again? ";
		cin >> gameOver;
		if (toupper(gameOver) == 'Y')
		{
			reset();
			run();
		}

}

////////////////////////////////////////
void SnakeAndMouseGame::savePositions(int& Sx, int& Sy, int& Mx, int& My)
{
	Sx = snake_.getX();
	Sy = snake_.getY();

	Mx = snake_.getX();
	My = snake_.getY();
}
ostream& operator<<(ostream& os, const SnakeAndMouseGame& game){
	os << game.mouse_.getX();
	os << "\n";
	os << game.mouse_.getY();
	os << "\n";
	os << game.snake_.getX();
	os << "\n";
	os << game.snake_.getY();

	return os;
}
istream& operator>>(istream& is, SnakeAndMouseGame& game){
	int sX, sY, mX, mY;

	is >> sX >> sY >> mX >> mY;

	return is;
}
bool SnakeAndMouseGame::wantsToCheat(char key){
	return (key == 'C');
}
