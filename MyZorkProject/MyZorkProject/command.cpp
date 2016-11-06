#include "command.h"



Command::Command(list<string> names, Action action, int numberOfArguments) :
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
	int inputWordsCount = CountWords(input);
	for (string iter : names) {
		if (inputWordsCount == 1) {
			if (compareString(input, iter)) {
				cout << iter;
			}
		}
		if (inputWordsCount == 2) {
			if (compareString(input.substr(0, iter.size() + 1), (iter + " "))) {
				cout << iter;
				found = true;
				break;
			}
		}

	}
	return found;
}