#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> inventory;

//ON OPEN, CLOSE REGIONS, easier to read

enum itemType { //Define item types, used in combination with the attribute variable to set the 
	healing,
	rangedWeapon,
	meleeWeapon,
	food
};

struct item { //Item struct
	string name;
	itemType type;
	int attribute;
	int worth;
};

item items[]{ //Item data (in an actual game itd be in a JSON file)
	{"Potion of Healing", healing, 5, 10},
	{"Standard Bow", rangedWeapon, 5, 20},
	{"Epic Bow", rangedWeapon, 11, 40},
	{"Standard Sword", meleeWeapon, 7, 18},
	{"Epic Sword", meleeWeapon, 15, 35},
	{"Bread", food, 2, 2},
	{"Cake", food, 5, 4}
};

struct commandTemp { //Command is split into 3 segments, easier to work with and improves readability 
	string keyword = "";
	int identifier = 0;
	int manipulater = 0;
};

int intValidator(string rawInt) { //Validate Ints
	string intRaw = "";
	for (int i = 0; i < rawInt.length(); i++) {
		if (isdigit(rawInt[i])) intRaw += rawInt[i];;
	}
	if (intRaw == "") return -1;
	return stoi(intRaw);
}

commandTemp inputSplitter(string inputRaw) { //Split command into 3 (commandTemp)
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

void inputProcessor(const commandTemp command, bool &shouldLoop) { //process input, exute commands here
	if (command.keyword == "view" && command.identifier >= 0 && command.identifier < inventory.size()) { //View command
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
	else if (command.keyword == "show_all") { //Show All command
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
	else if (command.keyword == "set" 
		&& command.identifier >= 0 && command.identifier < inventory.size() 
		&& command.manipulater >= 0 
		&& command.manipulater < sizeof(items) / sizeof(items[0])) { //Set command
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
	else if (command.keyword == "items") { //Items command
		#pragma region items
		cout << "List of all items currently avaliable:" << endl;
		for (int i = 0; i < sizeof(items) / sizeof(items[0]); i++) {
			cout << "{" << i << "} " << items[i].name << endl;
		}
		#pragma endregion
	}
	else if (command.keyword == "exit") { //Exit command
		#pragma region exit
		shouldLoop = false;
		#pragma endregion
	}
	else if (command.keyword == "help") { //Help command
		#pragma region help
		cout << "view (num): show the item in the inventory vector and gives information about the item" << endl
			<< "show_all: show all slots with whatever they have in them" << endl
			<< "set (num) (num): set the inventory slot of the first number to the item id of the second number" << endl
			<< "items: list all items" << endl
			<< "exit: exit program" << endl
			<< "help: show information on all commands" << endl;
		#pragma endregion
	}
	else { //Anything else gives and error
		cout << "*ERROR*: Invalid Command";
	}
}

string createInventory(const int maxInvSize) { //Create Inventory
	string inputRaw = "";
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

	return inputRaw;
}

void main() {
	bool shouldLoop = true;
	int maxInvSize = 16;
	string inputRaw = createInventory(maxInvSize);
	
	while (shouldLoop) {
		cout << endl << "Enter a command: ";
		getline(cin, inputRaw);
		commandTemp userCommand = inputSplitter(inputRaw);

		#pragma region debugging
		/*cout << "Command Keyword: " << userCommand.keyword << endl
			<< "Command identifier: " << userCommand.identifier << endl
			<< "Command manipulater: " << userCommand.manipulater << endl;*/
		#pragma endregion

		inputProcessor(userCommand, shouldLoop);
	}
}