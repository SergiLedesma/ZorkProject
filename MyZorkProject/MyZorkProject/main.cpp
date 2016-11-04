#include <iostream>
#include <string>
#include "world.h"

using namespace std;


int main() {
	string playerInput;
	World myWorld;

	cout << "Welcome to my game\n";
	getline(cin, playerInput);

	myWorld.ParseInput(playerInput);

	cin >> playerInput;
}