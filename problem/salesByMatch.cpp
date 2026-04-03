#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sockMerchant(int n, vector<int> ar);

int main() {
	int n = 9;
	vector<int> ar = {10, 20, 20, 30, 10, 30, 50, 10, 20};

	cout << sockMerchant(n, ar) << endl;

	return 0;
}

int sockMerchant(int n, vector<int> ar) {
	int count = 0;
	int slow = 0;
	int fast = 1;
	int super_fast = 2;

	sort(ar.begin(), ar.end());

	while (slow < n) {
		if (slow >= n) {
			break;
		} else if (fast >= n) {
			break;
		}

		if (ar[slow] == ar[fast]) {
			count = count + 1;
			slow = super_fast;
			fast = super_fast + 1;
			super_fast = super_fast + 2;
		} else if (ar[fast] == ar[super_fast]) {
			count = count + 1;
			slow = super_fast + 1;
			fast = super_fast + 2;
			super_fast = super_fast + 3;
		} else {
			slow = super_fast;
			fast = super_fast + 1;
			super_fast = super_fast + 2;
		}
	}

	return count;
}
