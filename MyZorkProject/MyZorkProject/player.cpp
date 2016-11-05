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

bool Player::Take(Item* item) {
	bool found = false;
	for (Entity* iter : room->childEntities) {
		if (iter->name == item->name) {
			found = true;
			break;
		}
	}
	if (found) {
		room->childEntities.remove((Entity*)item);
		childEntities.push_back((Entity*)item);
	}
	return found;
}

bool Player::Drop(Item* item) {
	bool found = false;
	for (Entity* iter : childEntities) {
		if (iter->name.compare(item->name)) {
			found = true;
			break;
		}
	}
	if (found) {
		childEntities.remove((Entity*)item);
		room->childEntities.push_back((Entity*)item);
	}
	return found;
}

bool Player::Craft(CraftableItem* craftableItem) {
	bool found;
	bool crafted = true;
	list<Item*> foundItems;

	for (string itemName : craftableItem->neededItems) {
		found = false;
		for (Entity* entity : childEntities) {
			if (entity->name.compare(itemName)) {
				found = true;
				foundItems.push_back((Item*)entity);
				break;
			}
		}
		if (!found) {
			crafted = false;
			break;
		}
	}

	if (crafted) {
		for (Item* item : foundItems) {
			childEntities.remove(item);
		}
		childEntities.push_back(craftableItem);
		string message = craftableItem->name + " crafted and added to the inventory"s;
		Globals::printMessage(message);
	}
	return crafted;
}

bool Player::Look(Entity* entity) {
	if (entity == NULL) {
		Globals::printMessage(room->name,room->description);
	}
	else {
		Globals::printMessage(entity->description);
	}
	return true;
}

bool Player::Eat(Item* item) {
	bool found = false;
	for (Entity* iter : childEntities) {
		if (iter->name == item->name) {
			found = true;
			break;
		}
	}
	if ((found) && (item->iType == FOOD)){
		childEntities.remove((Entity*)item);
		Globals::printMessage("Nom nom nom! Delicious!"s);
	}
	return found;
}

void Player::Inventory() {
	if (childEntities.empty() == false) {
		for (Entity* iter : childEntities) {
			Globals::printMessage(iter->name);
		}
	}
	else {
		Globals::printMessage("You have no items!");
	}
}