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
	};
	
	Room* cliff = new Room("Base of the cliff"s, "You're in the north wall of a big mountain. You can see three paths, one on each direction. In the wall behind you there's a painting."s);
	Room* cave = new Room("Cave"s, "You’re inside a small and cold cave. It’s a dead end."s);
	Room* forest = new Room("Forest"s, "This is a dense forest. There’s a high tree with some branches you can reach."s);
	Room* upTheTree = new Room("Up the tree"s, "After climbing over 5 meters you’ve reached the top of the tree. From here you can see your camp at the far north."s);
	Room* clearing = new Room("Clearing"s, "You’re in a clearing with a forest surrounding you in all directions but east."s);
	Room* path = new Room("Narrow path"s, "It’s a very tight path between two mountain walls. You can see ahead some creature’s lair, it looks dangerous!"s);
	Room* end = new Room("Smilodon's lair"s, "You face Smilodon: The Saber-toothed cat."s);

	Exit* cliffToPath = new Exit("Cliff to path"s, ""s, cliff, path, NORTH);
	Exit* pathToEnd = new Exit("Path to end"s, ""s, path, end, NORTH);
	Exit* cliffToCave = new Exit("Cave entrance"s, ""s, cliff, cave, EAST);
	Exit* cliffToForest = new Exit("Cliff to forest"s, ""s, cliff, forest, WEST);
	Exit* forestToTree = new Exit("Forest to tree"s, ""s, forest, upTheTree, UP);
	Exit* forestToClearing = new Exit("Forest to clearing"s, ""s, forest, clearing, WEST);

	Creature* monster = new Creature("Smilodon"s, "The Saber-toothed cat"s, end);

	player = new Player("The Lost Hunter"s, ""s, cliff);

	Item* wallPainting = new Item("Wall painting"s, "You can see a group of hunters with spears fighting a big mammoth."s, STATIC);

	Item* berry = new Item("Berry"s, "red, small and juicy fruit."s, FOOD);

	Item* branch = new Item("Branch"s, "a long tree limb."s, MATERIAL);
	Item* flint = new Item("Flint"s, "a small piece of sharp flint."s, MATERIAL);
	Item* vine = new Item("Vine"s, "a long string, it could be used as a rope."s, MATERIAL);

	list<string> spearList;
	spearList.push_back(branch->name);
	spearList.push_back(flint->name);
	spearList.push_back(vine->name);

	cliff->AddItem(wallPainting);
	cliff->AddItem(branch);
	cliff->AddItem(flint);
	cliff->AddItem(vine);
	cliff->AddItem(berry);

	CraftableItem* spear = new CraftableItem("Spear"s, "good to kill"s, WEAPON, spearList);

	player->Look(wallPainting);
	player->Take(berry);
	player->Inventory();
	player->Eat(berry);
	player->Inventory();
	player->Craft(spear);
	player->Take(branch);
	player->Take(flint);
	player->Take(vine);
	player->Look(NULL);
	player->Look(branch);
	player->Inventory();
	player->Craft(spear);
	player->Inventory();
}

World::~World()
{
}

bool World::ParseInput(const string& input) {

	if (input.size() == 0) {
		return false;
	}

	

	GetCommand(input);

	/*switch (numberOfWords) {
		case 1:
			if (Globals::compareString(input, "look")) {
				
			}
			break;
		case 2:
			cout << "case 2";
			break;
		default:
			return false;
	}*/

	return true;
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