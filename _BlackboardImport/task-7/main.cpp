#include <iostream>
#include <string>

using namespace std;

struct classTemp {
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
	int playerClass;
};

void classSelect() {
	bool isInvalid = true;
	string playerInputRaw = "";
	int playerInput = 0;
	int sizeOfClasses = sizeof(characterClasses) / sizeof(characterClasses[0]);

	while (isInvalid) {
		cout << "Choose a class from below (ensure your answer is within the range):" << endl;
		for (int i = 0; i < sizeOfClasses; i++) {
			cout << i + 1 << " " << characterClasses[i].className << endl;
		}

		cin >> playerInputRaw;
		cout << playerInputRaw.length() << endl;
		for (int i = 0; i < playerInputRaw.length(); i++) {
			if (isdigit(playerInputRaw[i]))
				playerInput += playerInputRaw[i];
		}
		cout << playerInput << endl;
	}

	if (playerInput > 0 && playerInput <= sizeOfClasses) {
		isInvalid = false;
	}
	else cout << "That input was invalid, try again." << endl;

	cout << "\n";
	cout << "You selected the " << characterClasses[playerInput - 1].className << " class" << endl;
	cout << "You have " << characterClasses[playerInput - 1].health << " health" << endl;
	cout << "You have " << characterClasses[playerInput - 1].damageMaxRoll << " max damage" << endl;
	cout << "Ranged class: ";
	if (characterClasses[playerInput - 1].ranged) cout << "True" << endl;
	else cout << "False" << endl;
}

int main() {
	classSelect();
}