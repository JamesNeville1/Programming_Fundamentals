#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct elementTemp {
	string elementName = "";
	int points = 0;
};
struct assessmentOneTemp {
	string assessmentName = "";
	elementTemp challenges[10];
	elementTemp reflectiveJournal;
};
struct assessmentTwoTemp {
	string assessmentName = "";
	elementTemp challenges[1];
	elementTemp criteria[2];
};

assessmentOneTemp assessmentOne = {
	"Assessment 1",
	{
		{"Challenge 1", 5},
		{"Challenge 2", 5},
		{"Challenge 3", 5},
		{"Challenge 4", 10},
		{"Challenge 5", 10},
		{"Challenge 6", 10},
		{"Challenge 7", 10},
		{"Challenge 8", 15},
		{"Challenge 9", 15},
		{"Challenge 10", 15}
	},
	{
		{"Reflective Journal", 30}
	}
};

assessmentTwoTemp assessmentTwo = {
	"Assessment 2",
	{
		{"Text-Based Game", 60}
	},
	{
		{"Code Quality & Best Practices", 20},
		{"Domonstration of programming techniques and applicability of learned techniques", 20}
	}
};

struct userScoresTemp {
	assessmentOneTemp myAssessmentOne = assessmentOne;
	assessmentTwoTemp myAssessmentTwo = assessmentTwo;
	int totalPoints;
	int totalPercent;
};

int validateInt(string raw) {
	bool valid = false;
	string rawValidated = "";

	for (int i = 0; i < raw.length(); i++) {
		if (isdigit(raw[i])) rawValidated += raw[i];
	}

	if (rawValidated != "") return stoi(rawValidated);
	else return -1;
}

int takeInput(string prompt, int max) {
	bool valid = false;
	string inputRaw = "";

	while (true) {
		cout << prompt;
		getline(cin, inputRaw);
		cout << endl;

		string inputString = "";
		for (int i = 0; i < inputRaw.length(); i++) {
			if (isdigit(inputRaw[i])) inputString += inputRaw[i];
		}

		
		if (inputString != "") return stoi(inputString);
	}
}

void main() {
	userScoresTemp userScores;
	string inputRaw = "";
	string prompt = "";

	for (int i = 0; i < sizeof(assessmentOne.challenges) / sizeof(assessmentOne.challenges[0]); i++) {
		prompt = "What did you get for " + assessmentOne.challenges[i].elementName + " (MAX " + to_string(assessmentOne.challenges[i].points) + "): ";
		userScores.myAssessmentOne.challenges[i].points = takeInput(prompt, assessmentOne.challenges[i].points);
	}

	prompt = "What did you get for " + assessmentOne.reflectiveJournal.elementName + "(Max " + to_string(assessmentOne.reflectiveJournal.points) + "): ";
	userScores.myAssessmentOne.reflectiveJournal.points = takeInput(prompt, assessmentOne.reflectiveJournal.points);

	int a = 0;
	for (int i = 0; i < sizeof(userScores.myAssessmentOne.challenges) / sizeof(userScores.myAssessmentOne.challenges[0]); i++) {
		a += userScores.myAssessmentOne.challenges[i].points;
	}
	a += userScores.myAssessmentOne.reflectiveJournal.points;

	cout << "your score is: " << a;
	cout << "What did you get for " << assessmentOne.reflectiveJournal.elementName; //<< "(Max " << to_string(assessmentOne.reflectiveJournal.points) << "): ";
}