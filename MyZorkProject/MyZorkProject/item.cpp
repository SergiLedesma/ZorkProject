#include "item.h"



Item::Item(const string name, const string description, Room* room, const ItemType iType) : Entity(name, description, room), iType(iType)
{
	type = ITEM;
}

Item::~Item()
{
}
