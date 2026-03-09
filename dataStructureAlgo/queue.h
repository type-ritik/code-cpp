#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

// Your original structure
typedef struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

typedef struct QueueNode
{
    BstNode *treeNode;
    struct QueueNode *next;
} QueueNode;

typedef struct
{
    QueueNode *front, *rear;
} Queue;

// Function Prototypes
bool isEmpty(Queue *q);
void enqueue(Queue *q, BstNode *tNode);
BstNode *dequeue(Queue *q);
BstNode *peek(Queue *q);

#endif
