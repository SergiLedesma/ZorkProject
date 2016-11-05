#ifndef __Exit__
#define __Exit__

#include <string>
#include "entity.h"
#include "globals.h"

using namespace std;

class Room;

class Exit :
	public Entity
{
public:
	Room* origin;
	Room* destination;
	Direction direction;

	Exit(const string name, const string description, Room* origin, Room* destination, Direction direction);
	virtual ~Exit();
};

#endif