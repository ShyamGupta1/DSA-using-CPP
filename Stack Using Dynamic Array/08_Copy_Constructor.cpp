#include <iostream>
using namespace std;

class Stack
{
private:
    int capacity;
    int top;
    int *start;

protected:
    void doubleStack();
    void halfStack();

public:
    Stack() : start(NULL) {}
    Stack(int capacity) : capacity(capacity), top(-1)
    {
        start = new int[capacity];
    }
    Stack(Stack &);
    bool isFull();
    bool isEmpty();
    void push(int);
    int peek();
    int pop();
    ~Stack() { delete[] start; }
};

Stack::Stack(Stack &S)
{
    if (S.top != -1)
    {
        capacity = S.capacity;
        top = S.top;
        start = new int[capacity];
        if (S.start)
        {
            for (int i = 0; i <= S.top; i++)
                start[i] = S.start[i];
        }
    }
}

int Stack::pop()
{
    if (isEmpty())
        throw new exception();
    int temp = start[top];
    top--;
    if ((top + 1) * 2 <= capacity && top > 1)
        halfStack();
    return temp;
}

int Stack::peek()
{
    if (isEmpty())
        throw new exception();
    return start[top];
}

void Stack::push(int data)
{
    if (isFull())
        doubleStack();
    start[++top] = data;
}

bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top == capacity - 1;
}

void Stack::doubleStack()
{
    capacity *= 2;
    int *ptr = new int[capacity];
    for (int i = 0; i <= top; i++)
        ptr[i] = start[i];
    delete[] start;
    start = ptr;
}

void Stack::halfStack()
{
    capacity /= 2;
    int *ptr = new int[capacity];
    for (int i = 0; i <= top; i++)
        ptr[i] = start[i];
    delete[] start;
    start = ptr;
}

int main()
{
    return 0;
}