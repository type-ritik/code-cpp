#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

struct Node *head;

int main(void)
{
    head = NULL;
}
