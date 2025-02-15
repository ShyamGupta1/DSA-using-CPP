// In question 1, define a method to insert a new element at the rear in the queue.

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
            this->capacity = -capacity;
        if (capacity == 0)
            this->capacity = 5;
        ptr = new int[capacity];
    }

    void insertRear(int);
};

void Queue::insertRear(int data)
{

    if (front == 0 && rear == capacity - 1 || front == rear + 1)
        cout << "\nQueue Overflow";

    // Empty Case where both front = rear = -1
    else if (rear == -1)
    {
        front = rear = 0;
        ptr[rear] = data;
    }
    // Special Case
    else if (rear != capacity - 1) // No need to check for front > 0 already done in overflow step we can also write (rear != capacity - 1 && front > 0)
    {
        rear = 0;
        ptr[rear] = data;
    }
    // Normal Case when (  rear != capacity - 1 && front == 0)  here rear does not exceed capacity
    else
    {
        rear++;
        ptr[rear] = data;
    }
}

int main()
{

    return 0;
}