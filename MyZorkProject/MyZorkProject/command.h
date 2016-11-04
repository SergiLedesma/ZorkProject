#include <string>
#include "player.h"
#pragma once

using namespace std;

class Command
{
public:
	Command();
	virtual ~Command();
	string inputCommand;
	string abbreviation;
};

