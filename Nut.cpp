//NUT CLASS

#include "Nut.h"


Nut::Nut() : MoveableGridItem(NUT,x_,y_),
	collected_(false)
{
	positionAtRandom();
}

bool Nut::hasBeenCollected() const {
	return collected_;
}
void Nut::disappear() {
	collected_ = !collected_;
}