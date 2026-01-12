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

// Insert at position
void insert_at(int, int);

// Delete at position
void delete_at(int);

// Delete item
void delete_data();

// Traverse in list
void traverse();

int main()
{

    head = NULL;
    // insert_at(1, 1);
    // insert_at(2, 2);
    // // add(1);
    // // add(2);
    // add(3);
    // // add(4);
    // add(5);
    // add(6);
    // add(7);
    // add(8);
    // add(9);

    // traverse();
    // printf("Insertion at 4 index\n");
    // insert_at(4, 4);
    // traverse();
    // insert_at(5, -5);

    delete_at(1);
    insert_at(1, 1);
    traverse();
    delete_at(1);
    insert_at(1, 1);
    traverse();
    delete_at(2);
    delete_at(1);
    for (int i = 1; i < 11; i++)
    {
        if (i == 9)
        {
            insert_at(20, 9);
        }
        add(i);
    }

    traverse();
    printf("Deletion at 9 index\n");
    delete_at(9);
    traverse();
    delete_at(20);
    delete_at(1);
    traverse();
    add(25);
    add(26);
    traverse();

    printf("Deletion data based\n");
    delete_data(5);
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
        printf("%d->", temp->data);
    }
    printf("NULL\n");
}

void insert_at(int item, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position {%d}\n", pos);
        return;
    }

    if (head == NULL && pos != 1)
    {
        printf("List is NULL, can't insert at position {%d}\n", pos);
        return;
    }

    Node *node = (Node *)malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;

    int count = 0;
    Node *curr = head;

    if (pos == 1)
    {
        node->next = head;
        head = node;
        return;
    }

    while ((curr->next != NULL) && (count != pos - 2))
    {
        curr = curr->next;
        count++;
    }

    if (count != pos - 2)
    {
        printf("List length is small compared to {%d}\n", pos);
        return;
    }

    node->next = curr->next;
    curr->next = node;
}

void delete_at(int pos)
{
    if (pos < 1)
    {
        printf("Invalid position {%d}\n", pos);
        return;
    }

    if ((head == NULL) || (head->next == NULL && pos != 1))
    {
        printf("List is NULL, can't delete at position {%d}\n", pos);
        return;
    }

    if (head->next == NULL && pos == 1)
    {
        free(head);
        head = NULL;
        return;
    }

    int count = 0;
    Node *current = head;
    Node *previous = NULL;

    if (pos == 1)
    {
        head = current->next;
        current->next = NULL;
        free(current);
        free(previous);
        return;
    }

    while (current->next != NULL && count != pos - 1)
    {
        if (count == pos - 2)
        {
            previous = current;
        }

        current = current->next;
        count = count + 1;
    }

    if (count != pos - 1)
    {
        printf("List lenght is small\n");
        return;
    }

    previous->next = current->next;
    current->next = NULL;
    free(current);
}

void delete_data(int data)
{
    if (head == NULL)
    {
        printf("List is NULL");
        return;
    }

    if (head->data != data && head->next == NULL)
    {
        printf("Data {%d} not found in list\n", data);
        return;
    }

    Node *curr = head;
    Node *prev = NULL;

    while (curr->next != NULL && curr->data != data)
    {
        if (curr->next->data == data)
        {
            prev = curr;
        }
        curr = curr->next;
    }

    printf("Previous%d\n", prev->data);
    printf("Current%d\n", curr->data);

    if (curr->data != data)
    {
        printf("Data {%d} not found in list\n", data);
        return;
    }

    prev->next = curr->next;
    curr->next = NULL;
    free(curr);
}
