#pragma once
#include "utility.h"
#include "player.h"

enum interests {
	manga,
	videogames,
	exercise,
	art,
};

map<interests, string> formatedInterests{
	{manga, "Manga"},
	{videogames, "Video Games"},
	{exercise, "Exercise"},
	{art, "Art"},
};

class dialogue {
public:
	string whatHappensText = "";
	string promptText = "";
	item* reward = NULL;
	int heartEffect = 0;
	int strikeEffect = 0;
	vector<dialogue*> response;

	void setDialogue(string whatHappensText, string promptText = "", int heartEffect = 0, int strikeEffect = 0, item* reward = NULL) {
		this->whatHappensText = whatHappensText;
		this->promptText = promptText;

		this->heartEffect = heartEffect;
		this->strikeEffect = strikeEffect;

		this->reward = reward;
	}
	void setResponses(vector<dialogue*> response) {
		this->response = response;
	}
};

class bachelorette {
public:
	string name = "Sam"; //Name
	interests specialInterest = manga; //Interest that the player needs to guess to proceed
	raceTemp* likes = NULL; //The race this bachelorette likes
	raceTemp* dislikes = NULL; //The race this bachelorette dislikes
	int currentHearts = 0; //The player must get 3 heart points to continue to date this bachelorette
	int maxHearts = 3;

	string initialDescription = "";
	string endDescriptionBad = "";
	string endDescriptionGood = "";

<<<<<<< HEAD
	vector<dialogue> dialogueData;

	#pragma region portrait
=======
	map<int, dialogue> dialogueData;
#pragma region portrait
>>>>>>> parent of ad8136a (json working)
	const char* portrait = R"(
################################%#########################**********#######################%%%%%%%%%
##############################%%#######################***************#########################%%%%%
#############################%##########################****************###########################%
###########################%%############****#############****************##########################
##########################%%############*******########**##****************#########################
#########################%%%########*#*********************#****************########################
########################%%%#######**##*****************#********************########################
########################%%########**#******************#********************########################
#######################%%%########*#********************#***********#****#*#########################
#######################%%%########*#********************##****#******##*############################
######################%%%%##########***************#****###****#**##################################
######################%%%%%##########**************#*############*##################################
######################%%%%%##############################**#########################################
#####################%%%%%%##############################***########################################
#####################%%%%%%#############################*****#######################################
#####################%%%%%%############################*******#############%########################
#####################%%%%%%###%###########################*****#%########%##%#######################
#####################%%%%%%###%#######%###############****###%#%%%##################################
####################%%%%%%%%%%##%####%##############**##%%%%%%%%%%##################################
####################%%%%%%%%%%#%%%%%%%%####*#********####%#####%%###################################
####################%%%%%%%%%%%@%#%%%%%%%#***************###########################################
####################%%%%#%%%%%%%#*########******************##***%##########%#######################
###################%%%%###%%%%######*###************************#%#########%%%######################
###################%%%%####%%%%######****************************##########%%%######################
###################%#%%####%%%%%#********************************##########%%%######################
#####################%%#####%%%%%#*******************************##########%%%######################
#####################%%#####%%%%%%*******************************%#########%%%%#####################
#####################%%#####%%%%%%%*****************************#%#########%%%%#####################
###################%#%%#####%%%%%%%%#*************************#%%%#########%%%%#####################
###################%%%%#####%%%%%%%%%%#*********************#%%%%%%#########%%%#####################
####################%%%######%%%%%%%%%%%%#****************#%%%%%%%%#########%%%%####################
####################%%%######%%%%%%%%%%%%%%%%#**********#%%%%%#%%%%#########%%%%####################
####################%%%######%%%%%%%%%%%%%%%%%%%##**###%%%%%%###%%##########%%%%%###################
#####################%%#######%%%%%%%%%%%%%%%%%%%%%%%%%%%%%######%##########%%%%%###################
####################%%%#######%%%%%%%%%%%%%%%%%%%%%%%%%%%%#######%##########%%%%%%##################
####################%%%########%%%%%%%@@@%%%%%%%%%%%%%%%##################%#%%%%%%##################
####################%%%#######%#%%%%%%%%%%%%%%%%#%%%#%####################%#######**###*******######
####################%%%#######%%%%%%%%%%%%%%#%#####%%##############%############***##**********#####
#################%##%%%#######%%%%%%%%%%%%%%#######%%##############%##########****##************####
####################%%%#######%%%%%%%%%%############%############%%%########****##***************###
####################%%########%%%%%%%%%%######################***#%%########***##*****************##
####################%%########%%%%%%%%%%##################******##%%%#######*#%#******************##
################**#%%%########%%%%%%%%%%##########**************#%%%%#########*********************#
###############***#%%%########%%%%%%%%%#************************#%%%%########**********************#
###############***#%%%#######%%%%%%%%%%#************************#%%%%########**********************#
##############****%%%########%%%%%%%%%%#************************##%%%%########*##******************#
##############***#%%%#######%%%%%%%%%%%%************************###%%%###########******************#
##########%###***#%%########%%%%%%%%%%%%************************###%%%#########*#******************#
##########%##****#%#########%%%%%%%%%%%%#***********************##%#%%##########*******************#
%%%%%########****#%#########%%%%%%%%%%%%#**********************#%###%%%#########******************#%
%%%%%%%%%%###****###########%%%%%%%%%%%%%********************#%%%%##%%%#######%##*****************#%
%%%%%%%%%%##*****########%##%%%%%%#####%%#*****************#%%%%%%%##%%%######%%#*****************#%
%%%%%%%%%%#*****########%%%#%%%%%%######%%#***************%%%%%%%%%%#%%%%#####%%#*****************%%
%%%%%%%%%%#*****#%######%%%%%%%%%########%%#************#%%%%%%%##%%#%%%%%####%%%#***************#%%
%%%%%%%%%%#*****#%######%%%%%%%%%#########%%#***#*****#%%%%%%%%#####%#%%%%%###%%##***************#%%
%%%%%%%%%#******#%######%%%%%%%%%##########%%#**#****%%%%%%%%%#########%%%%###%%#****************%%%
%%%%%%%%%#******#%####%#%%%%%%%%%%##########%%%##**#%%%%%%%%%##########%%%%%##%%#***************#%%%
%%%%%%%%%#******#%%%##%#%%%%%%%%%%%%########%%%%%#%%%%%%%%%%#########%%%%%%%%#%#****************#%%%
%%%%%%%%%#******##%%##%#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%######%%%%%%%%%#%*****************%%%%
%%%%%%%%%*********#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*****************%%%%
%%%%%%%%#**********#%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%****************#%%%%
%%%%%%%%#**********#%%@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%****************#%%%%
%%%%%%%%#**********#%%@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%****************%%%%%
%%%%%%%%#***********#%%@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@%***************#%%%%%
%%%%%%%%#************#%@@@@@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@#***************#%%%%%
%%%%%%%##************#%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%%%%%%%%%%%%%%@@@@#***************%%%%%%
%%%%%%%##*************%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%%@@@@@@@@@@#***************%%%%%%
@@@@%%%#*************#%@@@@%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#**************#%%%%%@
@@@@@@%#*************#@@@@@%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#**************#%%@@@@
@@@@@@%##************%@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@@@@@@@@@@@@@@#*************#%%@@@@@
@@@@@@###***********#%@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@@@@@@@%@@@@@@#*************#%@@@@@@
@@@@@%###**********##@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@%%@@@@@@###***********#%@@@@@@
@@@@@%###*********##%@@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@%%@@@@@%####*********##@@@@@@@
@@@@%###**********##%@@@@@@@@@%@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@@%###**********##@@@@@@@
@@@%##***********##%@@@@@@@@@@@@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%@@@@@@#************##@@@@@@@
	)";
	#pragma endregion

	void setBachelorette(int posInJson) {
		//cout << system("echo %cd%") << endl;

		ifstream fileStream("./bachelorette-data.json");

		string line;
		string buf;

		//Read file contents into buf
		while (getline(fileStream, line))
			buf += line;

		if (fileStream.is_open())
		{
			//Parses buf, not the ifstream

			//Core variables set here
			json jsonData = json::parse(buf);
			this->name = jsonData["name"];
			int interestBeforeCast = jsonData["specialIntrest"];
			this->specialInterest = static_cast<interests>(interestBeforeCast);
			this->likes = &raceData[jsonData["likes"]];
			this->dislikes = &raceData[jsonData["dislikes"]];
			this->initialDescription = jsonData["initialDescription"];
			this->endDescriptionBad = jsonData["endDescriptionBad"];
			this->endDescriptionGood = jsonData["endDescriptionGood"];

			//Dialogue set here
			for (const auto& elem : jsonData["dialogue"]) {
				dialogueData.push_back(dialogue());

				//Fix
				int heartEffect = 0;
				int strikeEffect = 0;
				if (elem["dialogue"].contains("heartEffect")) {
					heartEffect = elem["heartEffect"];
				}
				else if (elem["dialogue"] .contains("strikeEffect")) {
					strikeEffect = elem["strikeEffect"];
				}
				cout << heartEffect;
				cout << strikeEffect;
				//

				dialogueData[dialogueData.size()-1].setDialogue(elem["whatHappensText"], elem["promptText"], heartEffect, strikeEffect);
			}
			//cout << dialogueData[0].whatHappensText << endl; //Ask tutor about this
		}

		fileStream.close();
	}

	void getDialogueData(int posInJson) {
		//TEST
		vector<dialogue*> responsesTest;

		responsesTest.push_back(&this->dialogueData[1]);
		responsesTest.push_back(&this->dialogueData[2]);
		responsesTest.push_back(&this->dialogueData[3]);
		this->dialogueData[0].setResponses(responsesTest);
		responsesTest.clear();

		responsesTest.push_back(&this->dialogueData[0]);
		this->dialogueData[1].setResponses(responsesTest);
		responsesTest.clear();

		responsesTest.push_back(&this->dialogueData[0]);
		this->dialogueData[2].setResponses(responsesTest);
		responsesTest.clear();
	}

	void adjustHearts(int increaseBy) {
		this->currentHearts += increaseBy;
		utils::slowPrint(this->name + " has " + to_string(this->currentHearts) + " (of 3) hearts for you <3.", .06f);
	}
};

bachelorette bachelorettes[4];

<<<<<<< HEAD
void setBacheloretteData() {
	for (int i = 0; i < sizeof(bachelorettes) / sizeof(bachelorettes[0]); i++) {
		bachelorettes[i].setBachelorette(i);
		bachelorettes[i].getDialogueData(i);
	}
}

=======
>>>>>>> parent of ad8136a (json working)
bachelorette* pickBachelorette() {
	vector<string> bacheloretteOptions = { "Select your bachelorette:" };

	for (int i = 0; i < sizeof(bachelorettes)/sizeof(bachelorettes[0]); i++) {
		bacheloretteOptions.push_back(bachelorettes[i].name);
	}

	int input = utils::promptUserOptions(bacheloretteOptions, false);
	system("CLS");

	return &bachelorettes[input];
}

dialogue* doDialogue(dialogue* currentDialogue) {
	vector<string> prompts = { currentDialogue->whatHappensText };

	for (int i = 0; i < currentDialogue->response.size(); i++) {
		prompts.push_back(currentDialogue->response[i]->promptText);
	}

	int input = utils::promptUserOptions(prompts, true);

	return currentDialogue->response[input];
}