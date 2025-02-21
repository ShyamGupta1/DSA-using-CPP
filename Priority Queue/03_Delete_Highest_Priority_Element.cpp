// In question 1, define a method to delete highest priority element.

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    int pno; // Priority Number
};
class PriorityQueue
{
private:
    node *start;

public:
    PriorityQueue() : start(NULL) {}
    void insert(int, int);
    void deleteNode();
};

void PriorityQueue::deleteNode()
{
    if (start)
    {
        node *temp = start;
        start = start->next;
        delete temp;
    }
}

void PriorityQueue::insert(int data, int pno)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->pno = pno;
    if (start == NULL)
    {
        newNode->next = NULL;
        start = newNode;
    }
    else
    {
        node *temp = start;
        node *prev = NULL;
        while (temp)
        {
            if (pno > temp->pno)
                break;
            prev = temp;
            temp = temp->next;
        }
        if (prev)
        {
            newNode->next = temp;
            prev->next = newNode;
        }
        else
        {
            newNode->next = temp;
            start = newNode;
        }
    }
}

int main()
{
    return 0;
}