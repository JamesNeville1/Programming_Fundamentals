#include <iostream>

#include "utility.h"
#include "player.h"
#include "bachelorette.h"

void mainGame(bachelorette* currentBachelorette) {

	utils::slowPrint(currentBachelorette->initialDescription, .055f);
	utils::waitForSecs(1);

	cout << currentBachelorette->portrait << endl;

	doDialogue(&currentBachelorette->dialogueData[0]);
}

int main() {
	setRaceData();

	//Game start screen

	playerClass player = playerClass();
	player.characterDetails();

	bachelorette* currentBachelorette= pickBachelorette();

	getDialogueData(currentBachelorette);

	mainGame(currentBachelorette);
}