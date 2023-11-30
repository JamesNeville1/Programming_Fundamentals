#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <array>
#include <map>
#include <fstream>

using namespace std;

//This is my utils header, it holds a lot of utilities used in many functions across the game

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
	static int promptUserOptions(vector<string> prompts, bool isDialogue) {
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
	static bool yesOrNoPrompt(string prompt = "Confirm:") {
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
	static void waitForSecs(float waitFor = 1) {
		Sleep(waitFor * 1000);
	}
	static void slowPrint(string rawText, float waitForBetween = .001f, float waitAfter = 0) {
		for (int i = 0; i < rawText.length(); i++) {
			cout << rawText[i];
			utils::waitForSecs(waitForBetween);
		}
		utils::waitForSecs(waitAfter);
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
	static void dialogueBox(string prompt) {
		float waitFor = 0.02f;
		slowPrint(dialogueboxBounds(prompt));
		slowPrint("*     " + prompt + "     *", .05f);
		slowPrint(dialogueboxBounds(prompt));
		cout << endl;
	}
	static string returnFromTxt(string dir) {
		fstream data;
		data.open(dir, ios::in); //Open title.txt

		string line = "";
		string formatedString = "";
		
		while (getline(data, line)) {
			formatedString += line + "\n"; //Loop through lines, add to string with "\n"
		}
		return formatedString; //Return string
	}
	static char returnCapitalised(char raw) {
		return toupper(raw);
	}
};

//Note for marker: I typically like to return variables when I can rather than using voids and printing directly.
//It gives more options for manipulating the data without having to change that function