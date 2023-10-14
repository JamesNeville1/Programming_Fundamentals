#include <iostream>
#include <map>
#include <string>

using namespace std;

map <int, string> playerRace ={
	{ 1, "Acid Spitter"		},
	{ 2, "Dragonborn"		},
	{ 3, "Ice Elemental"	}
};

map <int, string> playerClass ={
	{ 1, "Knight"			},
	{ 2, "Archer"			},
	{ 3, "Wizard"			}
};

class player {
	public:
		string name;
		int race;
		int class_;
};

int main() {
	player myPlayer;
	cout << "Please choose a character race below: \n";

	map<int, string>::iterator i;
	
	#pragma region Input - Race
	for (i = playerRace.begin(); i != playerRace.end(); i++) {
		cout << i->first << " " << i->second << "\n";
	}
	cout << ">>> ";
	cin >> myPlayer.race;
	cout << "\n";
	#pragma endregion

	#pragma region Input - Class
	cout << "Please choose a character class below: \n";
	for (i = playerClass.begin(); i != playerClass.end(); i++) {
		cout << i->first << " " << i->second << "\n";
	}
	cout << ">>> ";
	cin >> myPlayer.class_;
	cout << "\n";
	#pragma endregion

	#pragma region Input - Name
	cout << "What is your name: ";
	cin >> myPlayer.name;
	#pragma endregion

	#pragma region Output
	cout << "\nPlayer Details: \n"
		<< "Name: " << myPlayer.name << "\n"
		<< "Race: " << myPlayer.race << "\n"
		<< "Class: " << myPlayer.class_ << "\n";
	#pragma endregion
}
