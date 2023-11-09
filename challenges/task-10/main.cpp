#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct elementTemp {
	string elementName = "";
	int points = 0;
	float percentModif = 1;
	int totalAchieved = 0;
};
struct assessmentTemp {
	vector<vector<elementTemp>> modules = vector<vector<elementTemp>>();
};
struct userScoresTemp {
	assessmentTemp assessmentsInfo[2];
	int totalPoints;
	int totalPercent;
};

userScoresTemp SetTemps(){
	userScoresTemp userToPass = userScoresTemp();
	userToPass.assessmentsInfo[0] = {
		{
			{
				{"Challenge 1", 5, .07f},
				{"Challenge 2", 5, .07f},
				{"Challenge 3", 5, .07f},
				{"Challenge 4", 10, .07f},
				{"Challenge 5", 10, .07f},
				{"Challenge 6", 10, .07f},
				{"Challenge 7", 10, .07f},
				{"Challenge 8", 15, .07f},
				{"Challenge 9", 15, .07f},
				{"Challenge 10", 15, .07f}
			},
			{
				{"Reflective Journal", 100, .3f}
			}
		},
	};

	userToPass.assessmentsInfo[1] = {
		{
			{
				{"Text-Based Game Artefact", 100, .6f}
			},
			{
				{"Code Quality and Best Practices", 100, .2f}
			},
			{
				{"Demonstation of skills and techniques", 100, .2f}
			}
		},
	};

	//for (int i = 0; i < sizeof(userToPass.assessmentsInfo) / sizeof(userToPass.assessmentsInfo[0]); i++) { //Loop through assessments
	//	//cout << "assessment " << i + 1 << endl;
	//	for (int x = 0; x < userToPass.assessmentsInfo[i].modules.size(); x++) { //Loop through modules
	//		//cout << "assessment " << i + 1 << " has " << x + 1 << " module(s)" << endl;
	//		for (int y = 0; y < userToPass.assessmentsInfo[i].modules[x].size(); y++) { //Loop through elements
	//			//cout << "assessment " << i + 1 << " has " << x + 1 << " module(s)" << " with " << y+1 << " elements" << endl;
	//			//userToPass.assessmentsInfo[i].totalWorth = userToPass.assessmentsInfo[i].modules[x][y].points;
	//		}
	//	}
	//}

	return userToPass;
}

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
	//bool valid = false;
	string inputRaw = "";

	while (true) {
		cout << prompt << " ";
		getline(cin, inputRaw);
		cout << endl;

		string inputString = "";
		for (int i = 0; i < inputRaw.length(); i++) {
			if (isdigit(inputRaw[i])) inputString += inputRaw[i];
		}

		if (inputString != "") {
			int validInt = stoi(inputString);
			if (validInt >= 0 && validInt <= max) {
				return validInt;
			}
			else {
				cout << "*ERROR*: Enter a number between 0 and " << max << " " << endl << endl;
			}
		}
	}
}

void main() {
	userScoresTemp user = SetTemps();
	int input = 0;

	//cout << user.assessmentsResults[0].modules[0][5].elementName;

	for (int i = 0; i < sizeof(user.assessmentsInfo) / sizeof(user.assessmentsInfo[0]); i++) { //Loop through assessments
		for (int x = 0; x < user.assessmentsInfo[i].modules.size(); x++) { //Loop through modules
			for (int y = 0; y < user.assessmentsInfo[i].modules[x].size(); y++) { //Loop through elements
				string prompt = "What did this user achieve for Assessment " + to_string(i + 1) + ", " + user.assessmentsInfo[i].modules[x][y].elementName 
					+ " (Max " + to_string(user.assessmentsInfo[i].modules[x][y].points) + "): ";
				input = takeInput(prompt, user.assessmentsInfo[i].modules[x][y].points);
				user.assessmentsInfo[i].modules[x][y].totalAchieved = input;
			}
		}
	}

	for (int i = 0; i < sizeof(user.assessmentsInfo) / sizeof(user.assessmentsInfo[0]); i++) { //Loop through assessments
		int overallScore = 0;
		for (int x = 0; x < user.assessmentsInfo[i].modules.size(); x++) { //Loop through modules
			float percantageTest = 0.0f;
			int test = 0;
			float overallPercentage = 0.0f;
			for (int y = 0; y < user.assessmentsInfo[i].modules[x].size(); y++) { //Loop through elements
				percantageTest += user.assessmentsInfo[i].modules[x][y].percentModif;
				test += user.assessmentsInfo[i].modules[x][y].totalAchieved;
			}
			overallPercentage = percantageTest * test;
			overallScore += overallPercentage;
		}
		cout << "You got " << to_string(overallScore) << "% for Assessment " << i + 1 << endl;
	}

	//cout << "You got " << user.assessmentsResults[0].modules[0][5].points;
}