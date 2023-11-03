#include <iostream>

using namespace std;

void numberSquarer() {
    float num;
    cout << "What number do you want to Square? ";
    cin >> num;
    cout << num << " squared is " << num * num;
}

int main() {
    numberSquarer();
}