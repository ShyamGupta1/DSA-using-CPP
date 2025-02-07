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
    void insertAtEnd(int);
    node *search(int);
    void insertAfter(node *, int);
    void display();
};

void CLL::insertAfter(node *insert, int data)
{
    if (insert)
    {
        node *newNode = new node;
        newNode->data = data;

        if (insert == last)
        {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
        else
        {
            newNode->next = insert->next;
            insert->next = newNode;
        }
    }
}

node *CLL::search(int data)
{
    if (last)
    {
        node *temp = last->next;
        do
        {
            if (temp->data == data)
                return temp;
            temp = temp->next;
        } while (temp != last->next);
    }
    return NULL;
}

void CLL::insertAtEnd(int data)
{
    node *newNode = new node;
    newNode->data = data;
    if (last)
    {
        newNode->next = last->next;
        last->next = newNode;
        last = last->next;
    }
    else
    {
        newNode->next = newNode;
        last = newNode;
    }
}
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

void CLL::display()
{
    if (last)
    {
        node *temp = last->next;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
    }
}

int main()
{
    CLL C;
    C.insertAtStart(4);
    C.insertAtStart(3);
    C.insertAtStart(2);
    C.insertAtStart(1);
    C.insertAtStart(0);
    C.insertAtEnd(5);
    C.insertAfter(C.search(5), 6);
    C.display();
    return 0;
}