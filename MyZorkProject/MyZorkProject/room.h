#ifndef __Room__
#define __Room__

#include <list>
#include "entity.h"
#include "exit.h"
#include "globals.h"


using namespace std;

class Room :
	public Entity
{
public:
	//list<Exit*> childExits;
	Room(const string name, const string description);
	virtual ~Room();
	bool AddExit(Exit * exit);
	Room* GetAvaliableRoomFromDirection(Direction direction);
};

#endif