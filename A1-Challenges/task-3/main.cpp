#include <iostream>
#include <math.h> 
using namespace std;

int numberSquarer(float num = 0.0f) { //Takes number in and returns squared (default parameters 0)
    num = pow(num,2);
    return num;
}

int main() {
    float num = 0.0f;
    cout << "Hello user, input number to be squared: ";
    cin >> num;
    cout << num << " squared is: " << numberSquarer(num);
}