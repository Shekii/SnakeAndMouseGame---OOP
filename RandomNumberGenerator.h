// RandomNumberGenerator.h: interface for the RandomNumberGenerator class----------------

#if !defined(RandomNumberGeneratorH)
#define RandomNumberGeneratorH

#include <stdlib.h>	//for srand and rand routines

using namespace std;

class RandomNumberGenerator
{
	public:
		//constructors
		RandomNumberGenerator();
		//assessors
		int getRandomValue(int) const;
	private:
		//supporting functions
		void seed();
};
#endif // !defined(RandomNumberGeneratorH)
