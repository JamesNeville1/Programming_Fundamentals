#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdlib.h>
#include <cstring>
#include "header.h"
#include <windows.h> 

using namespace std;

#pragma region Type
//Damage types for both character and enemies
enum damageType {
	fire,
	poison,
	frost,
	piercing,
	slashing,
	magic,
	divine,
	sneak,
	evil
};
//Each type converted to a game ready string
#pragma region typeToString
map<damageType, string> typeToString {
	{fire, "Fire"},
	{ poison, "Poison" },
	{ frost, "Frost" },
	{ piercing, "Piercing" },
	{ slashing, "Smiting" },
	{ magic, "Magical" },
	{ divine, "Divine" },
	{ sneak, "Dark" },
	{ evil, "Hell" }
};
#pragma endregion
#pragma endregion
#pragma region Race
//The race object template
struct raceTemp {
	string displayName = "";
	damageType raceDamageType = fire;
	int raceHealth = 0;
	float opinionModifier = 0.0f;
	bool avaliableWhenOpened = true;
};
//The array to store the race's data
raceTemp raceData[] = {
	{"Dragonborn", fire, 20, 0.0f},
	{"Snakeborn", poison, 30, -1.65f},
	{"Ice Elemental", frost, 12, 2.0f}
};
#pragma endregion
#pragma region Class
//The class object template
class classTemp {
	public:
	string displayName = "";
	int classHealth = 0;
	int maxDamageRoll = 0;
	damageType classDamageType;
	bool isRangedClass = false;
	bool avaliableWhenOpened = true;
};
//The array to store the class's data
classTemp classData[] = {
	{"Knight", 25, 6, slashing, false, true},
	{"Archer", 18, 8, piercing, true, true},
	{"Wizard", 10, 12, magic, true, true},
	{"Paladin", 32, 8, divine, false, true},
	{"Thief", 22, 10, sneak, true, true},
	{"Warlock", 7, 20, evil, true, true},
};
#pragma endregion
#pragma region Npc
//The npc object template
struct npc {
	string name = "";
	bool isMale = true;
	struct salesman {

	};
	struct regular {

	};
};
#pragma endregion
#pragma region Events
//The decision object template
struct descision {
	string option;
	int eventID;
};
//The event object template
struct eventTemp {
	string prompt;
	descision de[10];
};
//The array to store the event's data
eventTemp eventData[] = {
	{
		{"Do you go left or right?"},
		{{"Left", 1}, "Right", 2}
	},
	{
		{"You find a big monster"},
		{{"Fight!", 2}, {"Flee!", 0}}
	},
	{
		{"You find a treasure chest"},
		{{"Open", 1}, {"Don't risk it!", 0}}
	}
};
#pragma endregion
#pragma region Utils
//My utils class, holding all important functions that I will reuse time and time again
class utils {
public: class core {
public: static int validateInt(string raw) {
	bool valid = false;
	string rawValidated = "";

	for (int i = 0; i < raw.length(); i++) {
		if (isdigit(raw[i])) rawValidated += raw[i];
	}

	if (rawValidated != "") return stoi(rawValidated);
	else return -1;
}
public: static int promptUserOptions(vector<string> prompts) {
	bool valid = false;
	int validInt = 0;

	while (!valid) {
		cout << prompts[0] << endl;
		for (int i = 1; i < prompts.size(); i++) {
			cout << "> [" + to_string(i) + "] " << prompts[i] << endl;
		}

		string rawInput = "";
		getline(cin, rawInput);
		cout << endl;

		validInt = validateInt(rawInput) - 1;

		if (validInt >= 0 && validInt < prompts.size() - 1) valid = true;
		else cout << "Error: Please ensure you input is valid" << endl;
	}
	return validInt;
}
public: static string promptUserOptions(string prompt) {
	cout << prompt << " ";

	string input = "";
	getline(cin, input);

	return input;
}
public: static void promptNoInput(vector<string> prompts) {
	for (int i = 0; i < prompts.size(); i++) {
		cout << prompts[i] << endl;
	}
}
public: static bool yesOrNoPrompt() {
	//bool confirmed = false;
	while (true) { //check if bad?
		cout << endl;
		string input = promptUserOptions("Confirm: (y/n)");

		if (input == "y" || input == "Y") {
			cout << endl;
			return true;
		}
		else if (input == "n" || input == "N") {
			cout << endl;
			return false;
		}
	}
}
public: static void slowPrint(string rawText, float waitFor) {
	for (int i = 0; i < rawText.length(); i++) {
		cout << rawText[i];
		Sleep(waitFor * 1000);
	}
	cout << endl;
}
public: static void slowPrint(string rawText) {
	float waitFor = 0.01f;
	for (int i = 0; i < rawText.length(); i++) {
		cout << rawText[i];
		Sleep(waitFor * 1000);
	}
	cout << endl;
}
private: static string dialogueboxBounds(string prompt) {
	string output = "";
	for (int i = 0; i < prompt.length(); i++) {
		output += "*";
	}
	output += "************";
	return output;
}
public: static void dialogueBox(string prompt, int colour) {
	float waitFor = 0.02f;
	slowPrint(dialogueboxBounds(prompt));
	//cout << dialogueboxSpace(prompt) << endl;
	slowPrint("*     " + prompt + "     *", waitFor);
	//cout << dialogueboxSpace(prompt) << endl;
	slowPrint(dialogueboxBounds(prompt));
	cout << endl;
}
};
public: class information {
public:static vector<string> raceInfo(int chosenRaceInt) {
	vector<string> info;
	if (raceData[chosenRaceInt].opinionModifier > 0) {
		info.push_back("> This race is viewed highly by most, you're kind are often view as protectors and worshipped as gods.");
	}
	else if (raceData[chosenRaceInt].opinionModifier < 0) {
		info.push_back("> This race is disrespected by the masses, you're kind are often viewed as viel and are pushed to the fringe of society.");
	}
	else {
		info.push_back("> This race is accepted by most. Most will be impartial to you");
	}
	info.push_back("> This race will add an additional " + to_string(raceData[chosenRaceInt].raceHealth) + " health");
	return info;
}
public:static vector<string> classInfo(int chosenClassInt) {
	vector<string> info;
	if (classData[chosenClassInt].isRangedClass) info.push_back("> If you chose this class, you will be more effective at a distance.");
	else info.push_back("> If you choose this class, you will be more effective in close quaters.");
	info.push_back("> This class will add an additional " + to_string(classData[chosenClassInt].classHealth) + " health");
	info.push_back("> You roll a d" + to_string(classData[chosenClassInt].maxDamageRoll) + " when rolling damage");
	return info;
}
};
public: class eventSpecific {
public: static void eventFunc() {
	int currentEvent = 0;
	while (true) {

		vector<string> prints;
		prints.push_back(eventData[0].prompt);

		for (int i = 0; i < sizeof(eventData[0].de) / sizeof(eventData[0].de[0]); i++) {
			prints.push_back(eventData[currentEvent].de[i].option);
		}

		int input = utils::core::promptUserOptions(prints);
	}
}
};
};
#pragma endregion
#pragma region Other
int getPlayerTemps(bool getRace) {
	vector<string> prompts = { "Select your " };
	int loopFor = 0;

	if (getRace) {
		prompts[0] += "race";
		loopFor = sizeof(raceData) / sizeof(raceData[0]);
		for (int i = 0; i < loopFor; i++) {
			string option = raceData[i].displayName;
			prompts.push_back(option);
		}
	}
	else {
		prompts[0] += "class";
		loopFor = sizeof(classData) / sizeof(classData[0]);
		for (int i = 0; i < loopFor; i++) {
			string option = classData[i].displayName;
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
string ReturnTitle() {
	const char* titleScreen = R"(
	BBBBBBBBBBBBBBBBB                     lllllll             d::::::d                                       '::::'                              GGGGGGGGGGGGG                           tttt                                          444444444  
	B::::::::::::::::B                    l:::::l             d::::::d                                       '::::'                           GGG::::::::::::G                        ttt:::t                                         4::::::::4  
	B::::::BBBBBB:::::B                   l:::::l             d::::::d                                       ':::''                         GG:::::::::::::::G                        t:::::t                                        4:::::::::4  
	BB:::::B     B:::::B                  l:::::l             d:::::d                                       ':::'                          G:::::GGGGGGGG::::G                        t:::::t                                       4::::44::::4  
	B::::B     B:::::B  aaaaaaaaaaaaa    l::::l     ddddddddd:::::d uuuuuu    uuuuuu  rrrrr   rrrrrrrrr   ''''       ssssssssss         G:::::G       GGGGGG  aaaaaaaaaaaaa   ttttttt:::::ttttttt        eeeeeeeeeeee            4::::4 4::::4  
	B::::B     B:::::B  a::::::::::::a   l::::l   dd::::::::::::::d u::::u    u::::u  r::::rrr:::::::::r           ss::::::::::s       G:::::G                a::::::::::::a  t:::::::::::::::::t      ee::::::::::::ee         4::::4  4::::4  
	B::::BBBBBB:::::B   aaaaaaaaa:::::a  l::::l  d::::::::::::::::d u::::u    u::::u  r:::::::::::::::::r        ss:::::::::::::s      G:::::G                aaaaaaaaa:::::a t:::::::::::::::::t     e::::::eeeee:::::ee      4::::4   4::::4  
	B:::::::::::::BB             a::::a  l::::l d:::::::ddddd:::::d u::::u    u::::u  rr::::::rrrrr::::::r       s::::::ssss:::::s     G:::::G    GGGGGGGGGG           a::::a tttttt:::::::tttttt    e::::::e     e:::::e     4::::444444::::444
	B::::BBBBBB:::::B     aaaaaaa:::::a  l::::l d::::::d    d:::::d u::::u    u::::u   r:::::r     r:::::r        s:::::s  ssssss      G:::::G    G::::::::G    aaaaaaa:::::a       t:::::t          e:::::::eeeee::::::e     4::::::::::::::::4
	B::::B     B:::::B  aa::::::::::::a  l::::l d:::::d     d:::::d u::::u    u::::u   r:::::r     rrrrrrr          s::::::s           G:::::G    GGGGG::::G  aa::::::::::::a       t:::::t          e:::::::::::::::::e      4444444444:::::444
	B::::B     B:::::B a::::aaaa::::::a  l::::l d:::::d     d:::::d u::::u    u::::u   r:::::r                         s::::::s        G:::::G        G::::G a::::aaaa::::::a       t:::::t          e::::::eeeeeeeeeee                 4::::4  
	B::::B     B:::::Ba::::a    a:::::a  l::::l d:::::d     d:::::d u:::::uuuu:::::u   r:::::r                   ssssss   s:::::s       G:::::G       G::::Ga::::a    a:::::a       t:::::t    tttttte:::::::e                          4::::4  
	BB:::::BBBBBB::::::Ba::::a    a:::::a l::::::ld::::::ddddd::::::ddu:::::::::::::::uu r:::::r                   s:::::ssss::::::s       G:::::GGGGGGGG::::Ga::::a    a:::::a       t::::::tttt:::::te::::::::e                         4::::4  
	B:::::::::::::::::B a:::::aaaa::::::a l::::::l d:::::::::::::::::d u:::::::::::::::u r:::::r                   s::::::::::::::s         GG:::::::::::::::Ga:::::aaaa::::::a       tt::::::::::::::t e::::::::eeeeeeee               44::::::44
	B::::::::::::::::B   a::::::::::aa:::al::::::l  d:::::::::ddd::::d  uu::::::::uu:::u r:::::r                    s:::::::::::ss            GGG::::::GGG:::G a::::::::::aa:::a        tt:::::::::::tt  ee:::::::::::::e               4::::::::4
	BBBBBBBBBBBBBBBBB     aaaaaaaaaa  aaaallllllll   ddddddddd   ddddd    uuuuuuuu  uuuu rrrrrrr                     sssssssssss                 GGGGGG   GGGG  aaaaaaaaaa  aaaa          ttttttttttt      eeeeeeeeeeeeee               4444444444
	)";

	return titleScreen;
}
#pragma endregion
#pragma region Player
//The player class, holding all data relevant to the player, as well as functions that manipulate them
class playerTemp {
public:
	string name;
	int health;
	int playerRaceID;
	int playerClassID;
	playerTemp() {
		this->name = utils::core::promptUserOptions("Enter your characters name:");
		this->playerRaceID = getPlayerTemps(true);
		this->playerClassID = getPlayerTemps(false);
		this->health = raceData[playerRaceID].raceHealth + classData[playerClassID].classHealth;
	}
	void characterDetails() {
		cout << "Character Details:" << endl
			<< this->name << endl
			<< raceData[this->playerRaceID].displayName << endl
			<< classData[this->playerClassID].displayName << endl
			<< "Health: " << this->health << endl
			<< "Types: "
			<< typeToString.find(classData[this->playerClassID].classDamageType)->second << " "
			<< typeToString.find(raceData[this->playerRaceID].raceDamageType)->second << endl << endl;
	}
};
#pragma endregion

int main() {
	//cout << ReturnTitle() << endl;

	playerTemp playersCharacter = playerTemp();
	playersCharacter.characterDetails();
	

	utils::core::dialogueBox("Hey, you're finally awake", 1);
	utils::core::dialogueBox("You were trying to cross the border, right?", 2);
	utils::core::dialogueBox("Walked right into that Imperial ambush, same as me?", 3);

	//utils::eventSpecific::eventFunc();
}