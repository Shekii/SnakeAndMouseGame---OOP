#pragma once
#if !defined(GridItemH)
#define GridItemH
#include "constants.h"
class GridItem {
public:
	GridItem(const char newSymbol);
	char getSymbol() const;

protected:
	//data members
	const char symbol_;
};

#endif