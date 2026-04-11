#include<iostream>
#include<vector>
using namespace std;

vector<int> leftRotate(int , vector<int>);

int main() {

	vector<int> nums0 = {1, 2, 3, 4, 5};
	
	vector<int> result = leftRotate(2, nums0);

	for (int i = 0; i < result.size(); i++) {
		cout <<" " << result[i];
	}

	cout << endl;

	return 0;
}

vector<int> leftRotate(int d, vector<int> arr) {
	vector<int> temp;

	if (arr.size() == d) {
		return arr;
	}

	for (int i = d; i < arr.size(); i++) {
		temp.push_back(arr[i]);
	}

	for (int i = 0; i < d; i++){
		temp.push_back(arr[i]);
	}

	return temp;
}
