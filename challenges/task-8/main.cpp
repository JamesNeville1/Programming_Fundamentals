#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> inventory;
bool shouldLoop = true;
int maxInvSize = 16;

enum itemType {
	healing,
	rangedWeapon,
	meleeWeapon,
	food
};

struct item {
	string name;
	itemType type;
	int attribute;
	int worth;
};

item items[]{
	{"Potion of Healing", healing, 5, 10},
	{"Standard Bow", rangedWeapon, 5, 20},
	{"Epic Bow", rangedWeapon, 11, 40},
	{"Standard Sword", meleeWeapon, 7, 18},
	{"Epic Sword", meleeWeapon, 15, 35},
	{"Bread", food, 2, 2},
	{"Cake", food, 5, 4}
};

struct commandTemp {
	string keyword;
	int identifier;
	int manipulater;
};

int intValidator(string rawInt) {
	string intRaw = "";
	for (int i = 0; i < rawInt.length(); i++) {
		if (isdigit(rawInt[i])) intRaw += rawInt[i];;
	}
	if (intRaw == "") return -1;
	return stoi(intRaw);
}

commandTemp inputSplitter(string inputRaw) {
	commandTemp input;
	
	stringstream iss(inputRaw);
	string splitString = "";
	
	iss >> splitString;
	input.keyword = splitString;
	
	iss >> splitString;
	input.identifier = intValidator(splitString);

	iss >> splitString;
	input.manipulater = intValidator(splitString);
	
	return input;
}

void inputProcessor(commandTemp command) {
	//MAKE INVENTORY SIZE AND ITEMS SIZE VARIABLES or *make functions to check*

	if (command.keyword == "view" && command.identifier >= 0 && command.identifier < inventory.size()) {
		#pragma region view
		
		if (inventory[command.identifier] >= 0 && inventory[command.identifier] < sizeof(inventory) / sizeof(inventory[0])) {
			cout << "> [" << command.identifier << "] has: " << items[inventory[command.identifier]].name << endl;
			
			switch (items[inventory[command.identifier]].type) {
				case healing:
					cout << "\tThis item can heal this ammount of health: ";
					break;
				case rangedWeapon:
					cout << "\tThis item can do this much damage at a distance: ";
					break;
				case meleeWeapon:
					cout << "\tThis item can do this much damage in close quarters combat: ";
					break;
				case food:
					cout << "\tThis item will satiate this much hunger: ";
					break;
				default:
					break;
			}

			cout << items[inventory[command.identifier]].attribute << endl;
			cout << "\tIt is worth: " << items[inventory[command.identifier]].worth << endl;
		}
		else {
			cout << "> [" << command.identifier << "] is empty";
		}

		#pragma endregion
	}
	else if (command.keyword == "show_all") {
		#pragma region show_all

		cout << "Showing Inventory: " << endl;
		for (int i = 0; i < inventory.size(); i++) {
			if (inventory[i] >= 0 && inventory[i] < sizeof(inventory) / sizeof(inventory[i])) {
				cout << "> [" << i << "] " << items[inventory[i]].name << endl;
			}
			else {
				cout << "> [" << i << "] " << "{Empty}" << endl;
			}
		}

		#pragma endregion
	}
	else if (command.keyword == "set" && command.identifier >= 0 && command.identifier < inventory.size() && command.manipulater >= 0 && command.manipulater < sizeof(items) / sizeof(items[0])) {
		#pragma region set
		if(inventory[command.identifier] >= 0 && inventory[command.identifier] < sizeof(inventory) / sizeof(inventory[0])) {
			cout << "> [" << command.identifier << "] was " << items[inventory[command.identifier]].name << " and is now " << items[command.manipulater].name << endl;
		}
		else {
			cout << "> [" << command.identifier << "] was empty and is now " << items[command.manipulater].name << endl;
		}
		inventory[command.identifier] = command.manipulater;
		#pragma endregion
	}
	else if (command.keyword == "items") {
		#pragma region items
		cout << "List of all items currently avaliable:" << endl;
		for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
			cout << "{" << i << "} " << items[i].name << endl;
		}
		#pragma endregion
	}
	else if (command.keyword == "exit") {
		#pragma region exit
		shouldLoop = false;
		#pragma endregion
	}
	else if (command.keyword == "help") {
		#pragma region help
		cout << "view (num): show the item in the inventory vector and gives information about the item" << endl
			<< "show_all: show all slots with whatever they have in them" << endl
			<< "set (num) (num): set the inventory slot of the first number to the item id of the second number" << endl
			<< "items: list all items" << endl
			<< "exit: exit program" << endl
			<< "help: show information on all commands" << endl;
		#pragma endregion
	}
	else {
		cout << "*ERROR*: Invalid Command";
	}
}

void main() {
	string inputRaw = "";
	#pragma region Initialize Inventory

	bool valid = false;
	while (!valid) {
		cout << "Welcome, please set the size of the inventory: ";
		getline(cin, inputRaw);
		int invSize = intValidator(inputRaw);

		if (invSize > 0 && invSize <= maxInvSize) {
			inventory.resize(invSize);
			cout << "Size of inventory has been set to " << inventory.size();
			valid = true;
		}
		else {
			cout << "Size of inventory must be between 1-16" << endl;
		}
	}

	for (int i = 0; i < inventory.size(); i++) {
		inventory[i] = -1;
	}
	/*cout << "Inventory:" << endl;
	for (int i = 0; i < inventory.size(); i++) {
		inventory[i] = -1;

		if (inventory[i] >= 0 && inventory[i] < sizeof(inventory) / sizeof(inventory[i])) {
			cout << "> [" << i + 1 << "] " << items[inventory[i]].name << endl;
		}
		else {
			cout << "> [" << i + 1 << "] " << "{Empty}" << endl;
		}
	}*/
	#pragma endregion

	while (shouldLoop) {
		cout << endl << "Enter a command: ";
		getline(cin, inputRaw);
		commandTemp userCommand = inputSplitter(inputRaw);

		#pragma region debugging
		/*cout << "Command Keyword: " << userCommand.keyword << endl
			<< "Command identifier: " << userCommand.identifier << endl
			<< "Command manipulater: " << userCommand.manipulater << endl;*/
		#pragma endregion

		inputProcessor(userCommand);
	}
}