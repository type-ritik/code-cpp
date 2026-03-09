#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Your BST Node Structure
typedef struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

// Queue Node (stores a pointer to a BST Node)
typedef struct QueueNode
{
    BstNode *treeNode;
    struct QueueNode *next;
} QueueNode;

// Queue Structure
typedef struct
{
    QueueNode *front, *rear;
} Queue;

// Check if Queue is empty
bool isEmpty(Queue *q)
{
    return (q->front == NULL);
}

// Enqueue: Add a BstNode to the end
void enqueue(Queue *q, BstNode *tNode)
{
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->treeNode = tNode;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue: Remove and return the BstNode at the front
BstNode *dequeue(Queue *q)
{
    if (isEmpty(q))
        return NULL;

    QueueNode *temp = q->front;
    BstNode *tNode = temp->treeNode;

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return tNode;
}

// Peek: View the front BstNode without removing it
BstNode *peek(Queue *q)
{
    if (isEmpty(q))
        return NULL;
    return q->front->treeNode;
}
