// In question 1, define a method to delete last node of the list.

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
    void insertAfter(node *, int);
    node *search(int);
    void deleteFirstNode();
    void deleteLastNode();
    void display();
};

void DLL::deleteFirstNode()
{
    if (start)
    {
        node *temp = start;
        start = start->next;
        if (start)
            start->prev = NULL;
        delete temp;
    }
}

void DLL::deleteLastNode()
{
    if (start)
    {
        node *temp = start;
        if (temp->next == NULL)
        {
            start = NULL;
            delete temp;
            return;
        }
        while (temp->next != NULL)
            temp = temp->next;
        temp->prev->next = NULL;
        delete temp;
    }
}

void DLL::insertAfter(node *insert, int data)
{
    if (insert)
    {
        node *newNode = new node;
        newNode->data = data;
        newNode->prev = insert;
        newNode->next = insert->next;
        if (insert->next != NULL)
            insert->next->prev = newNode;
        insert->next = newNode;
    }
}

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

node *DLL::search(int data)
{
    node *temp = start;
    while (temp != NULL)
    {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

int main()
{
    DLL D;
    D.insertAtStart(4);
    D.insertAtStart(3);
    D.insertAtStart(2);
    D.insertAtStart(1);
    D.insertAtEnd(3);
    D.deleteLastNode();

    D.display();

    return 0;
}
