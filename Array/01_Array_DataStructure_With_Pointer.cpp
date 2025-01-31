/*
Define a class Array to implement array data structure with member variables to
store capacity of array, last index of the last filled block of the array and a pointer to
hold the address of the first block of the dynamically created array.
define a parameterised constructor to create an array of specified
size.
*/

#include <iostream>
using namespace std;

class Array
{
private:
    int capacity;
    int lastIndex; // Currect status of the array
    int *ptr;

public:
    Array(int);
};

// Parameterized Constructor to create an array

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
    Array arr(8);
    return 0;
}
