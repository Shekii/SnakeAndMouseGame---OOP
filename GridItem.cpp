#include "GridItem.h"


GridItem::GridItem(const char newSymbol) 
	: symbol_(newSymbol)
{}
char GridItem::getSymbol() const{
	return symbol_;
}