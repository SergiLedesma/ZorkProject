#include <string>
#include <iostream>
#include "creature.h"

#pragma once

class Player :
	public Creature
{
public:
	Player(const string name, const string description);
	virtual ~Player();
	bool Take(string asdf);
};