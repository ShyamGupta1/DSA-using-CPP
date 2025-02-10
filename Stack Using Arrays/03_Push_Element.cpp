// In question 1, define a method to push a new element on to the Stack.

#include <iostream>
using namespace std;

class Stack
{
private:
    int capacity;
    int top;
    int *ptr;

public:
    Stack(int capacity) : capacity(capacity), top(-1)
    {
        ptr = new int[this->capacity];
    }
    void push(int);
    bool isFull();
    bool isEmpty();
};

void Stack::push(int data)
{
    if (isFull())
        cout << "\nStack Overflow";
    else
        ptr[++top] = data;
}

bool Stack::isFull()
{
    return top + 1 == capacity;
}

bool Stack::isEmpty()
{
    return top == -1;
}

int main()
{

    return 0;
}