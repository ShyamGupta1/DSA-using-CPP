// In question 1, define a method doubleArray() to increase the size of the array by double of its size.

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

public:
    DynArray(int);
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

int main()
{
    DynArray arr(8);
    return 0;
}