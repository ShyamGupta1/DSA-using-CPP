/*
In question 1, define a method to insert a data into the list at the beginning.
*/

#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node() : data(0), next(NULL), prev(NULL) {}
};
class DLL
{
private:
    node *start;

public:
    DLL() : start(NULL) {}
    void insertAtStart(int);
};

void DLL::insertAtStart(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = start;
    newNode->prev = NULL;
    if (start)
        start->prev = newNode;
    start = newNode;
}
int main()
{
    DLL D;

    return 0;
}