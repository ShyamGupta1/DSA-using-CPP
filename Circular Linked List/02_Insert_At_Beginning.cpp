#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node() : data(0), next(NULL) {}
};

class CLL
{
private:
    node *last;

public:
    CLL() : last(NULL) {}
    void insertAtStart(int);
};

void CLL::insertAtStart(int data)
{
    node *newNode = new node;
    newNode->data = data;
    if (last)
        newNode->next = last->next;
    else
        last = newNode;
    last->next = newNode;
}
int main()
{
    CLL C;
    return 0;
}
