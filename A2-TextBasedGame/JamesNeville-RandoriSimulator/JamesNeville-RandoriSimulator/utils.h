#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <windows.h>
#include <fstream>

using namespace std;

class utils{
public:
	static int validateInt(string raw);
	static int promptUserOptions(vector<string> prompts, bool isDialogue);
	static string promptUserOptions(string prompt);
	static void promptNoInput(vector<string> prompts);
	static bool yesOrNoPrompt(string prompt = "Confirm:");
	static void waitForSecs(float waitFor = 1);
	static void slowPrint(string rawText, float waitForBetween = .001f, float waitAfter = 0);
	static string dialogueboxBounds(string prompt);
	static void dialogueBox(string prompt);
	static string returnFromTxt(string dir);
	static char returnCapitalised(char raw);
};

