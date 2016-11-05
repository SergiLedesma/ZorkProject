#ifndef __Command__
#define __Command__

#include <string>
#include "player.h"

using namespace std;

class Command
{
public:
	Command();
	virtual ~Command();
	string inputCommand;
	string abbreviation;
};

#endif