#ifndef __World__
#define __World__

#include "globals.h"
#include "entity.h"
#include "creature.h"
#include "command.h"
#include "player.h"
#include "exit.h"
#include "room.h"
#include "item.h"
#include "craftableItem.h"


using namespace std;

class World
{
public:
	World();
	virtual ~World();
	bool ParseInput(const string& input);
	Command * GetCommand(const string& input);

private:
	Player* player;
	list<Command*> commands;
	list<Entity*> interactables;
};

#endif