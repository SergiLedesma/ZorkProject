#include <string>
#include <list>

#pragma once

using namespace std;

enum EntityType
{
	ENTITY,
	CREATURE,
	NPC,
	PLAYER,
	EXIT,
	ROOM,
	ITEM
};

class Entity
{
public:
	EntityType type;
	string name;
	string description;
	Entity* parent;
	list<Entity*> childEntities;

	Entity(const string name, const string description, Entity* parent);
	Entity(const string name, const string description);
	virtual ~Entity();
};

