#include "utils.h"
#include "bachelorette.h"

using namespace std;

void mainGame(bachelorette* currentBachelorette, playerClass* player) {

	utils::slowPrint(currentBachelorette->initialDescription, .055f, 3);

	dialogue* currentDialogue = &currentBachelorette->dialogueData[0]; //Set dialogue to first in vector

	bool loop = true;

	if (player->race == currentBachelorette->likes) { //Check if race is liked
		utils::slowPrint("This bacholerett seems to already like you!", 0.05f);
		currentBachelorette->adjustHearts(1);
	}
	else if (player->race == currentBachelorette->dislikes) { //Check if race is disliked
		utils::slowPrint(currentBachelorette->name + " seems to not like the cut of your jib.", 0.05f);
		loop = false;
	}

	while (loop) { //Loop if bool is true
		if (currentDialogue->heartEffect != 0) { //Check if dialogue has effect on hearts 
			currentBachelorette->adjustHearts(currentDialogue->heartEffect);
		}

		if (currentDialogue->strikeEffect != 0) { //Checl if dialogue has effect on strikes
			loop = player->adjustStrikes(currentDialogue->strikeEffect, currentBachelorette->name);
		}
		system("CLS");

		cout << currentBachelorette->portrait << endl; //Print bachelorette portrait

		if (player->currentStrikes >= player->strikes) { //Check if strikes is at max or above, if so player loses
			utils::slowPrint(currentBachelorette->endDescriptionBad, 0.06f);
			loop = false;
		}
		else if (currentDialogue->response.size() <= 0) { //Check if the dialogue has any responses, if not, end
			if (currentBachelorette->currentHearts >= currentBachelorette->maxHearts && currentBachelorette->finalTest()) {
				utils::slowPrint(currentBachelorette->endDescriptionGood, 0.06f);
			}
			else {
				utils::slowPrint(currentBachelorette->endDescriptionBad, 0.06f);
			}
			loop = false;
		}
		else currentDialogue = doDialogue(currentDialogue); //Continue if other statements are false
	}
}

int main() {

	#pragma region Data Instantiation
	array<raceTemp, 3> raceData; //Store race data
	map<int, bacheloretteFiles> mappededData; //Map directories to 
	array<bachelorette, 3> bachelorettes; //Store bachelorette data
	#pragma endregion

	#pragma region Set Data
	setRaceData(&raceData);
	setMappedData(&mappededData);
	setBacheloretteData(&bachelorettes ,&mappededData, &raceData);
	#pragma endregion

	bool loop = true;
	while (loop) {
		cout << utils::returnFromTxt("title.txt") << endl;

		#pragma region Create Player
		playerClass player = playerClass(&raceData);
		player.characterDetails();
		utils::waitForSecs(1.0f);
		system("CLS");
		#pragma endregion

		bachelorette* currentBachelorette = pickBachelorette(&bachelorettes); //Player selects bachelorette
		currentBachelorette->currentHearts = 0;

		mainGame(currentBachelorette, &player); //Main game here

		loop = utils::yesOrNoPrompt("Play Again:");

		system("CLS");
	}
	cout << "Good Bye ;-;";
}