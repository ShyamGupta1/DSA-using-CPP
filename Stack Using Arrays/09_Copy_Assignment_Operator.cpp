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
    int getSize();
    void display();
    Stack &operator=(Stack &);
    ~Stack()
    {
        delete[] ptr;
    }
};

Stack &Stack::operator=(Stack &copy)
{
    if (this != &copy)
    {
        if (ptr != NULL)
            delete[] ptr;
        capacity = copy.capacity;
        top = copy.top;
        ptr = new int[capacity];
        for (int i = 0; i <= top; i++)
        {
            ptr[i] = copy.ptr[i];
        }
        return *this;
    }
}

int Stack::getSize()
{
    return top + 1;
}

bool Stack::checkUnderFlow()
{
    return isEmpty();
}

bool Stack::checkOverflow()
{
    return isFull();
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

void Stack::display()
{
    int i = top;
    while (i != -1)
    {
        cout << ptr[i] << " ";
        i--;
    }
}

int main()
{
    Stack S(6);
    S.push(-8);
    S.push(3);
    S.push(-7);
    S.push(1);
    S.push(9);
    S.push(-1);
    Stack St = S;
    St.display();

    return 0;
}