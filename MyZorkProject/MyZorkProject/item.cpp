#include "item.h"



Item::Item(const string name, const string description, const ItemType iType) : Entity(name, description), iType(iType)
{
	type = ITEM;
	
}

Item::~Item()
{
	
}
