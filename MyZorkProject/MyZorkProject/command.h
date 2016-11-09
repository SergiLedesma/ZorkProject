#ifndef __Command__
#define __Command__

#include <string>
#include "player.h"
#include "globals.h"

using namespace std;

class Command
{
public:
	Command(const list<string> names, const Action action, const int numberOfArguments);
	virtual ~Command();
	int CountWords(const string & input);
	bool IsCommand(const string & input);
	string GetArguments(const string & input);
	list<string> names;
	Action action;
	int numberOfArguments;
};

#endif