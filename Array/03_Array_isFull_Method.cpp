// In the question 1, add a method to check whether an array is full or not by returning True or False.

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
    bool isFull();
};

bool Array::isFull()
{
    return lastIndex == capacity - 1;
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
    Array arr(8);
    cout << arr.isFull();
    return 0;
}