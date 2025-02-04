// In question 1, define a method to delete last node of the list.

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node() : next(NULL) {}
};
class SLL
{
private:
    node *start;

public:
    SLL() : start(NULL) {}
    void insetAtStart(int);
    void insertAtEnd(int);
    void deleteFirst();
    void deleteLast();
    void display();
};

void SLL::insetAtStart(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = start;
    start = newnode;
}

void SLL::insertAtEnd(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    node *temp = start;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void SLL::deleteFirst()
{
    if (start == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
    node *temp = start;
    start = start->next;
    delete temp;
}
void SLL::deleteLast()
{
    node *prev = NULL, *temp = start;
    if (start)
    {
        if (temp->next == NULL)
        {
            delete temp;
            start = NULL;
        }
        else
        {
            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
    }
}

void SLL::display()
{
    node *ptr = start;
    if (start == NULL)
    {
        cout << "\nList is Empty";
        return;
    }

    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    SLL S;
    S.insetAtStart(1);
    S.insertAtEnd(3);
    S.deleteLast();
    S.display();

    return 0;
}
