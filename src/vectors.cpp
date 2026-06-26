#include <iostream>
using namespace std;

template <typename T>
class Vector
{
private:
	size_t size = 0;
	size_t capacity = 0;
	T *nums = nullptr;

public:
	Vector() { cout << "Start" << endl; }
	~Vector()
	{
		clear();
		operator delete(nums, capacity);
		cout << "End" << endl;
	}

	size_t length()
	{
		return size;
	}

	T &operator[](size_t index)
	{
		if (index >= 0 && index < this->size)
		{
			return this->nums[index];
		}
		else
		{
			throw out_of_range("Index out of bounds!");
		}
	}

	const T &operator[](size_t index) const
	{
		if (index >= 0 && index < this->size)
		{
			return this->nums[index];
		}
		else
		{
			throw out_of_range("Index out of bounds!");
		}
	}

	void push_back(T value)
	{
		if (isEmpty())
		{
			this->capacity = 1;
			T *arr = (T *)operator new(this->capacity * sizeof(T));

			arr[this->size] = value;
			this->nums = arr;
		}
		else if (isFull())
		{
			this->capacity *= 2;
			T *arr = (T *)operator new(this->capacity * sizeof(T));
			for (size_t i = 0; i < this->size; i++)
			{
				arr[i] = move(nums[i]);
			}

			for (size_t i = 0; i < this->size; i++)
			{
				nums[i].~T();
			}

			operator delete(nums, size);
			arr[this->size] = value;
			this->nums = arr;
		}
		else
		{
			this->nums[this->size] = value;
		}
		this->size++;
	}
	void pop_back()
	{
		if (isEmpty())
		{
			throw out_of_range("Stack Underflow!");
		}
		else
		{
			this->size--;
			this->nums[this->size].~T();
		}
	}

	void clear()
	{
		for (size_t i = 0; i < this->size; i++)
		{
			this->nums[i].~T();
		}
		this->size = 0;
	}

	bool isEmpty()
	{
		return this->size == 0;
	};
	bool isFull()
	{
		return this->size == this->capacity;
	};

	void traverse()
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << this->nums[i] << endl;
		}
	}
};

int main()
{
	Vector<string> vec;
	vec.push_back("Apple");
	vec.push_back("Banana");
	vec.push_back("Cherry");
	vec.push_back("Dragon fruits");
	cout << vec[0] << endl;
	cout << vec[1] << endl;
	cout << endl;
	vec.traverse();

	cout << "Size: " << vec.length() << endl;

	vec[0] = "Avocada";
	vec[1] = "Berry";
	cout << endl;
	cout << vec[0] << endl;
	cout << vec[1] << endl;
	cout << endl;
	vec.traverse();
	// vec.pop_back();
	// vec.pop_back();
	// vec.pop_back();
	// vec.traverse();
	// vec.pop_back();
	// vec.pop_back();
	return 0;
}
