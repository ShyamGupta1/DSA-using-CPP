/*
Define a class DynArray to implement dynamic array data structure with member
variables to store capacity of array, last index of the last filled block of the array and
a pointer to hold the address of the first block of the dynamically created array.
Define a parameterised constructor to create an array of specified
size.
*/

#include <iostream>

using namespace std;

class DynArray
{
private:
    int capacity;
    int lastIndex;
    int *ptr;

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

int main()
{
    DynArray arr(8);
    return 0;
}
