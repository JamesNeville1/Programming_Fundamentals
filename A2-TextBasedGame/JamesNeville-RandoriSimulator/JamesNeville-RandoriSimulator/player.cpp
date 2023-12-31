#include "player.h"

void setRaceData(array<raceTemp, 3>* raceDataRef) { //Set race data
	raceDataRef->at(0) = { "Human", 3 };
	raceDataRef->at(1) = { "Orc", 2 };
	raceDataRef->at(2) = { "The Chosen One",1 };
}

playerClass::playerClass(array<raceTemp, 3>* raceDataRef) { //playerClasses constructor, take input by player
	bool confirmed = false;
	while (!confirmed) {
		this->name = utils::promptUser("Enter your character's name: ");
		name[0] = utils::returnCapitalised(name[0]);
		this->race = getPlayerRace(raceDataRef);
		this->strikes = this->race->stikes;

		string confirmationPrompt = "Are you sure this is the character you wish to play! \nyou'll have "
			+ to_string(this->strikes)
			+ " strikes before the bachelorette loses interest\n";
		confirmed = utils::yesOrNoPrompt(confirmationPrompt);
	}
}
raceTemp* playerClass::getPlayerRace(array<raceTemp, 3>* raceDataRef) { //Get player race from user
	vector<string> prompts = { "Select your race: " };
	for (int i = 0; i < raceDataRef->size(); i++) {
		prompts.push_back(raceDataRef->at(i).displayName);
	}

	int input = utils::promptUser(prompts, false);

	return &raceDataRef->at(input);
}
void playerClass::characterDetails() { //Output player details
	cout << "Character Details:" << endl
		<< "Name: " << this->name << endl
		<< "Race: " << this->race->displayName << endl
		<< "Strikes: " << this->strikes << endl;
	utils::waitForSecs(2);
}
bool playerClass::adjustStrikes(int increaseBy, string currentBachName) { //Adjust player strikes, if at max return false and game ends
	this->currentStrikes += increaseBy;
	if (this->currentStrikes >= this->strikes) {
		return false;
	}
	else {
		utils::slowPrint(
			"You have " + to_string(this->currentStrikes)
			+ " (of " + to_string(this->strikes)
			+ ") strikes before " + currentBachName
			+ " walks out and your chances are ruined!",
			.06f, 1);
		return true;
	}
}