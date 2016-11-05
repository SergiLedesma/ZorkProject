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


class Globals {
	public:
		static void printMessage(string message);
		static void printMessage(string message, string message2);
};

#endif