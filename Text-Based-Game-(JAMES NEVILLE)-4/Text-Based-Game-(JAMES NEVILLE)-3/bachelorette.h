#pragma once
#include "utility.h"
#include "player.h"
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;

struct bacheloretteFiles {
	string json = "";
	string portrait = "";
};

enum interests { //All interests of bachelorette
	manga,
	videogames,
	exercise,
	art,
};

map<interests, string> formatedInterests{ //Interest is string form, easier to print with
	{manga, "Manga"},
	{videogames, "Video Games"},
	{exercise, "Exercise"},
	{art, "Art"},
};

void setMappedData (map<int, bacheloretteFiles>* bachFiles){
	bacheloretteFiles toPassStruct = {"./bachelorette-data-1.json", "samantha-portrait.txt"};
	bachFiles->insert(pair<int, bacheloretteFiles>(0, toPassStruct));
	toPassStruct = { "./bachelorette-data-2.json", "jace-portrait.txt" };
	bachFiles->insert(pair<int, bacheloretteFiles>(1, toPassStruct));
	toPassStruct = { "./bachelorette-data-3.json", "mrmarmite-portrait.txt" };
	bachFiles->insert(pair<int, bacheloretteFiles>(2, toPassStruct));
}

class dialogue { //Dialogue class, used to hold dialogue information
public:
	string whatHappensText = "";
	string promptText = "";
	//item* reward = NULL;
	int heartEffect = 0;
	int strikeEffect = 0;
	vector<dialogue*> response;

	void setDialogue(string whatHappensText, string promptText = "", int heartEffect = 0, int strikeEffect = 0/*, item* reward = NULL*/) {
		this->whatHappensText = whatHappensText;
		this->promptText = promptText;

		this->heartEffect = heartEffect;
		this->strikeEffect = strikeEffect;

		//this->reward = reward;
	}
	void setResponses(vector<dialogue*> response) {
		this->response = response;
	}
};

class bachelorette { //Bachelorette class, stores important data pertaining to the bachelorette
public:
	string name = ""; //Name
	interests specialInterest = manga; //Interest that the player needs to guess to proceed
	raceTemp* likes = NULL; //The race this bachelorette likes
	raceTemp* dislikes = NULL; //The race this bachelorette dislikes
	int currentHearts = 0; //The player must get 3 heart points to continue to date this bachelorette
	int maxHearts = 3;

	string initialDescription = ""; //Description for player to read of bachelorette
	string endDescriptionBad = ""; //If player fails this is what happens
	string endDescriptionGood = ""; //If player succeeds this happens

	vector<dialogue> dialogueData; //Hold dialogue for all bachelorettes

	string portrait = "";

	void setBachelorette(int bacheloretteID, map<int, bacheloretteFiles>* fileRef) { //Read data from json file
		ifstream fileStream(fileRef->at(bacheloretteID).json);
		
		string line;
		string buf;

		//Read file contents into buf
		while (getline(fileStream, line))
			buf += line;

		if (fileStream.is_open())
		{
			//Core variables set here
			json jsonData = json::parse(buf);
			this->name = jsonData["name"];
			int interestBeforeCast = jsonData["specialIntrest"];
			this->specialInterest = static_cast<interests>(interestBeforeCast);

			if(jsonData["likes"] > -1)
				this->likes = &raceData[jsonData["likes"]];
			if(jsonData["dislikes"] > -1)
				this->dislikes = &raceData[jsonData["dislikes"]];
			this->initialDescription = jsonData["initialDescription"];
			this->endDescriptionBad = jsonData["endDescriptionBad"];
			this->endDescriptionGood = jsonData["endDescriptionGood"];
			this->portrait = utils::returnFromTxt(fileRef->at(bacheloretteID).portrait);

			//Dialogue set here
			for (const json elem : jsonData["dialogue"]) { //loop through dialogue
				dialogueData.push_back(dialogue());

				int heartEffect = 0;
				int strikeEffect = 0;

				if (elem.contains("strikeEffect"))
					strikeEffect = elem["strikeEffect"];
				if (elem.contains("heartEffect"))
					heartEffect = elem["heartEffect"];

				dialogueData[dialogueData.size()-1].setDialogue(elem["whatHappensText"], elem["promptText"], heartEffect, strikeEffect);
			}

			//Options set here
			int dialogueIt = 0;
			for (const json elem : jsonData["dialogue"]) {
				if (elem.contains("options")) {
					for (int i = 0; i < elem["options"].size(); i++) {
						dialogueData[dialogueIt].response.push_back(&dialogueData[elem["options"].at(i)]);
					}
				}
				dialogueIt++;
			}
		}

		fileStream.close();
	}

	void adjustHearts(int increaseBy) {
		this->currentHearts += increaseBy;
		utils::slowPrint(this->name + " has " + to_string(this->currentHearts) + " (of 3) hearts for you <3.", .06f);
		utils::waitForSecs(1.0f);
	}

	bool finalTest() { //Player guesses special interest, last test to see if they win
		vector<string> lastDialogue = { this->name +
			" asks you what you are interested in: (if you get guess the same as "
			+ this->name
			+ " you will win a date)" };
		for (int i = 0; i < formatedInterests.size(); i++) {
			lastDialogue.push_back(formatedInterests[static_cast<interests>(i)]);
		}

		int input = utils::promptUserOptions(lastDialogue, false);
		
		if (lastDialogue[input+1] == formatedInterests.find(specialInterest)->second) {
			return true;
		}

		return false;
	}
};

bachelorette bachelorettes[3];

void setBacheloretteData(map<int, bacheloretteFiles>* fileRef) { //Loop through bachelorette array to set data
	for (int i = 0; i < sizeof(bachelorettes) / sizeof(bachelorettes[0]); i++) {
		bachelorettes[i].setBachelorette(i, fileRef);
	}
}

bachelorette* pickBachelorette() { //Prompt player to pick bachelorette
	vector<string> bacheloretteOptions = { "Select your bachelorette:" };

	for (int i = 0; i < sizeof(bachelorettes)/sizeof(bachelorettes[0]); i++) {
		bacheloretteOptions.push_back(bachelorettes[i].name);
	}

	int input = utils::promptUserOptions(bacheloretteOptions, false);
	system("CLS");

	return &bachelorettes[input];
}

dialogue* doDialogue(dialogue* currentDialogue) { //Take current dialogue return next
	vector<string> prompts = { currentDialogue->whatHappensText };

	for (int i = 0; i < currentDialogue->response.size(); i++) {
		prompts.push_back(currentDialogue->response[i]->promptText);
	}

	int input = utils::promptUserOptions(prompts, true);

	return currentDialogue->response[input];
}