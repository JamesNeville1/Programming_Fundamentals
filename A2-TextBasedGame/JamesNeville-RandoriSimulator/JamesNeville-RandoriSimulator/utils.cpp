#include "utils.h"
int utils::validateInt(string raw) {
	bool valid = false;
	string rawValidated = "";

	for (int i = 0; i < raw.length(); i++) {
		if (isdigit(raw[i])) rawValidated += raw[i];
	}

	if (rawValidated != "") return stoi(rawValidated);
	else return -1;
}
int utils::promptUserOptions(vector<string> prompts, bool isDialogue) {
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
		else cout << "Error: Please ensure you input is valid" << endl;
	}
	return validInt;
}
string utils::promptUserOptions(string prompt) {
	while (true) {
		cout << prompt << " ";

		string input = "";
		getline(cin, input);

		string validInput = "";
		for (int i = 0; i < input.length(); i++) {
			if (isalpha(input[i])) {
				validInput += input[i];
			}
		}

		if (validInput.length() <= 0)
			cout << "Error: The string must be comprised of letters, the input had none." << endl;
		else return validInput;
	}
}
void utils::promptNoInput(vector<string> prompts) {
	for (int i = 0; i < prompts.size(); i++) {
		cout << prompts[i] << endl;
	}
}
bool utils::yesOrNoPrompt(string prompt) {
	//bool confirmed = false;
	while (true) { //check if bad?
		cout << endl;
		string input = promptUserOptions(prompt + " (y/n)");

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
void utils::waitForSecs(float waitFor) {
	Sleep(waitFor * 1000);
}
void utils::slowPrint(string rawText, float waitForBetween, float waitAfter) {
	for (int i = 0; i < rawText.length(); i++) {
		cout << rawText[i];
		utils::waitForSecs(waitForBetween);
	}
	utils::waitForSecs(waitAfter);
	cout << endl;
}
string utils::dialogueboxBounds(string prompt) {
	string output = "";
	for (int i = 0; i < prompt.length(); i++) {
		output += "*";
	}
	output += "************";
	return output;
}
void utils::dialogueBox(string prompt) {
	float waitFor = 0.02f;
	slowPrint(dialogueboxBounds(prompt));
	slowPrint("*     " + prompt + "     *", .05f);
	slowPrint(dialogueboxBounds(prompt));
	cout << endl;
}
string utils::returnFromTxt(string dir) {
	fstream data;
	data.open(dir, ios::in); //Open title.txt

	string line = "";
	string formatedString = "";

	while (getline(data, line)) {
		formatedString += line + "\n"; //Loop through lines, add to string with "\n"
	}
	return formatedString; //Return string
}
char utils::returnCapitalised(char raw) {
	return toupper(raw);
}