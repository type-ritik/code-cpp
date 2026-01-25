#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
} Node;

Node *top = NULL;

void push(int data);

int pop();

Node *createNode(int data);

int empty();

int peek();

void traverse();

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    traverse();
    printf("Top element is %d\n", peek());
    printf("%d popped\n", pop());
    traverse();
    printf("Top element is %d\n", peek());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    printf("%d popped\n", pop());
    if (empty())
    {
        printf("Stack is empty now\n");
    }
    else
    {
        printf("Stack is not empty now\n");
    }
    printf("%d popped\n", pop());
    return 0;
}

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->prev = NULL;
    node->data = data;
    return node;
}

void push(int data)
{
    Node *node = createNode(data);

    if (top == NULL)
    {
        top = node;
        return;
    }

    node->prev = top;
    top = node;
    return;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow!");
        return -1;
    }

    int data = top->data;
    Node *temp = top;
    top = top->prev;
    free(temp);
    return data;
}

int empty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int peek()
{
    if (top == NULL)
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        return top->data;
    }
}

void traverse()
{
    Node *temp = top;
    if (top == NULL)
    {
        printf("Stack is empty");
        return;
    }

    while (temp->prev != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("%d -> NULL\n", temp->data);
}
