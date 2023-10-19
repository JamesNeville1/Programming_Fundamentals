#include <iostream>
#include "main.h"

using namespace std;

int userInput() {
    string userGuess = "";
    string validatedGuess = "";
    cout << "Enter a guess: ";
    cin >> userGuess;
    bool validated;
    while (validated) {
        for (size_t i = 0; i < userGuess.length(); i++) {
            if (isalpha(userGuess[i]) == 0) {
                validatedGuess += userGuess[i];
            }
        }
        if (validatedGuess == "") {
            cout << "That is an invalid input, please input numbers, guess again \n ";
            cin >> userGuess;
        }
    }
    return stoi(validatedGuess);
}

void numGuesser() {
    srand((unsigned)time(NULL)); //Generate random number between 0 - 100
    int randNum = rand() % 101;

    int userGuess = userInput();

    while (userGuess != randNum) {
        int dif = abs(userGuess - randNum);

        if (dif <= 2) cout << "boiling \n";
        else if (dif <= 5) cout << "hot \n";
        else if (dif <= 10) cout << "warmer \n";
        else if (dif <= 15) cout << "warm \n";
        else if (dif <= 25) cout << "cold \n";
        else if (dif <= 35) cout << "colder \n";
        else if (dif <= 50) cout << "freezing \n";
        
        userGuess = userInput();
    }
    cout << "You got it! The number is " << randNum;
}

int main() {
    numGuesser();
}