#include <iostream>
#include "main.h"
#include <string>

using namespace std;

//Very simple program so little comments, takes input in one function (returns float)
//Uses header to define the Vector2 struct and the GetDistanceBetweenPoints function

float processInput(string inputRaw) {
	string validFloat = "";
	bool pointAdded = false;
	for (int i = 0; i < inputRaw.length(); i++) {
		if (isdigit(inputRaw[i])) {
			validFloat += inputRaw[i];
		}
		else if (!pointAdded) {
			validFloat += inputRaw[i];
			pointAdded = true;
		}
	}
	if (validFloat != "") return stof(validFloat);
	return 0;
}

void main() {
	string inputRaw = "";
	Vector2 positions[2];
	
	for (int i = 0; i < 2; i++) {
		bool valid = false;

		cout << "Please enter the X the component of vector " << i+1 << ": ";
		getline(cin, inputRaw);
		positions[i].x = processInput(inputRaw);

		cout << "Please enter the Y the component of vector " << i+1 << ": ";
		getline(cin, inputRaw);
		positions[i].y = processInput(inputRaw);
	}

	cout << endl << "The distance between (" 
		<< positions[0].x << " , " << positions[0].y 
		<< ") and (" 
		<< positions[1].x << " , " << positions[1].y
		<< ") is "
		<< GetDistanceBetweenPoints(positions[0], positions[1]) 
		<< endl;
}