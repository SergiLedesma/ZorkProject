#include "creature.h"
#include <iostream>



Creature::Creature(const string name, const string description) : Entity(name,description,parent)
{
	
	type = CREATURE;
}


Creature::~Creature()
{
}
