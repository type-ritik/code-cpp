#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string expression)
{
    stack<int> post;
    for (char ch : expression)
    {
        if (isdigit(ch))
        {
            post.push(ch - '0'); // converting to integer
        }
        else
        {
            int val2 = post.top();
            post.pop();
            int val1 = post.top();
            post.pop();

            switch (ch)
            {
            case '+':
                post.push(val1 + val2);
                break;

            case '-':
                post.push(val1 - val2);
                break;

            case '*':
                post.push(val1 * val2);
                break;

            case '/':
                post.push(val1 / val2);
                break;

            default:
                break;
            }
        }
    }
    return post.top();
}

int evalPostfix(string exp)
{

    if (!isdigit(exp[0]) || !isdigit(exp[1]))
    {
        cout << "Error: Expression must start with two operands." << endl;
        return -1;
    }
    stack<char> stack;

    for (char character : exp)
    {
        if (isdigit(character))
        {
            stack.push(character - '0');
        }
        else
        {

            int val2 = stack.top();
            stack.pop();

            if (stack.empty())
            {
                cout << "Error: Insufficient operands in the expression." << endl;
                return -1;
            }

            int val1 = stack.top();
            stack.pop();

            switch (character)
            {
            case '+':
                stack.push(val1 + val2);
                break;
            case '-':
                stack.push(val1 - val2);
                break;
            case '/':
                stack.push(val1 / val2);
                break;
            case '*':
                stack.push(val1 * val2);
                break;
            default:
                break;
            }
        }
    }

    int result = stack.top();
    stack.pop();

    if (!stack.empty())
    {
        cout << "Error: Stack is not empty after evaluation." << endl;
        return -1;
    }

    return result;
}

int main(void)
{
    string expression = "23*54*+9-";
    cout << "Postfix Expression: " << expression << endl;
    // cout << '5' - '0' << endl;
    cout << "Evaluated Result: " << evalPostfix(expression) << endl;
    return 0;
}
