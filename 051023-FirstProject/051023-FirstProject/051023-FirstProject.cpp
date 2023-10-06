#include <iostream>
using namespace std;
void simpleChallenges() {
    //43 percent of 18
    //cout <<  .43 * 18 << "\n";

    //Convert degrees to radians
    //cout << "65 degrees = " << 65 * (atan(1)*4/180) << " radians";

    //Changing what a variable is worth
    //float playerSpeed = 1;
    //playerSpeed = 2;
    //cout << "playerSpeed = " << playerSpeed;

    //Calculating the area from width and height
    //float width = 5;
    //float height = 2.5;
    //cout << "area = " << width * height;
}

void userInput() {
    int age = 0;
    cout << "Please enter your age: ";
    cin >> age;
    cout << "You are " << age << " years old";
}

int taxCalculator() {
    float income;
    cout << "What is your annual income\n";
    cin >> income;
    income /= 12;
    income *= .80;
    return income;
}

int main() {
    cout << "Hello World!\n";

    //simpleChallenges();
    //userInput();
    cout << taxCalculator();
}
