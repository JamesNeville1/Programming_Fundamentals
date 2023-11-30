#include "utils.h"
int utils::validateInt(const string raw) { //Used to validate ints by passing in a raw string
	bool valid = false;
	string rawValidated = "";

	for (int i = 0; i < raw.length(); i++) {
		if (isdigit(raw[i])) rawValidated += raw[i];
	}

	if (rawValidated != "") return stoi(rawValidated);
	else return -1;
}
int utils::promptUser(const vector<string> prompts, const bool isDialogue) { //prompt user with options, only takes int
	bool valid = false;
	int validInt = 0;

	while (!valid) {
		if (!isDialogue)cout << prompts[0] << endl;
		else dialogueBox(prompts[0]);

		for (int i = 1; i < prompts.size(); i++) {
			cout << "> [" + to_string(i) + "] " << prompts[i] << endl;
		}
		cout << "<  ";
		string rawInput = "";
		getline(cin, rawInput);
		cout << endl;

		validInt = validateInt(rawInput) - 1;

		if (validInt >= 0 && validInt < prompts.size() - 1) valid = true;
		else {
			cout << "Error: Please ensure your input is valid" << endl;
		}
	}
	return validInt;
}
string utils::promptUser(const string prompt) { //prompt user, only take string
	bool valid = false;
	string validInput = "";
	while (!valid) {
		cout << prompt << " ";

		string input = "";
		getline(cin, input);

		for (int i = 0; i < input.length(); i++) {
			if (isalpha(input[i])) {
				validInput += input[i];
			}
		}

		if (validInput.length() <= 0)
			cout << "Error: The string must be comprised of letters, the input had none." << endl;
		else valid = true;
	}
	return validInput;
}
void utils::promptNoInput(const vector<string> prompts) { //Output list, takes no input
	for (int i = 0; i < prompts.size(); i++) {
		cout << prompts[i] << endl;
	}
}
bool utils::yesOrNoPrompt(const string prompt) { //Take input in yes or not format, return true or false
	while (true) {
		string input = promptUser(prompt + " (y/n)");

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
void utils::waitForSecs(const float waitFor) { //Wait for seconds
	Sleep(waitFor * 1000);
}
void utils::slowPrint(const string rawText, const float waitForBetween, const float waitAfter) { //Loop through string, wait between printing, wait after
	for (int i = 0; i < rawText.length(); i++) {
		cout << rawText[i];
		utils::waitForSecs(waitForBetween);
	}
	utils::waitForSecs(waitAfter);
	cout << endl;
}
string utils::dialogueboxBounds(const string prompt) {
	string output = "";
	for (int i = 0; i < prompt.length(); i++) {
		output += "*";
	}
	output += "************";
	return output;
}
void utils::dialogueBox(const string prompt) { //CreateTextBox, used by bachelorettes
	float waitFor = 0.02f;
	slowPrint(dialogueboxBounds(prompt));
	slowPrint("*     " + prompt + "     *", .05f);
	slowPrint(dialogueboxBounds(prompt));
	cout << endl;
}
string utils::returnFromTxt(const string dir) { //open text file, return contents
	fstream data;
	data.open(dir, ios::in); //Open title.txt

	string line = "";
	string formatedString = "";

	while (getline(data, line)) {
		formatedString += line + "\n"; //Loop through lines, add to string with "\n"
	}
	return formatedString; //Return string
}
char utils::returnCapitalised(const char raw) { //return capital, used for players name
	return toupper(raw);
}