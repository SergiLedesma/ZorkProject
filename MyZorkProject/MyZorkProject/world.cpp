#include <iostream>
#include <string>
#include "world.h"


World::World()
{
	Room* cliff = new Room("Base of the cliff"s, "North of the cliff. You can see three paths, one on each direction. In the wall behind you there's a painting."s);
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

	Item* berry = new Item("Berry"s, "good food"s, FOOD);

	Item* branch = new Item("Branch"s, "good food"s, FOOD);
	Item* flint = new Item("Flint"s, "good food"s, FOOD);
	Item* vine = new Item("Vine"s, "good food"s, FOOD);

	list<string> spearList;
	spearList.push_back(branch->name);
	spearList.push_back(flint->name);
	spearList.push_back(vine->name);

	cliff->AddItem(branch);
	cliff->AddItem(flint);
	cliff->AddItem(vine);


	CraftableItem* spear = new CraftableItem("Spear"s, "good to kill"s, WEAPON, spearList);

	cliff->AddItem(berry);
	player->Take(berry);
	player->Inventory();
	player->Eat(berry);
	player->Inventory();
	player->Craft(spear);
	player->Take(branch);
	player->Take(flint);
	player->Take(vine);
	player->Craft(spear);
}

World::~World()
{
}

int World::CountWords(const string& input) {
	int numberOfWords = 1;
	
	for (char letter : input) {
		if (isspace(letter)) {
			numberOfWords++; //fer un split de l'input
		}
	}

	return numberOfWords;
}

bool World::ParseInput(const string& input) {

	if (input.size() == 0) {
		return false;
	}

	int numberOfWords = CountWords(input);
	//crear llista de paraules

	Command* pot = new Command();

	pot->abbreviation = "t";
	pot->inputCommand = "take";

	switch (numberOfWords) {
		case 1:
			if (input.compare("look") == 0) {
				
			}
			break;
		case 2:
			cout << "case 2";
			break;
		default:
			return false;
	}

	return true;
}