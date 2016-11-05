#ifndef __CraftableItem__
#define __CraftableItem__

#include "item.h"


class CraftableItem :
	public Item
{
public:
	list<string> neededItems;
	CraftableItem(const string name, const string description, const ItemType iType, const list<string> neededItems);
	virtual ~CraftableItem();
};

#endif