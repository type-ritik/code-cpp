#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

struct Node *head;

void insertAtHead(int);

void insertAtTail(int);

void insertAtPosition(int, int);

void traverse();

Node *createNode(int);

void reverseTraverse(Node *);

void reverseRecursiveTraverse(Node *);

void deleteAtHead();

void deleteAtTail();

int main(void)
{
    head = NULL;
    insertAtHead(5);
    insertAtHead(10);
    insertAtHead(15);
    traverse();
    insertAtTail(20);
    insertAtTail(25);
    insertAtTail(30);
    traverse();
    insertAtPosition(8, 1111);
    traverse();
    printf("Reverse Recursive traverse\n");
    reverseRecursiveTraverse(head);
    printf("Reverse Traverse\n");
    reverseTraverse(head);
    return 0;
}

Node *createNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->data = data;

    return node;
}

void insertAtHead(int data)
{
    Node *node = createNode(data);
    if (head == NULL)
    {
        head = node;
        return;
    }

    head->prev = node;
    node->next = head;
    head = node;
    return;
}

void insertAtTail(int data)
{
    Node *node = createNode(data);

    if (head == NULL)
    {
        head = node;
        return;
    }

    if (head->next == NULL)
    {
        node->prev = head;
        head->next = node;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    node->prev = temp;
    temp->next = node;
    return;
}

void traverse()
{
    if (head == NULL)
    {
        printf("List is NULL\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("%d->NULL\n", head->data);
    }

    for (Node *temp = head; temp != NULL; temp = temp->next)
    {
        printf("%d->", temp->data);
    }
    printf("NULL\n");
}

void reverseRecursiveTraverse(Node *temp)
{
    if (temp == NULL)
    {
        printf("NULL");
        return;
    }
    reverseRecursiveTraverse(temp->next);
    printf("<-%d", temp->data);

    if (temp->prev == NULL)
    {
        printf("->NULL\n");
    }
}

void reverseTraverse(Node *head)
{
    if (head == NULL)
    {
        printf("List is NULL\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("NULL<-%d->NULL\n", head->data);
        return;
    }

    while (head->next != NULL)
    {
        head = head->next;
    }

    printf("NULL<-");
    while (head->prev != NULL)
    {
        printf("%d<-", head->data);
        head = head->prev;
    }

    printf("%d<-NULL\n", head->data);
    return;
}

void insertAtPosition(int position, int data)
{
    if (head == NULL)
    {
        printf("List is NULL, can't insert at position {%d}\n", position);
        return;
    }

    if (position < 1)
    {
        printf("Invalid position {%d}\n", position);
        return;
    }

    if (head->next == NULL && position != 1)
    {
        printf("List length is small, can't insert at position {%d}\n", position);
        return;
    }

    if (head->next == NULL && position == 1)
    {
        insertAtHead(data);
        return;
    }

    Node *node = createNode(data);
    int count = 0;
    Node *temp = head;

    while ((temp->next != NULL) && (count != position - 1))
    {
        temp = temp->next;
        count = count + 1;
    }

    if (count == position - 1)
    {
        temp->prev->next = node;
        node->next = temp;
        temp->prev = node;
        return;
    }

    if (count + 1 == position - 1)
    {
        temp->next = node;
        node->prev = temp;
        return;
    }

    if (count < position - 1)
    {
        printf("List length is small, can't insert at position {%d}\n", position);
        return;
    }
}

void deleteAtHead()
{
    if (head == NULL)
    {
        printf("List is NULL, can't delete at head\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return;
}

void deleteAtTail()
{
    if (head == NULL)
    {
        printf("List is NULL, can't delete at tail\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return;
}
