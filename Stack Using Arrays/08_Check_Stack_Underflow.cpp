/*In question 1, define a method to check stack underflow.*/

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
    int peek();
    int pop();
    bool checkOverflow();
    bool checkUnderFlow();
    ~Stack()
    {
        delete[] ptr;
    }
};

bool Stack::checkUnderFlow()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top + 1 == capacity;
}

int Stack::pop()
{
    try
    {
        if (top == -1)
            throw 1;
        return ptr[--top];
    }
    catch (int e)
    {
        cout << "\nEmpty Stack";
    }
}
int Stack::peek()
{
    try
    {
        if (top == -1)
            throw 1;
        return ptr[top];
    }
    catch (int e)
    {
        cout << "\nEmpty Underflow";
    }
}

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