#ifndef __Item__
#define __Item__

#include "entity.h"
#include "room.h"

using namespace std;

enum ItemType
{
	FOOD,
	MATERIAL,
	WEAPON
};

class Item :
	public Entity
{
public:
	Item(const string name, const string description, Room * room, const ItemType iType);
	virtual ~Item();

	ItemType iType;
};

#endif