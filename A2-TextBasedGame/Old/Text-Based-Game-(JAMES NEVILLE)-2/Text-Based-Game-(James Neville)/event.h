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

array<nonCombatEvent, 7> eventData;

void setEvents() {
	eventData[0].setEvent("", "You awaken in a strange place, you see a door");
	eventData[1].setEvent("I entre", "You entre the door, you see a man");
	eventData[2].setEvent("I do not entre", "");

	eventData[3].setEvent("I kill the man", "He turns into a zombie!");
	eventData[4].setEvent("I do not kill the man", "He gives you a gift, it's a treasure chest!");

	//Add event to fight zombie
	eventData[5].setEvent("I open the chest", "You open the chest a find 10 gold, after that you see a door");
	eventData[6].setEvent("I do not open the chest", "You open the chest a find 10 gold");

	//eventData[7].setEvent("", "Hey, you're finally awake/You were trying to cross the border, right?/Walked right into that Imperial ambush, same as me?");
	//eventData[8].setEvent("Yup", ";-;");
	//eventData[9].setEvent("Non of your damn business!", "HEY!");

	vector<eventTemp*> options;
	
	options.push_back(&eventData[1]);
	options.push_back(&eventData[2]);
	eventData[0].setOptions(options, false);
	options.clear();

	options.push_back(&eventData[3]);
	options.push_back(&eventData[4]);
	eventData[1].setOptions(options, false);
	options.clear();

	//options.push_back(&eventData[]);
	//options.push_back(&eventData[]);
	eventData[3].setOptions(options, false);
	options.clear();

	options.push_back(&eventData[5]);
	options.push_back(&eventData[6]);
	eventData[4].setOptions(options, false);
	options.clear();
}
int eventFunc(int currentEvent) {
	vector<string> eventDataPasser;

	eventDataPasser = { eventData[currentEvent].whatHappensText };
	for (int i = 0; i < eventData[currentEvent].options.size(); i++) {
		eventDataPasser.push_back(eventData[currentEvent].options[i]->promptText);
	}

	int input = utils::promptUserOptions(eventDataPasser, eventData[currentEvent].isDialogue);

	int nextEvent = 0;

	return nextEvent;
}
void mainGame() {
	int currentEvent = 0;
	while (true) {
		currentEvent = eventFunc(currentEvent);
	}
}
