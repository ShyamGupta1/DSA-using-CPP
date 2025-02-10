// In question 1 , define a parameterzied constructor to initialise member variables.

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
};

int main()
{

    return 0;
}