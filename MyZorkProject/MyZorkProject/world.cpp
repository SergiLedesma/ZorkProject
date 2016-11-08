#include <iostream>
#include <string>
#include "world.h"


World::World()
{
	commands = {
		new Command({ "look", "l" }, LOOK, 1),
		new Command({ "go", "g" }, GO, 1),
		new Command({ "take", "pick", "get", "t" }, TAKE, 1),
		new Command({ "drop", "d" }, DROP, 1),
		new Command({ "craft", "c" }, CRAFT, 1),
		new Command({ "eat", "e" }, EAT, 1),
		new Command({ "inventory", "i" }, INVENTORY, 1),
		new Command({ "quit", "q", "exit" }, QUIT, 1),
	};
	
	Room* cliff = new Room("Base of the cliff"s, "You're in the north wall of a big mountain. You can see three paths, one on each direction. In the wall behind you there's a painting."s);
	Room* cave = new Room("Cave"s, "You're inside a small and cold cave. It's a dead end."s);
	Room* forest = new Room("Forest"s, "This is a dense forest. There's a high tree with some branches you can reach."s);
	Room* upTheTree = new Room("Up the tree"s, "After climbing over 5 meters you've reached the top of the tree. From here you can see your camp at the far north."s);
	Room* clearing = new Room("Clearing"s, "You're in a clearing with a forest surrounding you in all directions but east."s);
	Room* path = new Room("Narrow path"s, "It's a very tight path between two mountain walls. You can see ahead some creature's lair, it looks dangerous!"s);
	Room* end = new Room("Smilodon's lair"s, "You face Smilodon: The Saber-toothed cat."s);

	Exit* cliffToPath = new Exit("Cliff to path"s, ""s, cliff, path, NORTH);
	Exit* pathToEnd = new Exit("Path to end"s, ""s, path, end, NORTH);
	Exit* cliffToCave = new Exit("Cave entrance"s, ""s, cliff, cave, EAST);
	Exit* cliffToForest = new Exit("Cliff to forest"s, ""s, cliff, forest, WEST);
	Exit* forestToTree = new Exit("Forest to tree"s, ""s, forest, upTheTree, UP);
	Exit* forestToClearing = new Exit("Forest to clearing"s, ""s, forest, clearing, WEST);

	Creature* monster = new Creature("Smilodon"s, "The Saber-toothed cat"s, end);

	player = new Player("Player"s, "You're a lost hunter and you have to find the way back to your village."s, cliff);

	Item* wallPainting = new Item("Painting"s, "You can see a group of hunters with spears fighting a big mammoth."s, STATIC);

	Item* berry = new Item("Berry"s, "Red, small and juicy fruit."s, FOOD);

	Item* branch = new Item("Branch"s, "A long tree limb."s, MATERIAL);
	Item* flint = new Item("Flint"s, "A small piece of sharp flint."s, MATERIAL);
	Item* vine = new Item("Vine"s, "A long string, it could be used as a rope."s, MATERIAL);

	list<string> spearList;
	spearList.push_back(branch->name);
	spearList.push_back(flint->name);
	spearList.push_back(vine->name);

	cliff->AddItem(wallPainting);
	clearing->AddItem(branch);
	cave->AddItem(flint);
	upTheTree->AddItem(vine);
	forest->AddItem(berry);

	CraftableItem* spear = new CraftableItem("Spear"s, "long and sharp weapon"s, WEAPON, spearList);

	interactables = {player, berry, branch, flint, vine, wallPainting, spear};

}

World::~World()
{
}

Action World::ParseInput(const string& input) {

	Command* command;
	string args;
	bool found = false;

	if (input.size() == 0) {
		return NONE;
	}

	command = GetCommand(input);

	if (command == NULL) {
		return NONE;
	}

	args = command->GetArguments(input);

	switch (command->action) {
		case LOOK:
			if (args.empty()) {
				player->Look(NULL);
			}
			else {
				for (Entity* element : interactables) {
					if (compareString(args, element->name)) {
						player->Look(element);
						found = true;
						break;
					}
				}
				if (!found) {
					printMessage("This item does not exists.");
				}
			}
			break;
		case GO:
			if (args.empty()) {
				player->Go(NOWHERE);
			}
			else {
				for (Direction direction : directionStrings) {
					if (compareString(args, direction)) {
						player->Go(direction);
						found = true;
						break;
					}
				}
				if (!found) {
					printMessage("I didn't understand where you want to go.");
				}
			}
			break;
		case TAKE:
			if (args.empty()) {
				player->Take(NULL);
			}
			else {
				for (Entity* element : interactables) {
					if (compareString(args, element->name)) {
						if (Item* item = dynamic_cast<Item*>(element)) {
							player->Take(item);
							found = true;
							break;
						}
						else {
							printMessage("That's not an item you can take.");
						}
					}
				}
				if (!found) {
					printMessage("This item does not exists.");
				}
			}
			break;
		case DROP:
			if (args.empty()) {
				player->Drop(NULL);
			}
			else {
				for (Entity* element : player->childEntities) {
					if (compareString(args, element->name)) {
						if (Item* item = dynamic_cast<Item*>(element)) {
							player->Drop(item);
							found = true;
							break;
						}
						else {
							printMessage("That's not an item you can drop.");
						}
					}
				}
				if (!found) {
					printMessage("You don't have that item."s);
				}
			}
			break;
		case CRAFT:
			if (args.empty()) {
				player->Craft(NULL);
			}
			else {
				for (Entity* element : interactables) {
					if (compareString(args, element->name)) {
						if (CraftableItem* item = dynamic_cast<CraftableItem*>(element)) {
							player->Craft(item);
							found = true;
							break;
						}
						else {
							printMessage("That's not a craftable item.");
						}
					}
				}
				if (!found) {
					printMessage("This item does not exists.");
				}
			}
			break;
		case EAT:
			if (args.empty()) {
				player->Eat(NULL);
			}
			else {
				for (Entity* element : interactables) {
					if (compareString(args, element->name)) {
						if (Item* item = dynamic_cast<Item*>(element)) {
							player->Eat(item);
							found = true;
							break;
						}
						else {
							printMessage("You can't eat that!");
						}
					}
				}
				if (!found) {
					printMessage("This food does not exists.");
				}
			}
			break;
		case INVENTORY:
			player->Inventory();
			break;
		case QUIT:
		default: 
			return NONE;
	}

	return command->action;
}

Command* World::GetCommand(const string& input) {
	Command* cmd = NULL;
	for (Command* command : commands) {
		if (command->IsCommand(input)) {
			cmd = command;
			break;
		}
	}
	return cmd;
}