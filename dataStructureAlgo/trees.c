#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "queue.h"

// void Insert(int data);
BstNode *InsertRecusive(BstNode *root, int data);
BstNode *GetNewNode(int data);
bool Search(BstNode *root, int data);
int FindMax(BstNode *root);
int FindMin(BstNode *root);
int FindMaxRecursive(BstNode *root);
int FindMinRecursive(BstNode *root);
int FindSecondMin(BstNode *root);
int FindSecondMax(BstNode *root);
int FindHeight(BstNode *root);
int max(int, int);
void PreOrderTraversal(BstNode *root);
void InOrderTraversal(BstNode *root);
void PostOrderTraversal(BstNode *root);
void LevelOrderTraversal(BstNode *root);
BstNode *FindMinNode(BstNode *root);

bool IsBinarySearchTree(BstNode *root);
bool IsBstUtil(BstNode *root, int minValue, int maxValue);

BstNode *Delete(BstNode *root, int data);

BstNode *GetSuccessor(BstNode *root, int data);
BstNode *Find(BstNode *root, int data);

int main()
{
    struct BstNode *root;
    root = NULL;
    root = InsertRecusive(root, 15);
    root = InsertRecusive(root, 10);
    root = InsertRecusive(root, 20);
    root = InsertRecusive(root, 25);
    root = InsertRecusive(root, 35);
    root = InsertRecusive(root, 13);
    root = InsertRecusive(root, 23);
    root = InsertRecusive(root, 8);
    root = InsertRecusive(root, 36);
    root = InsertRecusive(root, 42);
    root = InsertRecusive(root, 3);
    root = InsertRecusive(root, 1);

    if (Search(root, 25))
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }

    printf("%d is Maximum value in Tree\n", FindMax(root));
    printf("%d is Minimum value in Tree\n", FindMin(root));
    printf("%d is Second Maximum value in Tree\n", FindSecondMax(root));
    printf("%d is Second Minimum value in Tree\n", FindSecondMin(root));
    printf("%d is Minimum value By Recursive\n", FindMinRecursive(root));
    printf("%d is Maximum value By Recursive\n", FindMaxRecursive(root));
    printf("\n");
    printf("%d is th height of Tree\n", FindHeight(root));
    printf("\nPre-Order Traversal:\n");
    PreOrderTraversal(root);
    printf("\nIn-Order Traversal:\n");
    InOrderTraversal(root);
    printf("\nPost-Order Traversal:\n");
    PostOrderTraversal(root);
    printf("\nLevel-Order Traversal:\n");
    LevelOrderTraversal(root);
    printf("\nIs Binary Tree\n");
    if (!IsBinarySearchTree(root))
    {
        printf("Not a Binary Search Tree\n");
    }
    else
    {
        printf("Is a Binary Search Tree\n");
    }

    root = Delete(root, 20);
    printf("In-Order Traversal after deleting node:\n");
    InOrderTraversal(root);

    printf("Successor of Node 15\n");
    BstNode *successor = GetSuccessor(root, 15);
    if (successor != NULL)
    {
        printf("Successor of 15 is %d\n", successor->data);
    }
    else
    {
        printf("No successor found for 15\n");
    }
    return 0;
}

BstNode *InsertRecusive(BstNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = InsertRecusive(root->left, data);
    }
    else
    {
        root->right = InsertRecusive(root->right, data);
    }
    return root;
}

BstNode *GetNewNode(int data)
{
    BstNode *newNode = (BstNode *)malloc(sizeof(BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool Search(BstNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        printf("%d\n", root->data);
        return true;
    }
    else if (data <= root->data)
    {
        printf("%d GOES LEFT\n", root->data);
        return Search(root->left, data);
    }
    else
    {
        printf("%d GOES RIGHT\n", root->data);
        return Search(root->right, data);
    }
}

int FindMax(BstNode *root)
{
    if (root == NULL)
    {
        printf("Empty tree\n");
        return -1;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    else
    {
        while (root->right != NULL)
        {
            root = root->right;
        }
        return root->data;
    }
}

int FindMin(BstNode *root)
{
    if (root == NULL)
    {
        printf("Empty Tree\n");
        return -1;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    else
    {
        while (root->left != NULL)
        {
            root = root->left;
        }
        return root->data;
    }
}

int FindSecondMin(BstNode *root)
{
    if (root == NULL)
    {
        printf("Empty Tree\n");
        return -1;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    else
    {
        BstNode *current = root;
        while (current->left->left != NULL)
        {
            current = current->left;
        }
        return current->data;
    }
}

int FindSecondMax(BstNode *root)
{
    if (root == NULL)
    {
        printf("Empty Tree\n");
        return -1;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    else
    {
        BstNode *current = root;
        while (current->right->right != NULL)
        {
            current = current->right;
        }
        return current->data;
    }
}

int FindMinRecursive(BstNode *root)
{
    if (root == NULL)
    {
        printf("Empty Tree\n");
        return -1;
    }

    if (root->left == NULL)
    {
        return root->data;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return FindMinRecursive(root->left);
    }
}

int FindMaxRecursive(BstNode *root)
{
    if (root == NULL)
    {
        printf("Empty Tree\n");
        return -1;
    }

    if (root->right == NULL)
    {
        return root->data;
    }
    else if (root->left == NULL && root->right == NULL)
    {
        return root->data;
    }
    else
    {
        return FindMaxRecursive(root->right);
    }
}

int FindHeight(BstNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    return max(FindHeight(root->left), FindHeight(root->right)) + 1;
}

int max(int left, int right)
{
    if (left > right)
    {
        return left;
    }
    else
    {
        return right;
    }
}

void PreOrderTraversal(BstNode *root)
{

    if (root == NULL)
    {
        return;
    }

    printf("%d\n", root->data);
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void InOrderTraversal(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrderTraversal(root->left);
    printf("%d\n", root->data);
    InOrderTraversal(root->right);
}

void PostOrderTraversal(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    printf("%d\n", root->data);
}

void LevelOrderTraversal(BstNode *root)
{

    if (root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }

    Queue queue = {NULL, NULL};
    enqueue(&queue, root);

    while (!isEmpty(&queue))
    {
        BstNode *current = dequeue(&queue);

        printf("%d\n", current->data);

        if (current->left)
        {
            enqueue(&queue, current->left);
        }

        if (current->right)
        {
            enqueue(&queue, current->right);
        }
    }
}

bool IsBinarySearchTree(BstNode *root)
{
    if (root == NULL)
    {
        printf("Tree is empty\n");
        return false;
    }

    return IsBstUtil(root, INT_MIN, INT_MAX);
}

bool IsBstUtil(BstNode *root, int minValue, int maxValue)
{

    if (root == NULL)
    {
        return true;
    }
    printf("Root DATA: %d - Min: %d - Max: %d\n", root->data, minValue, maxValue);

    if (root->data > minValue && root->data < maxValue && IsBstUtil(root->left, minValue, root->data) && IsBstUtil(root->right, root->data, maxValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

BstNode *FindMinNode(BstNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left)
    {
        return FindMinNode(root->left);
    }
    else
    {
        return root;
    }
}

BstNode *Delete(BstNode *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->left == NULL)
        {
            BstNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            BstNode *temp = root;
            root = root->left;
            free(temp);
        }
        else
        {
            BstNode *temp = FindMinNode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

BstNode *Find(BstNode *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data < data)
    {
        return Find(root->right, data);
    }
    else if (root->data > data)
    {
        return Find(root->left, data);
    }
    else
    {
        return root;
    }
}

BstNode *GetSuccessor(BstNode *root, int data)
{
    BstNode *current = Find(root, data);

    if (current == NULL)
    {
        return NULL;
    }

    if (current->right != NULL)
    {
        return FindMinNode(current->right);
    }
    else
    {
        BstNode *succesor = NULL;
        BstNode *ancestor = root;
        while (ancestor != current)
        {
            if (current->data < ancestor->data)
            {
                succesor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return succesor;
    }
}
