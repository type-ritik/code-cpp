#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 101
int stack[MAX_SIZE];
int top = -1;

void push(int);

void pop();

int is_empty();

int top_is();

int main()
{
    push(10);
    push(12);
    push(13);
    printf("Top element is %d\n", top_is());
    pop();
    printf("Top element is %d\n", top_is());
    pop();
    printf("Top element is %d\n", top_is());
    pop();
    if (is_empty())
    {
        printf("Stack is empty now\n");
    }
    else
    {
        printf("Stack is not empty now\n");
    }
    pop();
    return 0;
}

void push(int data)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow!");
        return;
    }
    stack[++top] = data;
    return;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow!");
        return;
    }

    top--;
    return;
}

int is_empty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int top_is()
{
    if (top == -1)
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        return stack[top];
    }
}
