#pragma once
#include <vector>
#include <array>

using namespace std;

class utils {
	public:
	static int validateInt(string raw) {
		bool valid = false;
		string rawValidated = "";

		for (int i = 0; i < raw.length(); i++) {
			if (isdigit(raw[i])) rawValidated += raw[i];
		}

		if (rawValidated != "") return stoi(rawValidated);
		else return -1;
	}
	static int promptUserOptions(vector<string> prompts) {
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
	static string promptUserOptions(string prompt) {
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
	static void promptNoInput(vector<string> prompts) {
		for (int i = 0; i < prompts.size(); i++) {
			cout << prompts[i] << endl;
		}
	}
	static bool yesOrNoPrompt() {
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
	static void slowPrint(string rawText, float waitFor) {
		for (int i = 0; i < rawText.length(); i++) {
			cout << rawText[i];
			Sleep(waitFor * 1000);
		}
		cout << endl;
	}
	static void slowPrint(string rawText) {
		float waitFor = 0.01f;
		for (int i = 0; i < rawText.length(); i++) {
			cout << rawText[i];
			Sleep(waitFor * 1000);
		}
		cout << endl;
	}
	static string dialogueboxBounds(string prompt) {
		string output = "";
		for (int i = 0; i < prompt.length(); i++) {
			output += "*";
		}
		output += "************";
		return output;
	}
	static void dialogueBox(string prompt, int colour) {
		float waitFor = 0.02f;
		slowPrint(dialogueboxBounds(prompt));
		//cout << dialogueboxSpace(prompt) << endl;
		slowPrint("*     " + prompt + "     *", waitFor);
		//cout << dialogueboxSpace(prompt) << endl;
		slowPrint(dialogueboxBounds(prompt));
		cout << endl;
	}
};