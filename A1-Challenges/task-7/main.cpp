#include <iostream>
#include <string>

using namespace std;

struct classTemp { //Class structure, simple data for a RPG
	string className;
	int health;
	int damageMaxRoll;
	bool ranged;
};

classTemp characterClasses[3] = {
	{"Knight", 25, 6, false},
	{"Archer", 18, 8, true},
	{"Wizard", 10, 12, true}
};

struct player {
	string name;
	classTemp* playerClass;
};

classTemp* input() {
	string playerInputRaw = "";
	int playerInput = -1;

	bool valid = false;

	while (!valid) {
		cout << "Choose a class: " << endl;
		for (int i = 0; i < sizeof(characterClasses) / sizeof(characterClasses[0]); i++) {
			cout << "[" << i + 1 << "] " << characterClasses[i].className << endl;
		}
		getline(cin, playerInputRaw);
		
		string placement;
		for (int i = 0; i < playerInputRaw.length(); i++) {
			if (isdigit(playerInputRaw[i])) placement += playerInputRaw[i];
		}

		if (placement != "") {
			playerInput = stoi(placement) - 1;
		}

		if (playerInput >= 0 && playerInput < sizeof(characterClasses) / sizeof(characterClasses[0])) {
			valid = true;
		}

		if (!valid) {
			cout << "Invalid Choice, ensure your input is a valid." << "\n\n";
		}
	}

	return &characterClasses[playerInput];
}
string inputName() {
	string name;

	cout << "Enter your name ";
	getline(cin, name);
	
	return name;
}

int main() {
	player ourPlayer;
	ourPlayer.playerClass = input();
	ourPlayer.name = inputName();

	cout << "\nName: " << ourPlayer.name << endl;
	cout << "Class: " << ourPlayer.playerClass->className << endl;
}