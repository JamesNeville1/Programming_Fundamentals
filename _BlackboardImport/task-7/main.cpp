#include <iostream>
#include <string>

using namespace std;

string playerRace[3] = { "Acid Spitter", "Dragonborn", "Ice Elemental" };

string playerClass[3] = { "Knight", "Archer", "Wizard" };

class player {
public:
	string name = "";
	int race = 0;
	int class_ = 0;
};

bool validate(int input, int max) {
	if (input > max || input < 0) return false;
	else return true;
}

int selectRace() {
	bool validated = false;
	string inputRaw = "";
	int input = 0;

	while (!validated) {
		cout << "\nPlease choose a character race below: \n";

		for (int i = 0; i < sizeof(playerRace) / sizeof(string); i++) {
			cout << i + 1 << " " << playerRace[i] << "\n";
		}
		cout << ">>> ";
		cin >> inputRaw;

		input--;
		cout << "\n";
		
		validated = validate(input, sizeof(playerRace) / sizeof(string) - 1);

		if (!validated) {
			system("CLS");
			cout << "*Error: Please enter a number between 1 and " << sizeof(playerRace) / sizeof(string) << "*\n";
		}
	}
	return input;
}

int selectClass() {
	int input = 0;
	cout << "Please choose a character class below: \n";
	for (int i = 0; i < sizeof(playerClass) / sizeof(string); i++) {
		cout << i + 1<< " " << playerClass[i] << "\n";
	}
	cout << ">>> ";
	cin >> input;
	cout << "\n";
	return input - 1;
}

int main() {
	player myPlayer;

#pragma region Input
	myPlayer.race = selectRace();
	myPlayer.class_ = selectClass();
	cout << "What is your name: ";
	cin >> myPlayer.name;
#pragma endregion

#pragma region Output
	cout << "\nPlayer Details: \n"
		<< "Name: " << myPlayer.name << "\n"
		<< "Race: " << playerRace[myPlayer.race] << "\n"
		<< "Class: " << playerClass[myPlayer.class_] << "\n";
#pragma endregion
}
