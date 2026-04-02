#include<iostream>
#include<string>
using namespace std;

string dayOfProgrammer(int year);

int main() {
	cout << dayOfProgrammer(1787) << endl;
	cout << dayOfProgrammer(1918) << endl;
	cout << dayOfProgrammer(2020) << endl;

	return 0;
}

string dayOfProgrammer(int year) {
	int totalSum = 0;

	if (1917 >= year && year >= 1700) {
		if (year % 4 == 0) {
			totalSum = 244;
		} else {
			totalSum = 243;
		}
	} else if (year == 1918) {
		return "26.09." + to_string(year);
	} else {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			totalSum = 244;
		} else {
			totalSum = 243;
		}
	}

	int calculateDay = 256 - totalSum;

	return to_string(calculateDay) + ".09." + to_string(year);
}
