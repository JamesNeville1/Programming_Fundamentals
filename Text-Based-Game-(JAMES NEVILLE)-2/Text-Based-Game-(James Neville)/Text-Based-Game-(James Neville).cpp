//Built-in
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <windows.h> 
#include <array>

//Mine
#include "utility.h"
#include "event.h"
#include "items.h"
#include "player.h"
#include "enemy.h"
#include "npc.h"

using namespace std;

#pragma region Unsorted
enum gameState {
	exploring,
	combat,
	dialogue,
	dead,
};
string ReturnTitle() {
	cout << "Welcome to";
	utils::slowPrint("...", 1);

	const char* titleScreen = R"(
	   __                                ___                     
	   \ \  __ _ _ __ ___   ___  ___    / _ \__ _ _ __ ___   ___ 
	    \ \/ _` | '_ ` _ \ / _ \/ __|  / /_\/ _` | '_ ` _ \ / _ \
	 /\_/ / (_| | | | | | |  __/\__ \ / /_\\ (_| | | | | | |  __/
	 \___/ \__,_|_| |_| |_|\___||___/ \____/\__,_|_| |_| |_|\___|
	)";

	return titleScreen;
}
#pragma endregion

int main() {
	setEvents();

	cout << ReturnTitle() << endl;

	//playerTemp playersCharacter = playerTemp();
	//playersCharacter.characterDetails();

	//playersCharacter.printInventoryContents();
	//item* toAdd = &items[2];
	//playersCharacter.addItem(toAdd);
	//playersCharacter.printInventoryContents();

	//utils::dialogueBox("Hey, you're finally awake");
	//utils::dialogueBox("You were trying to cross the border, right?");
	//utils::dialogueBox("Walked right into that Imperial ambush, same as me?");

	cout << eventFunc(6);
}