#include <iostream>
#include <string>
#include <vector>
#include "header.h"

using namespace std;

int getPlayerTemps(bool getRace) {
	vector<string> prompts = { "Select your " };
	int loopFor = 0;

	if (getRace) {
		prompts[0] += "race";
		loopFor = sizeof(raceData) / sizeof(raceData[0]);
		for (int i = 0; i < loopFor; i++) {
			string option = "> [" + to_string(i + 1) + "] " + raceData[i].displayName;
			prompts.push_back(option);
		}
	}
	else {
		prompts[0] += "class";
		loopFor = sizeof(classData) / sizeof(classData[0]);
		for (int i = 0; i < loopFor; i++) {
			string option = "> [" + to_string(i + 1) + "] " + classData[i].displayName;
			prompts.push_back(option);
		}
	}

	bool hasChosen = false;
	int chosenTemp = 0;
	vector<string> info;

	while (!hasChosen) {
		chosenTemp = utils::core::promptUserOptions(prompts);

		if (getRace) info = utils::information::raceInfo(chosenTemp);
		else info = utils::information::classInfo(chosenTemp);

		utils::core::promptNoInput(info);
		if (utils::core::yesOrNoPrompt()) hasChosen = true;
	}

	return chosenTemp;
}

playerTemp createPlayerCharacter() {
	playerTemp playersCharacter = {
		utils::core::promptUserString("Enter your characters name:"),
		getPlayerTemps(true),
		getPlayerTemps(false)
	};

	cout << "Character Details:" << endl
		<< playersCharacter.name << endl
		<< raceData[playersCharacter.playerRaceID].displayName << endl
		<< classData[playersCharacter.playerClassID].displayName << endl;

	return playersCharacter;
}

int main() {
	playerTemp playersCharacter = createPlayerCharacter();
}