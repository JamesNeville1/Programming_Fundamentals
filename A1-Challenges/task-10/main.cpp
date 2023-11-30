#include <iostream>
#include <string>
#include <vector>

using namespace std;

//ON OPEN, CLOSE REGIONS AND FUNCTIONS, MORE READABLE

#pragma region structures
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
#pragma endregion
#pragma region data
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
#pragma endregion
#pragma region utils
int validateInt(const string raw) {
	bool valid = false;
	string rawValidated = "";

	for (int i = 0; i < raw.length(); i++) {
		if (isdigit(raw[i])) rawValidated += raw[i];
	}

	if (rawValidated != "") return stoi(rawValidated);
	else return -1;
}
string floatToString(const float rawFloat, const int amountOfChars = 3) {
	string rawFloatString = to_string(rawFloat);

	string validFloatToOutput;
	if (amountOfChars > rawFloatString.size()) {
		return rawFloatString;
	}

	for (int i = 0; i < amountOfChars; i++) {
		validFloatToOutput += rawFloatString[i];
	}

	if (validFloatToOutput[validFloatToOutput.size() - 1] == '.') {
		validFloatToOutput.pop_back();
	}

	return validFloatToOutput;
}
int takeInput(const string prompt, const int max) {
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
#pragma endregion
#pragma region main
void inputAssessment(userScoresTemp* user, const int assessment) {
	for (int x = 0; x < user->assessmentsInfo[assessment].modules.size(); x++) { //Loop through modules
		for (int y = 0; y < user->assessmentsInfo[assessment].modules[x].size(); y++) { //Loop through elements
			string prompt = "What did this user achieve for Assessment " + to_string(assessment + 1) + ", " + user->assessmentsInfo[assessment].modules[x][y].elementName
				+ " (Max " + to_string(user->assessmentsInfo[assessment].modules[x][y].points) + "): ";
			int input = takeInput(prompt, user->assessmentsInfo[assessment].modules[x][y].points); //Take input
			user->assessmentsInfo[assessment].modules[x][y].totalAchieved = input; //Set user score
		}
	}
}
float outputAssessment(const userScoresTemp* user, const int assessment) {
	float overallScorePerAssessment = 0;
	for (int x = 0; x < user->assessmentsInfo[assessment].modules.size(); x++) { //Loop through modules
		float percantageModif = 0.0f;
		int moduleScore = 0;

		float overallPercentage = 0.0f;
		for (int y = 0; y < user->assessmentsInfo[assessment].modules[x].size(); y++) { //Loop through elements
			percantageModif += user->assessmentsInfo[assessment].modules[x][y].percentModif;
			moduleScore += user->assessmentsInfo[assessment].modules[x][y].totalAchieved;
		}

		overallPercentage = percantageModif * moduleScore;
		cout << "You got " << floatToString(overallPercentage) << "% for module " << x + 1 << ", " << "Assessment " << assessment + 1 << endl;
		overallScorePerAssessment += overallPercentage;

		int bandAchieved = -1; //Set to -1 as array elemnt can not be -1
		int looper = 0;
		while (bandAchieved < 0) {

			if (moduleScore >= user->bands[looper]) {
				bandAchieved = looper;
				if (bandAchieved == user->bands.size() - 1) {
					cout << "You did not meet the requirements for a band on module, you will have to redo this module" << endl << endl;
				}
				else {
					cout << "You achieved CRG band " << user->bands.size() - bandAchieved - 1 << " (Out of " << user->bands.size() - 1 << ")" << endl << endl;
				}
			}

			looper++;
		}
	}
	cout << "You got " << floatToString(overallScorePerAssessment) << "% for Assessment " << assessment + 1 << endl << endl;
	return overallScorePerAssessment;
}
#pragma endregion

void main() {
	userScoresTemp user = SetTemps(); //Set user
	
	int input = 0;
	inputAssessment(&user, 0); //Take in data for assessment 1
	inputAssessment(&user, 1); //Take in data for assessent 2

	float overallScore = 0;
	overallScore += outputAssessment(&user, 0); //Output data for assessment 1
	overallScore += outputAssessment(&user, 1); //Output data for assessment 2

	cout << "After weighing, overall you got: " << floatToString(overallScore / 2) << "%" << endl; //Output overall score
}