#include <iostream>
#include <vector>
using namespace std;

void countAppleAndOrange(int s, int t, int a, int b, vector<int> apples, vector<int> oranges);

int main()
{
	vector<int> apple = {-2, 2, 1};
	vector<int> orange = {5, -6};
	countAppleAndOrange(7, 11, 5, 15, apple, orange);
	return 0;
}

void countAppleAndOrange(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
{
	vector<int> appleDistance;
	vector<int> orangeDistance;
	int appleCount = 0;
	int orangeCount = 0;

	// Measure apple distance which are felled from apple tree
	for (int i = 0; i < apples.size(); i++)
	{
		appleDistance.push_back(a + apples[i]);
	}

	// Measure orange distance which are felled from orange tree
	for (int i = 0; i < oranges.size(); i++)
	{
		orangeDistance.push_back(b + oranges[i]);
	}

	// Count apple which are felled on sam's yard
	for (int i = 0; i < appleDistance.size(); i++)
	{
		if (appleDistance[i] >= s && appleDistance[i] <= t)
		{
			appleCount++;
		}
	}

	// Count orange which are felled on sam's yard
	for (int i = 0; i < orangeDistance.size(); i++)
	{
		if (orangeDistance[i] <= t && orangeDistance[i] >= s)
		{
			orangeCount++;
		}
	}

	// Total Apples felled on sam's yard
	cout << appleCount << endl;

	// Total Oranges felled on sam's yard
	cout << orangeCount << endl;
}
