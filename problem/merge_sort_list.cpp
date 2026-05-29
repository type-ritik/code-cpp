#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    int data;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = tail = NULL;
    }

    void push_back(int value)
    {
        Node *new_node = new Node(value);
        if (head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void print_Node()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << " NULL" << endl;
    }
};

Node *mergeTwoList(Node *list1, Node *list2)
{

    Node *result;
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    if (list1->data <= list2->data)
    {
        result = list1;
        result->next = mergeTwoList(list1->next, list2);
    }
    else
    {
        result = list2;
        result->next = mergeTwoList(list1, list2->next);
    }

    return result;
}

Node *mergeTwoListIterativeApproach(Node *list1, Node *list2)
{
    Node *list = NULL;
    Node *head = NULL;

    if (list1 == NULL)
    {
        return list2;
    }

    if (list2 == NULL)
    {
        return list1;
    }

    int count = 0;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            if (head == NULL)
            {
                head = list1;
                list = head;
            }
            else
            {
                list->next = list1;
                list = list->next;
            }
            list1 = list1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = list2;
                list = head;
            }
            else
            {
                list->next = list2;
                list = list->next;
            }
            list2 = list2->next;
        }
    }

    if (list1 == NULL && list2 != NULL)
    {
        list->next = list2;
    }
    else
    {
        list->next = list1;
    }

    return head;
}

Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *curr = head;

    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *duplicate = curr->next;
            curr->next = curr->next->next;
            delete duplicate;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    LinkedList ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(40);

    ll.print_Node();

    LinkedList ll1;
    ll1.push_back(10);
    ll1.push_back(30);
    ll1.push_back(40);

    ll1.print_Node();
    Node *merge_node = mergeTwoListIterativeApproach(ll.head, ll1.head);

    LinkedList merge_list;
    merge_list.head = merge_node;
    merge_list.print_Node();

    LinkedList unique;
    unique.head = removeDuplicates(merge_node);
    unique.print_Node();
}
