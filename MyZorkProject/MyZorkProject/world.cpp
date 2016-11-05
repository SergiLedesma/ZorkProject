#include <iostream>
#include <string>
#include "world.h"


World::World()
{
	/*
	Creature* monster = new Creature("Paco"s, "El paleta"s);
	pol = new Player("Pol"s, "Pot"s);
	Room* startingRoom = new Room("starting room name"s, "the starting room descriptiojdsoña"s);
	Room* secondRoom = new Room("sec room name"s, "the sec room descriptiojdsoña"s);
	Exit* north1 = new Exit("big door"s, "a huge door"s, startingRoom, secondRoom);
	*/
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