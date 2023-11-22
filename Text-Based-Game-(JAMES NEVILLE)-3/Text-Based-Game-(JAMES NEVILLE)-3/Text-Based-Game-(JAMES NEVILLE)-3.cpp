#include <iostream>

#include "utility.h"
#include "player.h"
#include "bachelorette.h"

int main() {
	setRaceData();

	//Game start screen

	playerClass player = playerClass();
	player.characterDetails();

	bachelorette test;
	cout << test.portrait << endl << endl;

	utils::dialogueBox(test.openningLine);
}