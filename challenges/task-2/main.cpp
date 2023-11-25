#include <iostream>
#include <string>

using namespace std;

class user { //The user class, holding all data
private: //All relevant data, secured using "private"
    string name = "";
    string clanTag = "";
    string username = "";
    int age = 0;
public: 
    user() { //Constructor here, takes input from user and sets data
        cout << "Please enter your name: ";
        cin >> this->name;
        cout << "Please enter your clan tag: ";
        cin >> this->clanTag;
        cout << "Please enter your username: ";
        cin >> this->username;
        cout << "Please enter your age: ";
        cin >> this->age;
    }
    void printUser() { //Print user data;
        cout << "\nPlayer details:\n";
        cout << "Name: " << this->name << "\n";
        cout << "Username: [" << this->clanTag << "]" << this->username << "\n";
        cout << "Age: " << this->age << "\n";
    }
};

int main() {
    user currentUser = user(); //Define User
    currentUser.printUser(); //Output user data
}
