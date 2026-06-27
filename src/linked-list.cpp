#include <iostream>
#include "node.cpp"
using namespace std;

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    size_t length = 0;

public:
    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void push_back(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (head == nullptr)
        {
            this->head = node;
        }
        else
        {
            this->tail->next = node;
        }
        this->tail = node;
        this->length++;
    }

    void pop_back()
    {
        if (this->head == nullptr)
        {
            throw out_of_range("Stack Underflow!");
        }

        if (this->head->next == nullptr)
        {
            free(this->head);
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            Node<T> *temp = this->head;

            while (temp->next != this->tail)
            {
                temp = temp->next;
            }
            free(this->tail);
            temp->next = nullptr;
            this->tail = temp;
        }
        this->length--;
    }

    void push_front(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (this->head == nullptr)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            node->next = this->head;
            this->head = node;
        }
        this->length++;
    }

    void pop_front()
    {
        if (this->head == nullptr)
        {
            throw out_of_range("Stack Underflow!");
        }

        if (this->head->next == nullptr)
        {
            free(this->head);
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            Node<T> *node = this->head;
            this->head = this->head->next;
            free(node);
        }
        this->length--;
    }

    void insert(size_t index, T data)
    {
        if (index > this->len())
        {
            throw out_of_range("Invalid index.");
        }

        if (index == 0)
        {
            push_front(data);
        }
        else if (index == this->len())
        {
            push_back(data);
        }
        else
        {
            Node<T> *temp = head;

            for (size_t i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            Node<T> *node = new Node<T>(data);
            node->next = temp->next;
            temp->next = node;
            this->length++;
        }
    }

    Node<T> *search(T data)
    {
        if (this->head == nullptr)
        {
            throw out_of_range("List is empty!");
        }
        else
        {
            Node<T> *temp = this->head;

            while (temp)
            {
                if (temp->data == data)
                {
                    return temp;
                }
                temp = temp->next;
            }

            return nullptr;
        }
    }

    size_t len()
    {
        return this->length;
    }

    void traverse()
    {
        Node<T> *temp = head;

        while (temp)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void remove(T data)
    {
        if (this->head == nullptr)
        {
            throw out_of_range("List is empty!");
        }

        if (this->head->next == nullptr)
        {
            if (this->head->data == data)
            {
                pop_front();
            }
            else
            {
                throw out_of_range("Data not found!");
            }
        }
        else
        {
            Node<T> *temp = this->head;

            if (temp->data == data)
            {
                pop_front();
                return;
            }

            while (temp->next)
            {
                if (temp->next->data == data)
                {
                    Node<T> *node = temp->next;
                    temp->next = temp->next->next;
                    free(node);
                    this->length--;
                    return;
                }
                temp = temp->next;
            }

            throw out_of_range("Data not found!");
        }
    }

    void removeAt(int index)
    {
        if (index >= this->len())
        {
            throw out_of_range("Invalid index.");
        }

        if (index == 0)
        {
            pop_front();
        }
        else if (index == this->len() - 1)
        {
            pop_back();
        }
        else
        {
            Node<T> *temp = head;

            for (size_t i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }
            Node<T> *node = temp->next;
            temp->next = temp->next->next;
            free(node);
            this->length--;
        }
    }
};
