#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getMoneySpent(vector<int>, vector<int>, int);

int main() {
	vector<int> keyboards = {40, 50, 60};
	vector<int> drives = {5, 8, 12};

	cout << getMoneySpent(keyboards, drives, 60) << endl;
	
	return 0;
}

int getMoneySpent(vector<int> keyboards, vector<int> drives, int budget) {
	sort(keyboards.begin(), keyboards.end());
	sort(drives.begin(), drives.end());
	int slow = 0;
	int fast = 0;

	for (int i = 0; i < keyboards.size(); i++){
		if (keyboards[i] >= budget) {
			break;
		}
		for (int j = 0; j < drives.size(); j++) {
			fast = keyboards[i] + drives[j];

			if (fast <= budget && fast > slow) {
				slow = fast;
			}
		}
	}

	if (slow == 0 || slow > budget) {
		return -1;
	}

	return slow;
}
