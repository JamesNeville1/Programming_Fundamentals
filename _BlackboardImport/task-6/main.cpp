#include <iostream>
#include "main.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int userInput() {
    char gay[] = "2";
    //if (isdigit(gay[0])) cout << "aaaaaaaa";
    string userGuess = "";
    string validatedGuess = "";
    
    cout << "Enter a guess: ";
    getline(cin, userGuess);
    bool validated = false;
    while (!validated) {
        for (int i = 0; i < userGuess.length(); i++) {
            if (isdigit(userGuess[i])) {
                //cout << "true";
                validatedGuess += userGuess[i];
                validated = true;
            }
        }
        if (!validated || validatedGuess.length() > 3) {
            cout << "That is an invalid input, please input numbers, guess again: ";
            getline(cin, userGuess);
        }
    }
    return stoi(validatedGuess);
}

void numGuesser() {
    srand((unsigned)time(NULL)); //Generate random number between 0 - 100
    int randNum = rand() % 101;
    int tries = 0;

    int userGuess = userInput();

    cout << randNum;

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
    cout << "You got it! The number is " << randNum << ", you got it in " << tries << " tries";
}

int main() {
    numGuesser();
}