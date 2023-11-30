#include <iostream>

#include "utility.h"
#include "player.h"
#include "bachelorette.h"
#include "read.h"

enum gameState {
	playing,
	won,
	lost
};

void mainGame(bachelorette* currentBachelorette, playerClass* player) {

<<<<<<< HEAD

=======
>>>>>>> parent of ad8136a (json working)
	//utils::slowPrint(currentBachelorette->initialDescription, .055f);
	//utils::waitForSecs(2);

	gameState gameState = playing;
	dialogue* currentDialogue = &currentBachelorette->dialogueData[0];

	while (gameState == playing) {
		if (currentDialogue->heartEffect != 0) {
			currentBachelorette->adjustHearts(currentDialogue->heartEffect);
			utils::waitForSecs(1.0f);
		}
		if (currentDialogue->strikeEffect != 0) {
			player->currentStrikes += currentDialogue->strikeEffect;
			if (player->currentStrikes >= player->strikes) {
				gameState = lost;
			}
			else {
				utils::slowPrint(
					"You have " + to_string(player->currentStrikes)
					+ " (of " + to_string(player->strikes)
					+ ") strikes before " + currentBachelorette->name
					+ " walks out and this date is ruined!",
					.06f);
				utils::waitForSecs(1.0f);
			}
		}
		system("CLS");

		cout << currentBachelorette->portrait << endl;

		if (currentDialogue->response.size() <= 0) {
			if (currentBachelorette->currentHearts >= currentBachelorette->maxHearts) {
				gameState = won;
			}
			else {
				gameState = lost;
			}
		}
		else currentDialogue = doDialogue(currentDialogue);
	}

	if (gameState == won) {
		utils::slowPrint(currentBachelorette->endDescriptionGood, 0.06f);
	}
	else {
		utils::slowPrint(currentBachelorette->endDescriptionBad, 0.06f);
	}
}

int main() {
	setRaceData();
	
	//cout << returnTitle();
	readBachelorette(0);

	//playerClass player = playerClass();
	//player.characterDetails();
	//utils::waitForSecs(1.0f);
	//system("CLS");

	//bachelorette* currentBachelorette= pickBachelorette();

<<<<<<< HEAD
	mainGame(currentBachelorette, &player);
=======
	//getDialogueData(currentBachelorette);

	//mainGame(currentBachelorette, &player);
>>>>>>> parent of ad8136a (json working)
}