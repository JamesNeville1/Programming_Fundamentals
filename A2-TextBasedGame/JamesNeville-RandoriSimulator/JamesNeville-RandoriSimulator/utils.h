#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <windows.h>
#include <fstream>

using namespace std;

class utils{
public:
	static int validateInt(const string raw);
	static int promptUser(const vector<string> prompts, const bool isDialogue);
	static string promptUser(const string prompt);
	static void promptNoInput(const vector<string> prompts);
	static bool yesOrNoPrompt(const string prompt = "Confirm:");
	static void waitForSecs(const float waitFor = 1);
	static void slowPrint(const string rawText, const float waitForBetween = .001f, const float waitAfter = 0);
	static string dialogueboxBounds(const string prompt);
	static void dialogueBox(const string prompt);
	static string returnFromTxt(const string dir);
	static char returnCapitalised(const char raw);
};

