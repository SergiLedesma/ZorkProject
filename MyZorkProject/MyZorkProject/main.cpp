#include <iostream>
#include <string>
#include "world.h"

using namespace std;


int main() {
	string playerInput;
	World myWorld;
	Action action;
	bool end = false;

	cout << "Welcome to my game\n";

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