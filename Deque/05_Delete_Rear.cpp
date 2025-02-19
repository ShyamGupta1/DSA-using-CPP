// In question 1, define a method to delete rear element.

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
};
class Deque
{
private:
    node *front;
    node *rear;

public:
    Deque() : front(NULL), rear(NULL) {}
    void insertFront(int);
    void insertRear(int);
    void deleteFront();
    void deleteRear();
};

void Deque::deleteRear()
{
    if (rear)
    {
        // Single Node
        if (front == rear) // or rear->prev == NULL
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            node *temp = rear;
            rear = rear->prev;
            rear->next = NULL;
            delete temp;
        }
    }
}

void Deque::deleteFront()
{
    if (front)
    {
        // Single Node
        if (front == rear) // or front->next == NULL
        {
            delete front;
            front = rear = NULL;
        }
        else
        {
            node *temp = front;
            front = front->next;
            front->prev = NULL;
            delete temp;
        }
    }
}

void Deque::insertRear(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL)
    {
        // Deque is Empty
        newNode->prev = NULL;
        front = rear = newNode;
    }
    else
    {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
}

void Deque::insertFront(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->prev = NULL;

    if (front == NULL)
    {
        // Deque is Empty
        newNode->next = NULL;
        front = rear = newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

int main()
{
    return 0;
}