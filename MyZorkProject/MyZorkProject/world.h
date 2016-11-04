#include "entity.h"
#include "creature.h"
#include "command.h"
#include "player.h"

#pragma once

using namespace std;

class World
{
public:
	World();
	virtual ~World();
	int CountWords(const string& input);
	bool ParseInput(const string& input);

private:
	Player* pol;
};

