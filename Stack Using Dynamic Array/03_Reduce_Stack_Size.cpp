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
};

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