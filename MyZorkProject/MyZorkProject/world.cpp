#include <iostream>
#include <string>
#include "world.h"


World::World()
{
	Creature* monster = new Creature("Paco"s, "El paleta"s);
	pol = new Player("Pol", "Pot");
}


World::~World()
{
}

int World::CountWords(const string& input) {
	int numberOfWords = 1;
	
	for (auto& letter : input) {
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