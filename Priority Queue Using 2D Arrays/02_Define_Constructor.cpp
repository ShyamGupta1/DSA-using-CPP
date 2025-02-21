// Define a constructor to initialise member variable.

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
};

PriorityQueue::PriorityQueue(int cap, int hp) : capacity(cap), highest_priority(hp)
{

    if (capacity <= 0)
        capacity = 1; // capacity set to 1 for safer side

    // Dynamically allocate memory for the 2D array
    ptr = new int *[highest_priority + 1];
    for (int i = 0; i <= highest_priority; ++i)
    {
        ptr[i] = new int[capacity];
    }

    // Dynamically allocate memory for front and rear arrays
    front = new int[highest_priority + 1];
    rear = new int[highest_priority + 1];

    // Initialize front and rear for each array (queue)
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