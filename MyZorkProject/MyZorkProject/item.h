#ifndef __Item__
#define __Item__

#include "entity.h"
#include "room.h"


using namespace std;

enum ItemType
{
	FOOD,
	MATERIAL,
	WEAPON,
	COMMON,
	CONTAINER,
	STATIC
};

class Item :
	public Entity
{
public:
	Item(const string name, const string description, Entity* parent, const ItemType iType);
	virtual ~Item();
	bool ChangeParent(Entity * newParent);
	ItemType iType;
};

#endif