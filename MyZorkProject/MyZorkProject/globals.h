#ifndef __Globals__
#define __Globals__

#include <iostream>
#include <string>

using namespace std;

enum Direction { //Create pairs of directions
	NORTH = 1,
	SOUTH = -1,
	EAST = 2,
	WEST = -2,
	UP = 3,
	DOWN = -3
};

enum Action {
	GO,
	TAKE,
	DROP,
	CRAFT,
	LOOK,
	EAT,
	INVENTORY
};


namespace Globals {
	void printMessage(string message);
	void printMessage(string message, string message2);
	bool compareString(string first, string second);
};

#endif