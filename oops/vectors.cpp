#include <iostream>
using namespace std;

class Vector
{
private:
    int size;
    int *vec;
    int capacity;

public:
    Vector()
    {
        size = 0;
        capacity = 1;
        vec = new int(capacity);
    }

    Vector(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;
        vec = new int(capacity);
    }

    int sizeIs()
    {
        return size;
    }

    int capacityIs()
    {
        return capacity;
    }

    bool isFull()
    {
        return this->capacityIs() == this->sizeIs();
    }

    bool isEmpty()
    {
        return this->sizeIs() == 0;
    }

    void push_back(int value)
    {
        if (this->isFull())
        {
            capacity = capacity * 2;
            int *temp = new int(capacity);
            for (int i = 0; i < size; i++)
            {
                temp[i] = vec[i];
            }
            delete[] vec;
            vec = temp;
        }
        vec[size] = value;
        size++;
    }

    int at(int index)
    {
        return vec[index];
    }

    void pop_back()
    {
        if (!this->isEmpty())
        {
            size--;
        }
    }

    void toString()
    {
        for (int i = 0; i < this->sizeIs(); i++)
        {
            cout << this->at(i) << " ";
        }

        cout << endl;
    }
};

int main()
{
    Vector v(5);

    v.push_back(4);
    v.push_back(5);
    v.push_back(3);
    v.push_back(9);
    v.push_back(9);
    cout << v.at(0) << endl;
    cout << v.at(1) << endl;
    cout << v.isFull() << endl;
    v.toString();
    return 0;
}
