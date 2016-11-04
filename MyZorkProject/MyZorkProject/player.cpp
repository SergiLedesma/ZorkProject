#include "player.h"



Player::Player(const string name, const string description) : Creature(name, description)
{
}


Player::~Player()
{
}

bool Player::Take(string asdf) {
	cout << asdf;
	return true;
}