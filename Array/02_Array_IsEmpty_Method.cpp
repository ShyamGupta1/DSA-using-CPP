// In the question 1, add a method to check whether an array is empty or not by returning True or False.

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
};

bool Array::isEmpty()
{
    return lastIndex == -1;
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
    cout << arr.isEmpty();
    return 0;
}