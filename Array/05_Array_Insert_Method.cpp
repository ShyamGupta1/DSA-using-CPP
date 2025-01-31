// In question 1, define a method to insert a new element at specified index.

#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    Array(int);
    bool isEmpty();
    bool isFull();
    void append(int);
    void insert(int, int);
};
bool Array::isEmpty()
{
    return lastIndex == -1;
}

bool Array::isFull()
{
    return lastIndex == capacity - 1;
}

void Array::append(int value)
{
    if (isFull())
    {
        cout << "\nArray is full / Overflow";
        return;
    }
    else
        ptr[++lastIndex] = value;
}

void Array::insert(int index, int value)
{
    if (index > lastIndex + 1 || index < 0)
        cout << "\nInvalid index";
    else if (isFull())
        cout << "\nOverflow";
    else
    {
        for (int i = lastIndex + 1; i > index; i--)
            ptr[i] = ptr[i - 1];
        ptr[index] = value;
        lastIndex++;
    }
}

Array::Array(int size) : capacity(size)
{
    if (size <= 0)
        ptr = nullptr;
    else
    {
        lastIndex = -1;
        ptr = new int[capacity];
    }
}

int main()
{
    return 0;
}