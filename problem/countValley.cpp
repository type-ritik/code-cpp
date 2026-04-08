#include<iostream>
#include<string>
using namespace std;

int countValley(int size, string path);

int main() {
	int size;
	string path;

	cout << "Enter the size of path: ";
	cin >> size;

	cout << "Enter the path in (U || D): ";
	cin >> path;

	cout << endl;
	cout << countValley(size, path) << endl;
	return 0;
}

int countValley(int size, string path) {
	int numbersOfValley = 0;
	bool current = true;
	int level = 0;

	for (int i = 0; i < size; i++) {
		if (path[i] == 'U') {
			level = level + 1;
		}
		if (path[i] == 'D') {
			level = level - 1;
		}

		if (level < 0 && current) {
			numbersOfValley = numbersOfValley + 1;
			current = false;
		}

		if (level >= 0) {
			current = true;
		}
	}

	return numbersOfValley;
}
