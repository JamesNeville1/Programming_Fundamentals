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
	vector<int> bands;
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

	userToPass.bands = {
		70,
		60,
		50,
		40,
		30,
		0
	};

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
		else {
			cout << "*ERROR*: Input must be a number" << endl << endl;
		}
	}
}

int amountOfChars = 3;
string floatToString(float rawFloat) {
	string rawFloatString = to_string(rawFloat);

	string validFloatToOutput;
	for (int i = 0; i < amountOfChars; i++) {
		validFloatToOutput += rawFloatString[i];
	}

	return validFloatToOutput;
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

	float overallScore = 0;
	for (int i = 0; i < sizeof(user.assessmentsInfo) / sizeof(user.assessmentsInfo[0]); i++) { //Loop through assessments
		float overallScorePerAssessment = 0;
		for (int x = 0; x < user.assessmentsInfo[i].modules.size(); x++) { //Loop through modules
			float percantageTest = 0.0f;
			int moduleScore = 0;
			float overallPercentage = 0.0f;
			for (int y = 0; y < user.assessmentsInfo[i].modules[x].size(); y++) { //Loop through elements
				percantageTest += user.assessmentsInfo[i].modules[x][y].percentModif;
				moduleScore += user.assessmentsInfo[i].modules[x][y].totalAchieved;
			}
			overallPercentage = percantageTest * moduleScore;
			cout << "You got " << floatToString(overallPercentage) << "% for module " << x+1 << ", " << "Assessment " << i+1 << endl;
			overallScorePerAssessment += overallPercentage;
			
			int bandAchieved = -1;

			int looper = 0;
			while (bandAchieved < 0) {

				if (moduleScore >= user.bands[looper]) {
					bandAchieved = looper;
					if (bandAchieved  == user.bands.size() -1) {
						cout << "You did not meet the requirements for a band on module, you will have to redo this module" << endl << endl;
					}
					else {
						cout << "You achieved CRG band " << user.bands.size() - bandAchieved - 1 << " (Out of " << user.bands.size() - 1 << ")" << endl << endl;
					}
				}

				looper++;
			}
		}
		cout << "You got " << floatToString(overallScorePerAssessment) << "% for Assessment " << i + 1 << endl << endl;
		overallScore += overallScorePerAssessment;
	}

	cout << "Overall you got: " << floatToString(overallScore / 2) << "%" << endl;
}