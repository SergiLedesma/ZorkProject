#include <iostream>
#include <string>
#include "world.h"

using namespace std;


int main() {
	string playerInput;
	World myWorld;
	Action action;
	bool end = false;

	
	while (end == false) {
		getline(cin, playerInput);

		action = myWorld.ParseInput(playerInput);

		if (action == END) {
			printMessage("------------------------");
			printMessage("You have finished the game. Don't forget to look for other endings!", "I hope you enjoyed the experience.");
			printMessage("By: Sergi Ledesma", "Contact: sergi.dev@gmail.com");
			printMessage("Check out the full project at https://github.com/SergiLedesma");
			getline(cin, playerInput);
			end = true;
		}
		else if (action == QUIT) {
			end = true;
		}
	}
}