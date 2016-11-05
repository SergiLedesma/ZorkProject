#ifndef __Player__
#define __Player__

#include <string>
#include <iostream>
#include "creature.h"
#include "room.h"
#include "globals.h"

class Player :
	public Creature
{
public:
	Player(const string name, const string description, Room * room);
	virtual ~Player();
	bool Go(Direction direction);
	bool Take(string asdf)
};

#endif