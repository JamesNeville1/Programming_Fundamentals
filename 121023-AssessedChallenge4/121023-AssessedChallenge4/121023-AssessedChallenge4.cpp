#include <iostream>
#include <string>

using namespace std;

string boxBoundIteration(string userInput) {
    string output = "";
    for (int i = 0; i < userInput.length(); i++) {
        output += "*";
    }
    output += "****";
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
    getline(cin, userInput);

    makeBox(userInput);
}