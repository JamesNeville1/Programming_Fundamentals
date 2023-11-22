#pragma once
#include "utility.h"
#include "items.h"

//The race object template
struct raceTemp {
	string displayName = "";
	int stikes = 0;
};

array<raceTemp, 3> raceData = array<raceTemp, 3>();

//The array to store the race's data
void setRaceData() {
	raceData[0] = { "Human", 3};
	raceData[1] = { "Orc", 2};
	raceData[2] = { "Lizardfolk",0};
}

//Player class, main player functionalitise are here
class playerClass {
public:
	string name = "";
	raceTemp* race = NULL;
	int strikes = 0;
	array<item*, 4> inventory;
	
	#pragma region Core
	//Constructor, used to set all variables via player input
	playerClass() {
		bool confirmed = false;
		while (!confirmed) {
			this->name = utils::promptUserOptions("Enter your character's name: ");
			this->race = getPlayerRace();
			this->strikes = this->race->stikes;

			string confirmationPrompt = "Are you sure this is the character you wish to play! \nyou'll have "
				+ to_string(this->strikes)
				+ " strikes before the bachelorette loses interest\n";
			confirmed = utils::yesOrNoPrompt(confirmationPrompt);
		}
	}
	//Get race specific details
	raceTemp* getPlayerRace() {
		vector<string> prompts = { "Select your race: " };
		for (int i = 0; i < raceData.size(); i++) {
			prompts.push_back(raceData[i].displayName);
		}

		int input = utils::promptUserOptions(prompts, false);

		return &raceData[input];
	}
	//Output player details
	void characterDetails() {
		cout << "Character Details:" << endl
			<< "Name: " << this->name << endl
			<< "Race: " << this->race->displayName << endl
			<< "Strikes: " << this->strikes << endl;
	}
	#pragma endregion
};