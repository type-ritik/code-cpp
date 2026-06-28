#include <iostream>
#include "node.cpp"
using namespace std;

template <typename T>
class Stack
{
private:
    Node<T> *top;
    size_t length;

public:
    Stack()
    {
        this->top = nullptr;
        this->length = 0;
    }

    ~Stack()
    {
        this->clear();
    }

    void push_back(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (this->isEmpty())
        {
            this->top = node;
        }
        else
        {
            node->next = this->top;
            this->top = node;
        }
        this->length++;
    }

    T peek()
    {
        return this->top->data;
    }

    size_t len()
    {
        return this->length;
    }

    bool isEmpty()
    {

        return this->length == 0;
    }

    void pop_back()
    {
        if (this->isEmpty())
        {
            throw out_of_range("Stack Underflow!");
        }
        else
        {
            Node<T> *temp = this->top;
            this->top = this->top->next;
            delete temp;
            this->length--;
        }
    }

    void clear()
    {
        if (this->isEmpty())
        {
            throw out_of_range("Stack Underflow!");
        }
        else
        {
            while (!this->isEmpty())
            {

                this->pop_back();
            }
        }
    }

    void traverse()
    {
        if (this->isEmpty())
        {
            throw out_of_range("Stack is Empty!");
        }
        else
        {
            Node<T> *current = this->top;
            while (current)
            {
                cout << current->data << endl;
                current = current->next;
            }
        }
    }
};
