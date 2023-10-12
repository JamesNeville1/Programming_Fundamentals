#include <iostream>
#include <string>

using namespace std;

void inputs() {
    string name;
    string clanTag;
    string username;
    int age;

    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your clan tag: ";
    cin >> clanTag;
    cout << "Please enter your username: ";
    cin >> username;
    cout << "Please enter your age: ";
    cin >> age;

    cout << "\nPlayer details:\n";
    cout << "Name: " << name << "\n";
    cout << "Username: [" << clanTag << "]" << username << "\n";
    cout << "Age: " << age << "\n";
}

int main() {
    inputs();
}
