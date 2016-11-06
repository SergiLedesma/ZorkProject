#ifndef __Command__
#define __Command__

#include <string>
#include "player.h"
#include "globals.h"

using namespace std;

class Command
{
public:
	Command(list<string> names, Action action, int numberOfArguments);
	virtual ~Command();
	int CountWords(const string & input);
	bool IsCommand(const string & input);
	list<string> names;
	Action action;
	int numberOfArguments;
};

#endif