#include <iostream>
#include <stack>
using namespace std;

// class Stack
// {
// private:
//     int top;
//     int capacity = 100;
//     char A[100];

// public:
//     Stack()
//     {
//         top = -1;
//     }

//     void push(char x)
//     {
//         if (this->isFull())
//         {
//             cout << "STACK OVERFLOW!";
//             exit(EXIT_FAILURE);
//         }

//         this->A[++this->top] = x;
//     }

//     char pop()
//     {
//         if (this->isEmpty())
//         {
//             cout << "STACK UNDERFLOW!";
//             exit(EXIT_FAILURE);
//         }

//         return this->A[top--];
//     }

//     int isEmpty()
//     {
//         return (this->top == -1);
//     }

//     int isFull()
//     {
//         return (this->top == this->capacity - 1);
//     }

//     char Top()
//     {
//         return this->A[this->top];
//     }
// };

void reverseString(string str)
{
    stack<char> stack;

    for (int i = 0; i < str.length(); i++)
    {
        stack.push(str[i]);
    }

    for (int i = 0; i < str.length(); i++)
    {
        str[i] = stack.top();
        stack.pop();
    }

    cout << str << endl;
    return;
}

int main(void)
{
    string text = "Hello World!";
    reverseString(text);
    return 0;
}
