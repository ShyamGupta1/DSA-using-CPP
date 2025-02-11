#include <iostream>
using namespace std;

class Stack
{
private:
    int capacity;
    int top;
    int *start;

public:
    Stack() : start(NULL) {}
    Stack(int capacity) : capacity(capacity), top(-1)
    {
        start = new int[capacity];
    }
};

int main()
{
    return 0;
}