#include <iostream>
#include <string>
#include "world.h"

using namespace std;


int main() {
	string playerInput;
	World myWorld;
	Action action;
	bool end = false;

	printMessage("10.000 BC. You wake up at the base of a high cliff. After going hunting with your tribe you felt down, and lost all your equipment. You've probably been unconscious for a few hours. Explore your surroundings and find a way to get back home.");

	while (end == false) {
		getline(cin, playerInput);

		action = myWorld.ParseInput(playerInput);

		if (action == END) {
			printMessage("YOU FINISHED AND ENDING FOR THE GAME!");
			getline(cin, playerInput);
			end = true;
		}
		if (action == QUIT) {
			end = true;
		}
	}

	
}