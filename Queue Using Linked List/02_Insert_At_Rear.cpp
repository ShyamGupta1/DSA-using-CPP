// In question 1, define a method to insert a new element at the rear in the queue.

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
};

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