#include <iostream>
#include "node.cpp"
using namespace std;

template <typename T>
class Queue
{
private:
    Node<T> *front;
    Node<T> *rear;
    size_t length;

public:
    Queue()
    {
        this->front = nullptr;
        this->rear = nullptr;
        this->length = 0;
    }

    ~Queue()
    {
        this->clear();
    }

    void enqueue(T data)
    {
        Node<T> *node = new Node<T>(data);
        if (this->isEmpty())
        {
            this->front = node;
            this->rear = node;
        }
        else
        {
            this->rear->next = node;
            this->rear = node;
        }
        this->length++;
    }

    void dequeue()
    {
        if (this->isEmpty())
        {
            throw out_of_range("Queue underflow!");
        }
        else
        {
            Node<T> *node = this->front;
            this->front = this->front->next;
            delete node;
            this->length--;
        }
    }

    size_t len()
    {
        return this->length;
    }

    bool isEmpty()
    {
        return this->length == 0;
    }

    void traverse()
    {
        if (this->isEmpty())
        {
            cout << "NULL" << endl;
        }
        else
        {
            Node<T> *current = this->front;

            while (current)
            {
                cout << current->data << "->";
                current = current->next;
            }

            cout << "NULL" << endl;
        }
    }

    T peek_front()
    {
        if (this->isEmpty())
        {
            return nullptr;
        }
        else
        {
            return this->front->data;
        }
    }

    T peek_rear()
    {
        if (this->isEmpty())
        {
            return nullptr;
        }
        else
        {
            return this->rear->data;
        }
    }

    void clear()
    {
        if (this->isEmpty())
        {
            throw out_of_range("Queue Underflow!");
        }
        else
        {
            while (!this->isEmpty())
            {
                this->dequeue();
            }
        }
    }
};
