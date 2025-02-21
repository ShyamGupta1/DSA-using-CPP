#include <iostream>
using namespace std;

class PriorityQueue
{
private:
    int capacity;
    int highest_priority;
    int **ptr;
    int *front;
    int *rear;

public:
    PriorityQueue(int, int);
    bool isFull(int);
    bool isEmpty(int);
};

bool PriorityQueue::isEmpty(int pno)
{
    // Check for specific priority number
    if (front[pno] == -1 && rear[pno] == -1)
        return true;
    return false;
}

bool PriorityQueue::isFull(int pno)
{
    // Check for specific priority number
    if (front[pno] == 0 && rear[pno] + 1 == capacity || rear[pno] + 1 == front[pno])
        return true;
    return false;
}

PriorityQueue::PriorityQueue(int cap, int hp) : capacity(cap), highest_priority(hp)
{

    if (capacity <= 0)
        capacity = 1;

    ptr = new int *[highest_priority + 1];
    for (int i = 0; i <= highest_priority; ++i)
        ptr[i] = new int[capacity];

    front = new int[highest_priority + 1];
    rear = new int[highest_priority + 1];

    for (int i = 0; i <= highest_priority; ++i)
    {
        front[i] = -1;
        rear[i] = -1;
    }
}

int main()
{
    return 0;
}