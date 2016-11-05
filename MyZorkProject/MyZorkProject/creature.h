#ifndef __Creature__
#define __Creature__

#include "entity.h"
#include "room.h"

using namespace std;

class Creature :
	public Entity
{
public:
	Creature(const string name, const string description, Room* room);
	virtual ~Creature();
	Room* room;
};

#endif