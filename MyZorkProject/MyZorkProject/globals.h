#ifndef __Globals__
#define __Globals__

#include <iostream>
#include <string>
#include <array>

using namespace std;

enum Direction { //Create pairs of directions
	NOWHERE = 0,
	NORTH = 1,
	SOUTH = -1,
	EAST = 2,
	WEST = -2,
	UP = 3,
	DOWN = -3
};

extern array<Direction, 6> directionStrings;

enum Action {
	GO,
	TAKE,
	DROP,
	CRAFT,
	LOOK,
	EAT,
	INVENTORY,
	NONE,
	END,
	QUIT
};


namespace Globals {
	void printMessage(string message);
	void printMessage(string message, string message2);
	bool compareString(string first, string second);
	bool compareString(string first, const Direction direction);
};

#endif