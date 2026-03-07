#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
} BstNode;

// void Insert(int data);
BstNode *InsertRecusive(BstNode *root, int data);
BstNode *GetNewNode(int data);
bool Search(BstNode *root, int data);
int FindMax(BstNode *root);
int FindMin(BstNode *root);

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
