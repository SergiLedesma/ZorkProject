#include "player.h"



Player::Player(const string name, const string description, Room* room) : Creature(name, description, room)
{
	type = PLAYER;
}


Player::~Player()
{
}

bool Player::Go(Direction direction) {
	Room* nextRoom = room->GetAvaliableRoomFromDirection(direction);
	if (nextRoom != NULL) {
		room = nextRoom;
		return true;
	}
	return false;
}

bool Player::Take(string asdf) {
	cout << asdf;
	return true;
}