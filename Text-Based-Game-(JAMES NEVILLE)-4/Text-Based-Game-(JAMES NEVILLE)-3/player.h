#pragma once
#include "utility.h"

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
	raceData[2] = { "Lizardfolk",1};
}

//Player class, main player functionalitise are here
class playerClass {
public:
	string name = "";
	raceTemp* race = NULL;
	int strikes = 0;
	int currentStrikes = 0;
	//array<item*, 4> inventory;
	
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
	//Add strike
	bool adjustStrikes(int increaseBy, string currentBachName) {
		this->currentStrikes += increaseBy;
		if (this->currentStrikes >= this->strikes) {
			return false;
		}
		else {
			utils::slowPrint(
				"You have " + to_string(this->currentStrikes)
				+ " (of " + to_string(this->strikes)
				+ ") strikes before " + currentBachName
				+ " walks out and this date is ruined!",
				.06f);
			utils::waitForSecs(1.0f);
			return true;
		}
	}
	#pragma endregion
	#pragma region ItemSpecific
	void addItem() {

	}
	#pragma endregion
};

//Use friends

//class item {
//public:
//	string name = "";
//	int modif = 0;
//	virtual void useItem(playerClass* player) = 0;
//	
//	item(string name, int modif = 0, playerClass* player) {
//		this->name = name;
//		this->modif = modif;
//		useItem(player);
//	}
//};
//class potionOfGreg : public item {
//public:
//	void useItem(playerClass* player) override {
//		player->name = "Greg";
//		utils::slowPrint("Your name is now " + name, .5f);
//		utils::slowPrint("It does literally nothing..." + name);
//	}
//};
//class lovePotion : public item {
//public:
//	void useItem(playerClass* player) override {
//		player->strikes += this->modif;
//	}
//};
//
//void setItemData(playerClass* player) {
//	//static lovePotion potionOfLove = item("Love Potion", 1, player);
//	//static potionOfGreg gregPotion = item("Greg Potion", player);
//}