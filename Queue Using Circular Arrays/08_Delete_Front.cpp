// In question 1, define a method to delete the front element of the queue.

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
    bool isFull();
    bool isEmpty();
    int getRear();
    int getFront();
    void deleteFront();
    ~Queue() { delete[] ptr; }
};

void Queue::deleteFront()
{
    if (isEmpty())
        cout << "\nQueue UnderFlow";
    // Single Value
    else if (front == rear) // && front == rear == capacity - 1;
        front = rear = -1;
    // Front reaches lastIndex and have Many Values
    else if (front == capacity - 1)
        front = 0;
    // Normal Case
    else
        front++;
}

int Queue::getFront()
{
    if (isEmpty())
        throw 1;
    return ptr[front];
}

int Queue::getRear()
{
    if (isEmpty())
        throw 1;
    return ptr[rear];
}

bool Queue::isEmpty()
{
    if (front == -1)
        return true;
    return false;
}

bool Queue::isFull()
{
    if (front == 0 && rear == capacity - 1 || front == rear + 1)
        return true;
    return false;
}

void Queue::insertRear(int data)
{

    if (front == 0 && rear == capacity - 1 || front == rear + 1)
        cout << "\nQueue Overflow";

    else if (rear == -1)
    {
        front = rear = 0;
        ptr[rear] = data;
    }

    else if (rear == capacity - 1)
    {
        rear = 0;
        ptr[rear] = data;
    }

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