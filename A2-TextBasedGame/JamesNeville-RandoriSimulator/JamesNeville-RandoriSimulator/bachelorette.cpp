#include "bachelorette.h"

map<interests, string> formatedInterests{
	{ manga, "Manga"},
	{ videogames, "Video Games" },
	{ exercise, "Exercise" },
	{ food, "Food" },
};

void setMappedData(map<int, bacheloretteFiles>* bachFiles) {
	bacheloretteFiles toPassStruct = { "./bachelorette-data-1.json", "samantha-portrait.txt" };
	bachFiles->insert(pair<int, bacheloretteFiles>(0, toPassStruct));
	toPassStruct = { "./bachelorette-data-2.json", "jace-portrait.txt" };
	bachFiles->insert(pair<int, bacheloretteFiles>(1, toPassStruct));
	toPassStruct = { "./bachelorette-data-3.json", "mrmarmite-portrait.txt" };
	bachFiles->insert(pair<int, bacheloretteFiles>(2, toPassStruct));
}

void dialogue::setDialogue(string whatHappensText, string promptText, int heartEffect, int strikeEffect) {
	this->whatHappensText = whatHappensText;
	this->promptText = promptText;

	this->heartEffect = heartEffect;
	this->strikeEffect = strikeEffect;
}
void dialogue::setResponses(vector<dialogue*> response) {
	this->response = response;
}
void bachelorette::setBachelorette(int bacheloretteID, map<int, bacheloretteFiles>* fileRef, array<raceTemp, 3>* raceDataRef) {
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

		if (jsonData["likes"] > -1)
			this->likes = &raceDataRef->at(jsonData["likes"]);
		if (jsonData["dislikes"] > -1)
			this->dislikes = &raceDataRef->at(jsonData["dislikes"]);
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

			dialogueData[dialogueData.size() - 1].setDialogue(elem["whatHappensText"], elem["promptText"], heartEffect, strikeEffect);
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
void bachelorette::adjustHearts(int increaseBy) {
	this->currentHearts += increaseBy;
	utils::slowPrint(this->name + " has " + to_string(this->currentHearts) + " (of 3) hearts for you <3.", .06f, 1);
}
bool bachelorette::finalTest() {
	vector<string> lastDialogue = { this->name +
			" asks you what you are interested in: (if you get guess the same as "
			+ this->name
			+ " you will win a date)" };
	for (int i = 0; i < formatedInterests.size(); i++) {
		lastDialogue.push_back(formatedInterests[static_cast<interests>(i)]);
	}

	int input = utils::promptUserOptions(lastDialogue, false);

	if (lastDialogue[input + 1] == formatedInterests.find(specialInterest)->second) {
		return true;
	}

	return false;
}

void setBacheloretteData(array<bachelorette, 3>* bachelorettes ,map<int, bacheloretteFiles>* fileRef, array<raceTemp, 3>* raceDataRef) { //Loop through bachelorette array to set data
	for (int i = 0; i < bachelorettes->size(); i++) {
		bachelorettes->at(i).setBachelorette(i, fileRef, raceDataRef);
	}
}

bachelorette* pickBachelorette(array<bachelorette, 3>* bachelorettes) { //Prompt player to pick bachelorette
	vector<string> bacheloretteOptions = { "Select your bachelorette:" };

	for (int i = 0; i < bachelorettes->size(); i++) {
		bacheloretteOptions.push_back(bachelorettes->at(i).name);
	}

	int input = utils::promptUserOptions(bacheloretteOptions, false);
	system("CLS");

	return &bachelorettes->at(input);
}

dialogue* doDialogue(dialogue* currentDialogue) { //Take current dialogue return next
	vector<string> prompts = { currentDialogue->whatHappensText };

	for (int i = 0; i < currentDialogue->response.size(); i++) {
		prompts.push_back(currentDialogue->response[i]->promptText);
	}

	int input = utils::promptUserOptions(prompts, true);

	return currentDialogue->response[input];
}