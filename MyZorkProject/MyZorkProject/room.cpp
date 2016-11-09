#include "room.h"
#include "exit.h"



Room::Room(const string name, const string description) : Entity(name, description)
{
	type = ROOM;
	childExits = {};
}


Room::~Room()
{
}


bool Room::AddExit(Exit* exit) {
	childExits.push_back(exit);
	return true;
}

bool Room::AddItem(Item* item) {
	childEntities.push_back((Entity*)item);
	return true;
}

Room* Room::GetAvaliableRoomFromDirection(const Direction direction) {
	Room* result = NULL;
	
	for (Exit* iter : childExits) {
		if (iter->origin == this && direction == iter->direction) {
			result = iter->destination;
			break;
		}
		else if (iter->destination == this && -direction == iter->direction) {     //The negative value of a direction is the inverse of that direction.
			result = iter->origin;
			break;
		}
	}
	
	return result;
}