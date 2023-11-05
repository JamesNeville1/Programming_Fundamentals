#include <iostream>
#include <string>
#include <vector>
#include "header.h"

using namespace std;

int getPlayerRace() {
	vector<string> prompts = { "Select your characters race:" };
	for (int i = 0; i < sizeof(raceData) / sizeof(raceData[0]); i++) {
		string option = "> [" + to_string(i+1) + "] " + raceData[i].displayName;
		prompts.push_back(option);
	}

	bool chosen = false;
	int chosenRace = 0;
	vector<string> raceInfo;

	while (!chosen) {
		chosenRace = utils::promptUserOptions(prompts);

		if (raceData[chosenRace].opinionModifier > 0) {
			raceInfo.push_back("> This race is viewed highly by most, you're kind are often view as protectors and worshipped as gods.");
		}
		else if (raceData[chosenRace].opinionModifier < 0) {
			raceInfo.push_back("> This race is disrespected by the masses, you're kind are often viewed as viel and are pushed to the fringe of society.");
		}
		else {
			raceInfo.push_back("> This race is accepted by most. Most will be impartial to you");
		}

		//raceInfo.push_back("> Picking this race will make your weapon attacks do: " + raceData[chosenRace].raceDamageType);
		raceInfo.push_back("> Picking this race will increase your max health by: " + to_string(raceData[chosenRace].raceHealth));

		//cout << raceInfo[2] << endl;

		utils::promptNoInput(raceInfo);
		if (utils::yesOrNoPrompt()) chosen = true;
	}

	return chosenRace;
}

int getPlayerClass() {
	vector<string> prompts = { "Select your characters class:" };
	for (int i = 0; i < sizeof(classData) / sizeof(classData[0]); i++) {
		string option = "> [" + to_string(i+1) + "] " + classData[i].displayName;
		prompts.push_back(option);
	}

	bool chosen = false;
	int chosenClass = 0;

	while (!chosen) {
		chosenClass = utils::promptUserOptions(prompts);

		cout << classData[chosenClass].displayName << "s are ";

		if (classData[chosenClass].isRangedClass) {
			cout << " ranged character, you will be stronger at a distance, and weaker in close quaters";
		}
		else {
			cout << " melee character, you will be stronger in close quaters, and weaker at a distance";
		}

		if (utils::yesOrNoPrompt()) chosen = true;
	}

	return chosenClass;
}

playerTemp createPlayerCharacter() {
	playerTemp playersCharacter = {
		utils::promptUserString("Enter your characters name:"),
		getPlayerRace(),
		getPlayerClass()
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