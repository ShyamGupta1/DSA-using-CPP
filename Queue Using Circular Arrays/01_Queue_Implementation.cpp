#include <iostream>
using namespace std;

class Queue
{
private:
    int capacity;
    int front;
    int rear;
    int *ptr;

public:
    Queue(int capacity) : front(-1), rear(-1)
    {
        if (capacity < 0)
            this->capacity = -capacity; // Make it positive
        if (capacity == 0)
            this->capacity = 5; // For the safer side
        ptr = new int[capacity];
    }
};

int main()
{
    return 0;
}