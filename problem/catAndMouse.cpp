#include<iostream>
#include<string>
using namespace std;

string catAndMouse(int, int, int);

int main() {

	cout << catAndMouse(1, 3, 2) << endl;
	cout << catAndMouse(1, 2, 3) << endl;
	cout << catAndMouse(2, 5, 3) << endl;

	return 0;
}

string catAndMouse(int catA, int catB, int mouseC) {
	int distOfCatA = abs(mouseC - catA);
	int distOfCatB = abs(mouseC - catB);

	if (distOfCatA > distOfCatB) {
		return "Cat B";
	} else if (distOfCatA < distOfCatB) {
		return "Cat A";
	} else {
		return "Mouse C";
	}
}
