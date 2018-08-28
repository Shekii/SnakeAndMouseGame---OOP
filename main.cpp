#include <iostream>


using namespace std;

#include "SnakeAndMouseGame.h"


int main()
{
	Interface ui;
	string name;
	cout << "Please enter your Name: ";
	cin >> name;
	SnakeAndMouseGame game(&ui, name);


	//os.open("SnakeAndMouseGame.txt", ios::out); 
	//if (os.fail()) 
	//	cout << "\nAn error has occurred when opening the file."; 
	//else 
	//	os << game; 
	//os.close();
	//Above for question 9

	game.run();

	ui.holdWindow();
	return 0;
}