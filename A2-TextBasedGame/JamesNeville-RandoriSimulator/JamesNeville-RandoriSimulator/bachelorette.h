#pragma once
#include "utils.h"
#include "player.h"
#include "json.hpp" //I TAKE ZERO CREDIT FOR THIS, I wrote all the code but this hpp

using json = nlohmann::json;

struct bacheloretteFiles {
	string json = "";
	string portrait = "";
};

enum interests { //All interests of bachelorette
	manga,
	videogames,
	exercise,
	food,
};

void setMappedData(map<int, bacheloretteFiles>* bachFiles);

class dialogue {
public:
	string whatHappensText = "";
	string promptText = "";
	int heartEffect = 0;
	int strikeEffect = 0;
	vector<dialogue*> response;

	void setDialogue(string whatHappensText, string promptText = "", int heartEffect = 0, int strikeEffect = 0);
	void setResponses(vector<dialogue*> response);
};

class bachelorette {
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

	static map<interests, string> formatedInterests;

	void setBachelorette(int bacheloretteID, map<int, bacheloretteFiles>* fileRef, array<raceTemp, 3>* raceDataRef);
	void adjustHearts(int increaseBy);
	bool finalTest();
	dialogue* doDialogue(dialogue* currentDialogue);
};

void setBacheloretteData(array<bachelorette, 3>* bachelorettes, map<int, bacheloretteFiles>* fileRef, array<raceTemp, 3>* raceDataRef);

bachelorette* pickBachelorette(array<bachelorette, 3>* bachelorettes);