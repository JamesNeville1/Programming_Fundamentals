#pragma once
#include "utility.h"

class eventTemp {
	public:
	string promptText;
	string whatHappensText;
	//add item drop or something

	void setEvent(string promptText, string whatHappensText) {
		this->promptText = promptText;
		this->whatHappensText = whatHappensText;
	}
};
class nonCombatEvent : public eventTemp {
	public:
	vector<eventTemp*> options;
	bool isDialogue = false;
	void setOptions(vector<eventTemp*> options, bool isDialogue) {
		this->options = options;
		this->isDialogue = isDialogue;
	}
};
//class combatEvent : public eventTemp {
	//vector<item*> options;
	//void setOptions(vector<item*> options) {
	//	this->options = options;
	//}
//};

array<nonCombatEvent, 9> eventData;

void setEvents() {
	vector<eventTemp*> options;

	eventData[0].setEvent("", "You awaken in a strange place, you see a door");
	eventData[1].setEvent("I entre", "You entre the door, you see a man");
	eventData[2].setEvent("I do not entre", "End");
	eventData[3].setEvent("Do you open the chest", "You open the chest a find 10 gold, after that you see a door");
	eventData[4].setEvent("I kill the man", "He turns into a zombie!");
	eventData[5].setEvent("I do not kill the man", "You leave");

	eventData[6].setEvent("", "Hey, you're finally awake/You were trying to cross the border, right?/Walked right into that Imperial ambush, same as me?");
	eventData[7].setEvent("Yup", ";-;");
	eventData[8].setEvent("Non of your damn business!", "HEY!");

	options.push_back(&eventData[7]);
	options.push_back(&eventData[8]);
	eventData[6].setOptions(options, true);
}
int eventFunc(int currentEvent) {
	vector<string> eventDataPasser;

	eventDataPasser = { eventData[currentEvent].whatHappensText };
	for (int i = 0; i < eventData[currentEvent].options.size(); i++) {
		eventDataPasser.push_back(eventData[currentEvent].options[i]->promptText);
	}

	int input = utils::promptUserOptions(eventDataPasser, eventData[currentEvent].isDialogue);

	utils::dialogueBox(eventData[currentEvent].options[input]->whatHappensText);

	return input;
}
