#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;

public:
    node() : prev(NULL), data(0), next(NULL) {}
};

class DCLL
{
private:
    node *start;

public:
    DCLL() : start(NULL) {}
    void insertAtStart(int);
};

void DCLL::insertAtStart(int data)
{
    node *newNode = new node;
    newNode->data = data;

    if (start == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else
    {
        newNode->next = start;
        newNode->prev = start->prev;
        start->prev->next = newNode;
        start->prev = newNode;
    }
    start = newNode;
};

int main()
{
    DCLL DC;

    return 0;
}