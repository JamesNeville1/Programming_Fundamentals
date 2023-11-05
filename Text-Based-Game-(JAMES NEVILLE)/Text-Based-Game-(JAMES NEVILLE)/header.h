#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;

enum damageType {
	fire,
	poison,
	frost,
	piercing,
	slashing,
	magic,
	divine,
	sneak,
	evil
};

struct raceTemp {
	string displayName = "";
	damageType raceDamageType = fire;
	int raceHealth = 0;
	float opinionModifier = 0.0f;
	bool avaliableWhenOpened = true;
};

raceTemp raceData[] = {
	{"Dragonborn", fire, 20, 0.0f},
	{"Snakeborn", poison, 30, -1.65f},
	{"Ice Elemental", frost, 12, 2.0f}
};

struct classTemp {
	string displayName = "";
	int health = 0;
	int maxDamageRoll = 0;
	damageType classDamageType;
	bool isRangedClass = false;
	bool avaliableWhenOpened = true;
};

classTemp classData[] = {
	{"Knight", 25, 6, slashing, false, true},
	{"Archer", 18, 8, piercing, true, true},
	{"Wizard", 10, 12, magic, true, true},
	{"Paladin", 32, 8, divine, false, true},
	{"Thief", 22, 10, sneak, true, true},
	{"Warlock", 7, 20, magic, true, true},
};

struct playerTemp {
	string name;
	int playerRaceID;
	int playerClassID;
};

struct npc {
	string name = "";
	bool isMale = true;
	struct salesman {

	};
	struct regular {

	};
};

struct eventTemp {
	vector<string> prompts;
};

eventTemp eventData[] = {
	{
		{"Do you go left or right?","Left","Right"},
	},
	{
		{"You find a big monster", "Attack!", "Go back"},
	},
	{
		{"You find a treasure chest", "Open it", "Go back"},
	}
};

class utils {
	public: class core {
		public: static int validateInt(string raw) {
			bool valid = false;
			string rawValidated = "";

			for (int i = 0; i < raw.length(); i++) {
				if (isdigit(raw[i])) rawValidated += raw[i];
			}

			if (rawValidated != "") return stoi(rawValidated);
			else return -1;
		}

		public: static int promptUserOptions(vector<string> prompts) {
			bool valid = false;
			int validInt = 0;

			while (!valid) {
				cout << prompts[0] << endl;
				for (int i = 1; i < prompts.size(); i++) {
					cout << "> [" + to_string(i) + "] " << prompts[i] << endl;
				}

				string rawInput = "";
				getline(cin, rawInput);
				cout << endl;

				validInt = validateInt(rawInput) - 1;

				if (validInt >= 0 && validInt < prompts.size() - 1) valid = true;
				else cout << "Error: Please ensure you input is valid" << endl;
			}
			return validInt;
		}

		public: static string promptUserString(string prompt) {
			cout << prompt << " ";

			string input = "";
			getline(cin, input);

			return input;
		}

		public: static void promptNoInput(vector<string> prompts) {
			for (int i = 0; i < prompts.size(); i++) {
				cout << prompts[i] << endl;
			}
		}
		public: static bool yesOrNoPrompt() {
			//bool confirmed = false;
			while (true) { //check if bad?
				cout << endl;
				string input = promptUserString("Confirm: (y/n)");

				if (input == "y" || input == "Y") {
					cout << endl;
					return true;
				}
				else if (input == "n" || input == "N") {
					cout << endl;
					return false;
				}
			}
		}
	};
	public: class information {
		public:static vector<string> raceInfo(int chosenRaceInt) {
			vector<string> info;
			if (raceData[chosenRaceInt].opinionModifier > 0) {
				info.push_back("> This race is viewed highly by most, you're kind are often view as protectors and worshipped as gods.");
			}
			else if (raceData[chosenRaceInt].opinionModifier < 0) {
				info.push_back("> This race is disrespected by the masses, you're kind are often viewed as viel and are pushed to the fringe of society.");
			}
			else {
				info.push_back("> This race is accepted by most. Most will be impartial to you");
			}
			info.push_back("> This race will add an additional " + to_string(raceData[chosenRaceInt].raceHealth) + " health");
			return info;
		}

		public:static vector<string> classInfo(int chosenClassInt) {
			vector<string> info;
			if (classData[chosenClassInt].isRangedClass) info.push_back("> If you chose this class, you will be more effective at a distance.");
			else info.push_back("> If you choose this class, you will be more effective in close quaters.");
			info.push_back("> This class will add an additional " + to_string(classData[chosenClassInt].health) + " health");
			info.push_back("> You roll a d" + to_string(classData[chosenClassInt].maxDamageRoll) + " when rolling damage");
			return info;
		}
	};
	public: class eventSpecific {
		public: static void eventFunc(eventTemp eventInfo, int outcomes[]) {
			int input = utils::core::promptUserOptions(eventInfo.prompts);
			
			int i[2] = { 1,2 };
			switch (input) {
				case 1:eventFunc(eventData[1], i);
					break;
				case 2:eventFunc(eventData[2], i);
			}
		}
	};
};