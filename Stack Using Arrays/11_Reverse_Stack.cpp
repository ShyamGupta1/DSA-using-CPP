/*Define a method to reverse a stack.*/

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
    Stack(Stack &);
    void push(int);
    bool isFull();
    bool isEmpty();
    int peek();
    int pop();
    bool checkOverflow();
    bool checkUnderFlow();
    void reverse();
    void display();
    int getSize();
    Stack &operator=(Stack &);
    ~Stack()
    {
        delete[] ptr;
    }
};

Stack::Stack(Stack &copy)
{
    this->capacity = copy.capacity;
    this->top = copy.top;
    this->ptr = new int[capacity];
    for (int i = 0; i <= top; i++)
        this->ptr[i] = copy.ptr[i];
}

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
    if (isEmpty())
        cout << "\nStack Underflow";
    else
    {
        int i = top;
        while (i != -1)
        {
            cout << ptr[i] << " ";
            i--;
        }
    }
}

// Member Function to reverse

void Stack::reverse()
{
    if (isEmpty())
        cout << "\nStack Underflow";
    else
    {
        int i = 0, j = top;
        if (top == 0)
            return;
        else
        {
            while (i < j)
            {
                ptr[i] = ptr[i] + ptr[j] - (ptr[j] = ptr[i]);
                i++;
                j--;
            }
        }
    }
}

// Non-Member Function to reverse 

void reverse(Stack &s)
{
    Stack *temp = new Stack(s.getSize());
    while (!s.isEmpty())
    {
        temp->push(s.peek());
        s.pop();
    }

    s = *temp; // Copy Assignment operator
}

int main()
{
    Stack S(6);
    S.push(4);
    S.push(3);
    S.push(2);
    S.push(1);
    S.push(0);
    S.push(-1);
    S.reverse();
    S.display();

    return 0;
}
