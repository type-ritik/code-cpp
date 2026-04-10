#include<iostream>
#include<vector>
using namespace std;

int formingMagicSquare(vector<vector<int>> );

int main() {
	vector<vector<int>> input0 = {
		{4, 9, 2},
		{3, 5, 7},
		{8, 1, 5}
	};

	vector<vector<int>> input1 = {
		{5, 3, 4},
		{1, 5, 8},
		{6, 4, 2}
	};

	vector<vector<int>> input2 = {
		{4, 8, 2},
		{4, 5, 7},
		{6, 1, 6}
	};

	cout << formingMagicSquare(input0) << endl;
	cout << formingMagicSquare(input1) << endl;
	cout << formingMagicSquare(input2) << endl;

	return 0;
}

int formingMagicSquare(vector<vector<int>> sqr) {
	 vector<vector<int>> squares = {
        	{8, 1, 6, 3, 5, 7, 4, 9, 2},
        	{6, 1, 8, 7, 5, 3, 2, 9, 4},
        	{2, 7, 6, 9, 5, 1, 4, 3, 8},
        	{4, 3, 8, 9, 5, 1, 2, 7, 6},
        	{2, 9, 4, 7, 5, 3, 6, 1, 8},
        	{4, 9, 2, 3, 5, 7, 8, 1, 6},
        	{8, 3, 4, 1, 5, 9, 6, 7, 2},
        	{6, 7, 2, 1, 5, 9, 8, 3, 4}
    	};

	 int min = 99999;

	 for(int i = 0; i < squares.size(); i++) {
		 int total = 0;

		 for (int j = 0; j < squares[i].size(); j++) {
			 total += abs(sqr[j/3][j%3] - squares[i][j]);
		 }

		 if (total < min) {
		 	min = total;
		 }
	 }

	 return min;
}
