#include <iostream>
#include <stack>
using namespace std;

bool validParenthesis(string str)
{

    if (str.length() % 2 != 0)
    {
        return false;
    }

    if (str.length() == 0)
    {
        return true;
    }

    if (str.length() == 2)
    {
        if ((str[0] == '[' && str[1] == ']') || (str[0] == '(' && str[1] == ')') || (str[0] == '{' && str[1] == '}'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (str[0] == ']' || str[0] == '}' || str[0] == ')')
    {
        return false;
    }

    stack<char> stack;

    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case '[':
        case '(':
        case '{':
            stack.push(str[i]);
            break;
        case '}':
            if (stack.empty() || stack.top() != '{')
            {
                return false;
            }
            stack.pop();
            break;
        case ']':
            if (stack.empty() || stack.top() != '[')
            {
                return false;
            }
            stack.pop();
            break;
        case ')':
            if (stack.empty() || stack.top() != '(')
            {
                return false;
            }
            stack.pop();
            break;

        default:
            break;
        }
    }

    if (!stack.empty())
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main(void)
{
    string str = "[][]{}{}";

    if (validParenthesis(str))
    {
        cout << "Valid Parenthesis\n";
    }
    else
    {
        cout << "Invalid Parenthesis\n";
    }
    return 0;
}
