#include <iostream>
#include <string>

using namespace std;

string boxBoundIteration(const string userInput) { //Return box bounds, using "const" as userInput doesnt change 
    string output = "";
    for (int i = 0; i < userInput.length(); i++) { //Loop through input to work out the bounds
        output += "*";
    }
    output += "****"; //Add 4 for padding
    return output;
}

void makeBox(string userInput) {
    cout << boxBoundIteration(userInput);
    cout << "\n" << "* " << userInput << " *" << "\n";
    cout << boxBoundIteration(userInput);
}

int main() {
    string userInput = ""; 

    cout << "Please enter some text: ";
    getline(cin, userInput); //Take input

    makeBox(userInput); //Make box
}