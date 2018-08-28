
#include "Player.h"

#include <string>


Player::Player(string name) :
name_(name), score_()
{
}

string Player::getName() const{
	return name_;
}


int Player::getScoreAmount() const{
	return score_.getAmount();
}


void Player::updateScoreAmount(int score) {
		score_.updateAmount(score);	
}






