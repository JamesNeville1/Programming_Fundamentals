#pragma once
#include "utility.h"

#pragma region Type
//Damage types for both character and enemies
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
//Each type converted to a game ready string
map<damageType, string> typeToString {
	{fire, "Fire"},
	{ poison, "Poison" },
	{ frost, "Frost" },
	{ piercing, "Piercing" },
	{ slashing, "Smiting" },
	{ magic, "Magical" },
	{ divine, "Divine" },
	{ sneak, "Dark" },
	{ evil, "Hell" }
};
#pragma endregion
#pragma region Race
//The race object template
struct raceTemp {
	string displayName = "";
	damageType raceDamageType = fire;
	int raceHealth = 0;
	float opinionModifier = 0.0f;
	bool avaliableWhenOpened = true;
};
//The array to store the race's data
raceTemp raceData[] = {
	{"Dragonborn", fire, 20, 0.0f},
	{"Snakeborn", poison, 30, -1.65f},
	{"Ice Elemental", frost, 12, 2.0f}
};

vector<string> raceInfo(int chosenRaceInt) {
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
#pragma endregion
#pragma region Class
//The class object template
class classTemp {
public:
	string displayName = "";
	int classHealth = 0;
	int maxDamageRoll = 0;
	damageType classDamageType;
	bool isRangedClass = false;
	bool avaliableWhenOpened = true;
};
//The array to store the class's data
classTemp classData[] = {
	{"Knight", 25, 6, slashing, false, true},
	{"Archer", 18, 8, piercing, true, true},
	{"Wizard", 10, 12, magic, true, true},
	{"Paladin", 32, 8, divine, false, true},
	{"Thief", 22, 10, sneak, true, true},
	{"Warlock", 7, 20, evil, true, true},
};

vector<string> classInfo(int chosenClassInt) {
	vector<string> info;
	if (classData[chosenClassInt].isRangedClass) info.push_back("> If you chose this class, you will be more effective at a distance.");
	else info.push_back("> If you choose this class, you will be more effective in close quaters.");
	info.push_back("> This class will add an additional " + to_string(classData[chosenClassInt].classHealth) + " health");
	info.push_back("> You roll a d" + to_string(classData[chosenClassInt].maxDamageRoll) + " when rolling damage");
	return info;
}
#pragma endregion
int getPlayerTemps(bool getRace) {
	vector<string> prompts = { "Select your " };
	int loopFor = 0;

	if (getRace) {
		prompts[0] += "race";
		loopFor = sizeof(raceData) / sizeof(raceData[0]);
		for (int i = 0; i < loopFor; i++) {
			string option = raceData[i].displayName;
			prompts.push_back(option);
		}
	}
	else {
		prompts[0] += "class";
		loopFor = sizeof(classData) / sizeof(classData[0]);
		for (int i = 0; i < loopFor; i++) {
			string option = classData[i].displayName;
			prompts.push_back(option);
		}
	}

	bool hasChosen = false;
	int chosenTemp = 0;
	vector<string> info;

	while (!hasChosen) {
		chosenTemp = utils::promptUserOptions(prompts);

		if (getRace) info = raceInfo(chosenTemp);
		else info = classInfo(chosenTemp);

		utils::promptNoInput(info);
		if (utils::yesOrNoPrompt()) hasChosen = true;
	}

	return chosenTemp;
}
class playerTemp {
public:
	string name;
	int health;
	int playerRaceID;
	int playerClassID;
	array<item*, 8> inventory = array<item*, 8>();
	playerTemp() {
		this->name = utils::promptUserOptions("Enter your characters name:");
		this->playerRaceID = getPlayerTemps(true);
		this->playerClassID = getPlayerTemps(false);
		this->health = raceData[playerRaceID].raceHealth + classData[playerClassID].classHealth;
	}
	void characterDetails() {
		cout << "Character Details:" << endl
			<< this->name << endl
			<< raceData[this->playerRaceID].displayName << endl
			<< classData[this->playerClassID].displayName << endl
			<< "Health: " << this->health << endl
			<< "Types: "
			<< typeToString.find(classData[this->playerClassID].classDamageType)->second << " "
			<< typeToString.find(raceData[this->playerRaceID].raceDamageType)->second << endl << endl;
	}
	void takeDamage(int damage) {
		this->health -= damage;
		cout << "You took " << damage << " damage" << endl
			<< "You now have " << health << " health" << endl;
	}
	int findFirstAvaliableSlot() {
		for (int i = 0; i < inventory.size(); i++) {
			if (inventory[i] == NULL) {
				return i;
			}
		}
		return -1;
	}
	void printInventoryContents() {
		cout << "Inventory:" << endl;
		for (int i = 0; i < inventory.size(); i++) {
			cout << "Slot [" << i << "]: ";
			if (inventory[i] == NULL) {
				cout << "is empty";
			}
			else {
				cout << items[i].name;
			}
			cout << endl;
		}
		cout << endl;
	}
	bool addItem(item* itemToAdd) {
		int slotPos = findFirstAvaliableSlot();

		if (slotPos != -1) {
			inventory[slotPos] = itemToAdd;
			return true;
		}
		return false;
	}
};