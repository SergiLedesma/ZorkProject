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
	int CountWords(const string& input);
	bool ParseInput(const string& input);

private:
	Player* player;
};

#endif