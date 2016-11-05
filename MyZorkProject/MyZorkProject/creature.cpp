#include <iostream>
#include "creature.h"
#include "room.h"


Creature::Creature(const string name, const string description, Room* room) :
	Entity(name, description), room(room)
{
	type = CREATURE;
}

Creature::~Creature()
{
}
