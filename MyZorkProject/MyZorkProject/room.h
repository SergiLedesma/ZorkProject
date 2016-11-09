#ifndef __Room__
#define __Room__

#include <list>
#include "entity.h"
#include "globals.h"

using namespace std;

class Exit;
class Item;

class Room :
	public Entity
{
public:
	list<Exit*> childExits;
	Room(const string name, const string description);
	virtual ~Room();
	bool AddExit(Exit* exit);
	bool AddItem(Item* item);
	Room* GetAvaliableRoomFromDirection(const Direction direction);
};

#endif