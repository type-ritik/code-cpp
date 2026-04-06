#include<iostream>
#include<cmath>
using namespace std;

int rightToLeftTraverse(int, int);
int leftToRightTraverse(int, int);
int pageCount(int, int);

int main() {
	int num1, num2;

	cout << "Enter Book page: " << endl;
	cin >> num1;
	cout << "Enter Searchable page: " << endl;
	cin >> num2;
	cout << pageCount(num1, num2) << endl;
	// cout << pageCount(283293, 23232) << endl;
	return 0;
}

int pageCount(int n, int p) {
	int mid = floor(n / 2);

	if ( mid < p ) {
		return rightToLeftTraverse(p, n);
	} else {
		return leftToRightTraverse(p, 0);
	}
}

int rightToLeftTraverse(int value, int end) {
	int count = 0;
	int slow = end;
	int fast = end - 1;

	if ((end % 2 == 0) && (value == (end - 1))) {
		count = count + 1;
	}

	while ((slow > value) && (fast > value)) {
		count = count + 1;
		slow = slow - 2;
		fast = fast - 2;
	}
	
	return count;
}

int leftToRightTraverse(int value, int start) {
	int count = 0;
	int slow = start;
	int fast = start + 1;

	while ((slow < value) && (fast < value)) {
		count = count + 1;
		slow = slow + 2;
		fast = fast + 2;
	}

	return count;
}
