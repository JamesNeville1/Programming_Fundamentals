#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string sentenceCaser(string userInput) {
    bool cap = false; //Instatiate the capitalisation bool
    userInput.at(0) = toupper(userInput.at(0)); //Set first letter of the string to a capital
    for (int i = 1; i < userInput.length(); i++) { //Starting at the second letter of the string, loop to the end of the sentence
        if (userInput.at(i) == '.') { //Set cap to true if the character is a "."
            cap = true;
        }
        else if (cap) { //Then, if cap is true and the character isn't a space, make the character a capital and set cap back to false
            if (userInput.at(i) != ' ') {
                userInput.at(i) = toupper(userInput.at(i));
                cap = false;
            }
        }
        else {
            userInput.at(i) = tolower(userInput.at(i)); //Make sure any other letters are lower case
        }
    }
    return userInput;
}

string lowercaser(string userInput) {
    transform(userInput.begin(), userInput.end(), userInput.begin(), tolower); //Make sentence lowercase
    return userInput;
}

string uppercaser(string userInput) {
    transform(userInput.begin(), userInput.end(), userInput.begin(), toupper); //Make setence uppercase
    return userInput;
}

int main() {
    string userInput = "";
    cout << "Please enter some text: ";
    getline(cin, userInput);

    cout << "Sentence case: " << sentenceCaser(userInput) << "\n";
    cout << "Lowercase: " << lowercaser(userInput) << "\n";
    cout << "Uppercase: " << uppercaser(userInput);
}