/*
In question 1 define a method to insert a data into the list at the end
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
    void insertAtEnd(int);
    void display();
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
int main()
{
    DLL D;
    D.insertAtStart(3);
    D.insertAtStart(2);
    D.insertAtStart(1);
    D.insertAtStart(0);
    D.insertAtEnd(4);
    D.insertAtEnd(5);
    D.insertAtEnd(6);
    D.insertAtEnd(7);
    D.display();

    return 0;
}