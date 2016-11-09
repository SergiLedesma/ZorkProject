#include "command.h"



Command::Command(const list<string> names, const Action action, const int numberOfArguments) :
	names(names), action(action), numberOfArguments(numberOfArguments)
{

}

Command::~Command()
{
}

int Command::CountWords(const string& input) {
	int numberOfWords = 1;
	int i = 0;
	char letter;
	bool lastIsSpace = false;
	while (i < input.size()) {
		letter = input[i];
		if (isspace(letter) && !lastIsSpace) {
			lastIsSpace = true;
			numberOfWords++;
		}
		else {
			lastIsSpace = false;
		}
		i++;
	}

	return numberOfWords;
}

bool Command::IsCommand(const string &input) {
	bool found = false;
	for (string iter : names) {
		if (compareString(input.substr(0, iter.size()), iter)) {
			found = true;
			break;
		}
	}
	return found;
}

string Command::GetArguments(const string &input) {

	int inputWordsCount = CountWords(input);

	string arguments = input;

	for (string iter : names) {
		if (inputWordsCount == 1) {
			arguments = ""s;
			break;
		}
		if (inputWordsCount == 2) {
			if (compareString(input.substr(0, iter.size() + 1), (iter + " "))) {
				arguments.erase(0, iter.size() + 1);
				break;
			}
		}
	}

	return arguments;
}