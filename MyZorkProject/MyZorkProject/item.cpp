#include "item.h"


Item::Item(const string name, const string description, Entity* parent, const ItemType iType) : Entity(name, description, parent), iType(iType)
{
	type = ITEM;
}

Item::~Item()
{
}

bool Item::ChangeParent(Entity* newParent) {
	if (parent != NULL) {
		parent->childEntities.remove(this);
	}
	parent = newParent;
	if (parent != NULL) {
		parent->childEntities.push_back(this);
	}
	return true;
}