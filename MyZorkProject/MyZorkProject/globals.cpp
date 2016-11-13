#include "globals.h"

array<Direction, 6> directionStrings = { NORTH,SOUTH,EAST,WEST,UP,DOWN };

namespace Globals {


	void printMessage(string message) {
		message[0] = (char)toupper(message[0]);
		cout << message << '\n';
	}

	void printMessage(string message, string message2) {
		message[0] = (char)toupper(message[0]);
		message2[0] = (char)toupper(message2[0]);
		cout << message << '\n' << message2 << '\n';
	}

	void printHelp() {
		cout << "1 word commands\n";
		cout << "Look - Description of the close enviroment\nInventory - List of player's inventory\nQuit - Quit the game\n\n";
		cout << "2 word commands\n";
		cout << "Look (entity) - Detailed description\nGo (direction) - Player movement towards that direction\nGet/Pick/Take (item) - Add item to player's inventory\n";
		cout << "Drop (item) - Remove item from player's inventory and leave it on the floor\nCraft (receipe) - Remove receipe's items from inventory and add the crafted one";
		cout << "Eat (item) - Remove item from player's inventory and enjoy the food\nOpen (container) - Open the container and put its content in player's inventory\n\n";
		cout << "4 word commands\n";
		cout << "Put (item) in (container) - Remove item from player's inventory and store it inside the container\n";
	}

	void printIntro() {
		cout << "Welcom to Tribal Zork!\n";
		cout << "10.000 BC. You wake up at the base of a high cliff. After going hunting with your tribe you felt down, and lost all your equipment.\n";
		cout << "You've probably been unconscious for a few hours. Explore your surroundings and find a way to get back home.\n";
		cout << "If you need help just type HELP\n\n";
	}

	bool compareString(string first, string second) {
		bool equals = true;
		if (first.size() != second.size()) {
			equals = false;
		}
		else {
			for (unsigned int i = 0; i < first.size(); i++) {
				if (tolower(first[i]) != tolower(second[i])) {
					equals = false;
					break;
				}
			}
		}
		return equals;
	}

	bool compareString(string first, const Direction direction) {
		bool equals = true;
		string second = "";
		switch (direction) {
			case NORTH:
				second = "north";
				break;
			case SOUTH:
				second = "south";
				break;
			case EAST:
				second = "east";
				break;
			case WEST:
				second = "west";
				break;
			case UP:
				second = "up";
				break;
			case DOWN:
				second = "down";
				break;
		}
		if (first.size() != second.size()) {
			equals = false;
		}
		else {
			for (unsigned int i = 0; i < first.size(); i++) {
				if (tolower(first[i]) != tolower(second[i])) {
					equals = false;
					break;
				}
			}
		}
		return equals;
	}
}