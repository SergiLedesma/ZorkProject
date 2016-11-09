#include "player.h"

Player::Player(const string name, const string description, Room* room) : Creature(name, description, room)
{
	type = PLAYER;
}

Player::~Player()
{
}

MovementState Player::Go(Direction direction) {
	if (direction == NOWHERE) {
		printMessage("You didn't say which direction you want to go to.");
		return NOTMOVING;
	}
	Room* nextRoom = room->GetAvaliableRoomFromDirection(direction);
	if (nextRoom != NULL) {
		room = nextRoom;
		Look(NULL);
		if (compareString(room->name, "Smilodon's lair"s)) {
			return ENDING;
		}
		else {
			return MOVING;
		}
	}
	printMessage("You can't go that way.");
	return NOTMOVING;
}

bool Player::Take(Item* item) {
	if (item == NULL) {
		printMessage("You didn't say what you want to take.");
		return false;
	}
	bool found = false;
	for (Entity* iter : room->childEntities) {
		if (compareString(iter->name, item->name)) {
			if (item->iType != STATIC) {
				found = true;
				break;
			}
			else {
				printMessage("You can't take that!");
				return false;
			}
		}
	}
	if (found) {
		room->childEntities.remove((Entity*)item);
		childEntities.push_back((Entity*)item);
		printMessage(item->name + " taken."s);
	}
	else {
		printMessage(item->name + " not found in this room."s);
	}
	return found;
}

bool Player::Drop(Item* item) {
	if (item == NULL) {
		printMessage("You didn't say what you want to drop.");
	}
	bool found = false;
	for (Entity* iter : childEntities) {
		if (compareString(iter->name, item->name)) {
			if (item->iType != STATIC) {
				found = true;
				break;
			}
		}
	}
	if (found) {
		childEntities.remove((Entity*)item);
		room->childEntities.push_back((Entity*)item);
		printMessage(item->name + " dropped."s);
	}
	else {
		printMessage("You don't have that item."s);
	}
	return found;
}

bool Player::Craft(CraftableItem* craftableItem) {
	if (craftableItem == NULL) {
		printMessage("You didn't say what you want to craft.");
	}
	bool found;
	bool crafted = true;
	list<Item*> foundItems;

	for (string itemName : craftableItem->neededItems) {
		found = false;
		for (Entity* entity : childEntities) {
			if (compareString(entity->name, itemName)) {
				found = true;
				foundItems.push_back((Item*)entity);
				break;
			}
		}
		if (!found) {
			crafted = false;
			printMessage("You don't have all the materials needed to craft this."s);
			break;
		}
	}

	if (crafted) {
		for (Item* item : foundItems) {
			childEntities.remove(item);
		}
		childEntities.push_back(craftableItem);
		string message = craftableItem->name + " crafted and added to the inventory."s;
		printMessage(message);
	}
	return crafted;
}

bool Player::Look(Entity* entity) {
	bool found = false;
	if (entity == NULL) {
		printMessage(room->name,room->description);
		if (room->childEntities.empty() == false) {
			printMessage("In this place you can see:");
			for (Entity* object : room->childEntities) {
				string obj = object->name;
				obj[0] = (char)tolower(object->name[0]);
				printMessage("A " + obj);
			}
		}
		return true;
	}
	else if (compareString(entity->name, "player"s)) {
		printMessage(description);
		return true;
	}
	else {
		for (Entity* iter : childEntities) {
			if (compareString(iter->name, entity->name)) {
				found = true;
				break;
			}
		}
		if (!found) {
			for (Entity* iter : room->childEntities) {
				if (compareString(iter->name, entity->name)) {
					found = true;
					break;
				}
			}
		}
	}
	if (found) {
		printMessage(entity->description);
	}
	else {
		printMessage("That's not something you can find in this room nor in your inventory."s);
	}
	return found;
}

bool Player::Eat(Item* item) {
	bool found = false;
	for (Entity* iter : childEntities) {
		if (compareString(iter->name, item->name)) {
			found = true;
			break;
		}
	}
	if (found) {
		if (item->iType == FOOD){
			childEntities.remove((Entity*)item);
			printMessage("Nom nom nom! Delicious!"s);
		}
		else {
			printMessage("You can't eat that!"s);
		}
	}
	else {
		printMessage("You don't have that."s);
	}
	return found;
}

void Player::Inventory() {
	if (childEntities.empty() == false) {
		printMessage("Inventory:");
		for (Entity* iter : childEntities) {
			printMessage("- " + iter->name);
		}
	}
	else {
		printMessage("You have no items!");
	}
}