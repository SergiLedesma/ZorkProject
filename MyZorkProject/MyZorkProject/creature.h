#pragma once
#include "entity.h"
class Creature :
	public Entity
{
public:
	Creature(const string name, const string description);
	virtual ~Creature();
};

