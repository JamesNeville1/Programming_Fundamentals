#pragma once
#include "utility.h"

class eventTemp {
public:
	string promptText;
	string whatHappensText;
	vector<eventTemp*> options;
	//add item drop or something

	void setEvent(string promptText, string whatHappensText) {
		this->promptText = promptText;
		this->whatHappensText = whatHappensText;
	}
	void setOptions(vector<eventTemp*> options) {
		this->options = options;
	}
};
vector<eventTemp> eventData;
void setEvents() {
	vector<eventTemp*> options;

	eventData.resize(6);
	eventData[0].setEvent("", "You awaken in a strange place, you see a door");
	eventData[1].setEvent("I entre", "You entre the door, you see a man");
	eventData[2].setEvent("I do not entre", "End");
	eventData[3].setEvent("Do you open the chest", "You open the chest a find 10 gold, after that you see a door");
	eventData[4].setEvent("I kill the man", "He turns into a zombie!");
	eventData[5].setEvent("I do not kill the man", "You leave");

	options.push_back(&eventData[1]);
	options.push_back(&eventData[2]);
	eventData[0].setOptions(options);

}
int dialogueEvent(int currentEvent) {
	vector<string> eventDataPasser;

	eventDataPasser = { eventData[currentEvent].whatHappensText };
	for (int i = 0; i < eventData[currentEvent].options.size(); i++) {
		eventDataPasser.push_back(eventData[currentEvent].options[i]->promptText);
	}

	int input = utils::promptUserOptions(eventDataPasser);


	return input;
}
