#ifndef __CraftableItem__
#define __CraftableItem__

#include "item.h"


class CraftableItem :
	public Item
{
public:
	list<string> receipe;
	CraftableItem(const string name, const string description, Entity* parent, const ItemType iType, const list<string> receipe);
	virtual ~CraftableItem();
};

#endif