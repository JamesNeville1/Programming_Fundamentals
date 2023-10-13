#include <iostream>

using namespace std;

int userInput() {
    int userGuess = 0;
    cout << "Enter a guess: ";
    cin >> userGuess;
    return userGuess;
}

void numGuesser() {
    srand((unsigned)time(NULL)); //Generate random number between 0 - 100
    int randNum = 50;

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