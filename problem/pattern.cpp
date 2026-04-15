#include<iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter number: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++){
			cout << " ";
		}
		cout << "*";

		for (int j = (i * 2) - 1; j > 0; j-- ){
			cout << " ";
		}

		if (i > 0) {
			cout << "*" << endl;
		} else {
			cout << endl;
		}
	}

	for (int i = n - 2; i >= 0; i-- ) {
		for (int j = i; j < n - 1; j++ ){
			cout << " ";
		}
		cout << "*";

		for (int j = (i * 2) - 1; j > 0; j--) {
			cout << " ";
		}
		if (i > 0) {
			cout << "*" << endl;
		} else {
			cout << endl;
		}
	}

	return 0;
}
