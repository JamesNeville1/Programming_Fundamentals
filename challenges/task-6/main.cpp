#include <iostream>
#include "main.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int validateInt(string raw) {
    bool valid = false;
    string rawValidated = "";

    for (int i = 0; i < raw.length(); i++) {
        if (isdigit(raw[i])) rawValidated += raw[i];
    }

    if (rawValidated != "") return stoi(rawValidated);
    else return -1;
}

int userInput() {
    string userGuess = "";   
    int validGuess = -1;

    while (validGuess < 0 || validGuess > 100) {
        cout << "Enter a guess: ";
        getline(cin, userGuess);
        validGuess = validateInt(userGuess);
    }
    
    return validGuess;
}

void numGuesser() {
    int randNum = random(0, 100);
    int tries = 0;

    int userGuess = userInput();

    while (userGuess != randNum) {
        int dif = abs(userGuess - randNum);

        if (dif <= 2) cout << "boiling \n";
        else if (dif <= 5) cout << "hot \n";
        else if (dif <= 10) cout << "warmer \n";
        else if (dif <= 15) cout << "warm \n";
        else if (dif <= 25) cout << "cold \n";
        else if (dif <= 35) cout << "colder \n";
        else cout << "freezing \n";

        userGuess = userInput();
        tries++;
    }
    cout << "You got it! The number is " << randNum << ", you got it in " << tries + 1 << " tries";
}

int main() {
    numGuesser();
}
