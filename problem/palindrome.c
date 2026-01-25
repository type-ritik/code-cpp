#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char *);

int main()
{
    char *str = " ";
    if (isPalindrome(str))
    {
        printf("The string is a palindrome.\n");
    }
    else
    {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}

bool isPalindrome(char *str)
{
    int len = strlen(str);
    if (len == 0 || len == 1)
    {
        return true;
    }

    int left = 0;
    int right = len - 1;

    while (left <= right)
    {
        char leftLower = (char)tolower(str[left]);
        char rightLower = (char)tolower(str[right]);

        if (leftLower == ' ' || !(((int)leftLower >= 48 && (int)leftLower <= 57) || ((int)leftLower >= 97 && (int)leftLower <= 122)))
        {
            left++;
            continue;
        }
        if (rightLower == ' ' || !(((int)rightLower >= 48 && (int)rightLower <= 57) || ((int)rightLower >= 97 && (int)rightLower <= 122)))
        {
            right--;
            continue;
        }
        if ((int)leftLower != (int)rightLower)
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
