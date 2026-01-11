#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

// Node structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// global variable, can be accessed anywhere
struct Node *head;

// Add item in list
void add(int);

// Traverse in list
void traverse();

int main()
{

    head = NULL;
    add(1);
    add(2);
    add(3);
    add(4);
    add(5);
    add(6);
    add(7);
    add(8);
    add(9);

    traverse();
    return 0;
}

void add(int item)
{

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;

    if (head == NULL)
    {
        head = node;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
}

void traverse()
{
    for (Node *temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d\n", temp->data);
    }
}
