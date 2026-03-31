#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> wafer = {2, 2, 1, 3, 2};
    int d = 4;
    int m = 2;

    int count = 0;

    for (int i = 0; i < wafer.size(); i++)
    {
        int sum = 0;
        for (int j = i; j <= m - 1 + i; j++)
        {
            sum += wafer[j];
        }

        if (sum == d)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
