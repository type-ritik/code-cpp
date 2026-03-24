#include<iostream>
#include<vector>
using namespace std;

vector<int> gradingStudents(vector<int> grades);

int main() {
	vector<int> grades = {73, 67, 38, 33};

	vector<int> result = gradingStudents(grades);

	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}

vector<int> gradingStudents(vector<int> grades){
	vector<int> upgrades;

	for (int i = 0; i < grades.size(); i++){
		if (grades[i] < 38) {
			upgrades.push_back(grades[i]);
		}else {
			int rem = grades[i] % 5;
			if (rem > 2){
				upgrades.push_back(grades[i] + (5 - rem));
			}else {
				upgrades.push_back(grades[i]);
			}
		}
	}

	return upgrades;
}


