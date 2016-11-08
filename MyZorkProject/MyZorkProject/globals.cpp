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

	bool compareString(string first, Direction direction) {
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