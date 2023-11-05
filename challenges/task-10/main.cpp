#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct elementTemp {
	string name = "";
	int pointsAvailable = 0;
};

struct assessmentTemp {
	string name = "";
	vector<elementTemp> challenges;
	vector<elementTemp> otherElements;
};

assessmentTemp assessmentOne = {
	"Assessment 1", {"1", 10}
}

void main() {

}