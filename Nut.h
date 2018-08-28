#if !defined(NutH)
#define NutH

#include "MoveableGridItem.h"
#include "constants.h"
class Nut: public MoveableGridItem {
public:
	Nut();

	bool hasBeenCollected() const;
	void disappear();

private:
	bool collected_;
};

#endif // !defined(NutH)
