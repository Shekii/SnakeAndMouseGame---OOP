#include "Score.h"


Score::Score() :
amount_(0)
{}

int Score::getAmount() const{
	return amount_;
}
void Score::updateAmount(int incAmount){
	
	if (incAmount == -1)
		if (amount_ > 0)
			amount_ += incAmount;


	if (incAmount == 1)
			amount_ += incAmount;
}


