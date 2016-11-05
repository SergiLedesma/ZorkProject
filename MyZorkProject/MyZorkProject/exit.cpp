#include "exit.h"
#include "room.h"



Exit::Exit(const string name, const string description, Room* origin, Room* destination, Direction direction) :
	Entity(name, description), direction(direction), origin(origin), destination(destination)
{
	type = EXIT;
	origin->AddExit(this);
	destination->AddExit(this);
}


Exit::~Exit()
{
}
