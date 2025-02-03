// In question 1, define a method to append a new element in the array.

#include <iostream>

using namespace std;

class DynArray
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

protected:
    void dynArray();
    void halfArray();

public:
    DynArray(int);
    bool isFull();
    bool isEmpty();
    void append(int);
};

DynArray::DynArray(int size) : capacity(size)
{
    if (size <= 0)
        ptr = NULL;
    else
    {
        lastIndex = -1;
        ptr = new int[capacity];
    }
}

void DynArray::halfArray()
{
    int *temp, i;
    capacity /= 2;
    temp = new int[capacity];
    for (i = 0; i <= lastIndex; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
}

void DynArray::dynArray()
{
    int *temp, i;
    capacity *= 2;
    temp = new int[capacity];
    for (i = 0; i <= lastIndex; i++)
        temp[i] = ptr[i];
    delete[] ptr;
    ptr = temp;
}

bool DynArray::isFull()
{
    return capacity == lastIndex + 1;
}

bool DynArray::isEmpty()
{
    return lastIndex == -1;
}
void DynArray::append(int data)
{
    if (isFull())
        dynArray();
    ptr[++lastIndex] = data;
}
int main()
{
    DynArray arr(8);
    return 0;
}
