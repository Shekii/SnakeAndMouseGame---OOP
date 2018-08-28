
#if !defined(PlayerH)
#define PlayerH
#include <string> 
#include "Score.h"
using namespace std;
class Player {
public:

	Player(string);
	
	string getName() const;
	int getScoreAmount() const;
	void updateScoreAmount(int);

private:
	Score score_;
	const string name_;
};

#endif // !defined(PlayerH
