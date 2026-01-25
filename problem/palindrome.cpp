#include <iostream>
#include <cctype>
using namespace std;

bool isPalindrome(string str);

int main()
{
    string str = "A man, a plan          , a c404canal: Panama";
    if (isPalindrome(str))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }
    return 0;
}

bool isPalindrome(string str)
{
    if (str.length() == 0 || str.length() == 1)
    {
        return true;
    }

    int left = 0;
    int right = str.length() - 1;

    while (left <= right)
    {
        char lowerLeft = tolower(str[left]);
        char lowerRight = tolower(str[right]);

        if (lowerLeft == ' ' || !((int)lowerLeft >= 48 && (int)lowerLeft <= 57 || (int)lowerLeft >= 97 && (int)lowerLeft <= 122))
        {
            left++;
            continue;
        }
        if (lowerRight == ' ' || !((int)lowerRight >= 48 && (int)lowerRight <= 57 || (int)lowerRight >= 97 && (int)lowerRight <= 122))
        {
            right--;
            continue;
        }
        if (lowerLeft != lowerRight)
        {
            return false;
        }
        else
        {
            left++;
            right--;
        }
    }

    return true;
}
