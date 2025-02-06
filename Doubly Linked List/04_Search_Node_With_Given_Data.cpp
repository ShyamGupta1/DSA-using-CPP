// In question 1, define a method to search a node with the give item.

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
    void insertAtEnd(int);
    node *search(int);
    void display();
};

void DLL::insertAtStart(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = start;
    newNode->prev = NULL;
    start = newNode;
}

void DLL::insertAtEnd(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    node *temp = start;
    if (start == NULL)
    {
        newNode->prev = NULL;
        start = newNode;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
    }
}

void DLL::display()
{
    node *temp = start;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node *DLL::search(int data)
{
    node *temp = start;
    while (temp != NULL)
    {
        if (temp->data = data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    DLL D;
    return 0;
}