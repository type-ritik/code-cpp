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

int main(void)
{
    string expression = "34+5*";
    cout << "Postfix Expression: " << expression << endl;
    // cout << '5' - '0' << endl;
    cout << "Evaluated Result: " << evaluatePostfix(expression) << endl;
    return 0;
}
