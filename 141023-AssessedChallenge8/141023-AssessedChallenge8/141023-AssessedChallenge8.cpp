#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map <int, string> items = {
	{ 1, "Potion of Healing"},
	{ 2, "Bread"			},
	{ 3, "Poison"			}
};

int main() {
	#pragma region Set Inventory Size
	cout << "Specify the size of the inventory: ";
	int inventorySize;
	cin >> inventorySize;
	vector<int> inventory(inventorySize);
	#pragma endregion
	
	cout << "Enter Comand: ";
	string userPrompt = "";
	cin >> userPrompt;

	string command = userPrompt.substr(0, userPrompt.find(' '));
	string indexInput = (userPrompt.substr(userPrompt.find(' ') + 1));

	cout << command << "\n" << indexInput;

	if (command == "show_all") {
		cout << "\nInventory:\n";
		for (int i = 0; i < inventory.size(); i++) {
			cout << "Slot " << i;
			if (inventory[i] == 0) {
				cout << " is empty\n";
			}
			else if (inventory[i] <= items.size()){
				cout << "has " << items[inventory[i]] << "\n";
			}
			else {
				inventory[i] = 0;
				cout << " is empty\n";
			}
		}
	}
}