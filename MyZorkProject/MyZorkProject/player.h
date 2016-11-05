#ifndef __Player__
#define __Player__

#include <string>
#include <iostream>
#include "creature.h"
#include "globals.h"
#include "room.h"
#include "item.h"
#include "craftableItem.h"

using namespace std;

class Player :
	public Creature
{
public:
	Player(const string name, const string description, Room * room);
	virtual ~Player();
	bool Go(Direction direction);
	bool Take(Item* item);
	bool Drop(Item* item);
	bool Craft(CraftableItem * item);
	bool Look(Entity* entity);
	bool Eat(Item* item);
	void Inventory();
};

#endif