// In question 1, define a destructor to deallocates the memory.

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
class Queue
{
private:
    node *front, *rear;

public:
    Queue() : front(NULL), rear(NULL) {}
    void insert(int);
    int getRear();
    int getFront();
    void deleteFront();
    ~Queue();
};

Queue::~Queue()
{
    while (front)
        deleteFront();
}

void Queue::deleteFront()
{
    if (front)
    {
        if (front == rear)
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            node *temp = front;
            front = front->next;
            delete temp;
        }
    }
}

int Queue::getFront()
{
    if (front == NULL)
        throw 1;
    else
        return front->data;
}

int Queue::getRear()
{
    if (rear == NULL)
        throw 1;
    else
        return rear->data;
}

void Queue::insert(int data)
{
    node *newNode = new node;
    newNode->next = NULL;
    newNode->data = data;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
int main()
{
    return 0;
}