// In question 1, define a method to insert a new element at the front.

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
};

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