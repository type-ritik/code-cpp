#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
using namespace std;

int migratoryBirds(vector<int> arr);

int main()
{

    vector<int> birds = {1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4};

    cout << migratoryBirds(birds) << endl;

    return 0;
}

int migratoryBirds(vector<int> arr)
{
    unordered_map<int, int> maps;
    vector<int> most_repeated_birds;
    int heighestPair = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (maps.find(arr[i]) == maps.end())
        {
            maps[arr[i]] = 1;
        }
        else
        {
            maps[arr[i]] = maps[arr[i]] + 1;

            if (maps[arr[i]] > heighestPair)
            {
                heighestPair = maps[arr[i]];
            }
        }
    }

    for (const auto &pairs : maps)
    {
        if (pairs.second == heighestPair)
        {
            cout << pairs.first << " " << pairs.second << endl;
            most_repeated_birds.push_back(pairs.first);
        }
    }

    int first_bird = INT_MAX;

    if (most_repeated_birds.size() == 1)
    {
        return most_repeated_birds[0];
    }

    for (int i = 0; i < most_repeated_birds.size(); i++)
    {
        if (most_repeated_birds[i] < first_bird)
        {
            first_bird = most_repeated_birds[i];
        }
    }

    return first_bird;
}
