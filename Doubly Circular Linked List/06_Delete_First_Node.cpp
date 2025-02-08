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
    void insertAtLast(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void display();
};

void DCLL::deleteFirst()
{
    if (start)
    {
        if (start->next == start)
        {
            delete start;
            start = NULL;
        }
        else
        {
            node *temp = start;
            start->next->prev = start->prev;
            start->prev->next = start->next;
            start = start->next;
            delete temp;
        }
    }
}

void DCLL::insertAfter(node *insert, int data)
{
    if (insert)
    {
        node *newNode = new node;
        newNode->data = data;
        newNode->next = insert->next;
        newNode->prev = insert;
        insert->next->prev = newNode;
        insert->next = newNode;
    }
}

node *DCLL::search(int data)
{

    node *temp = start;
    do
    {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    } while (temp != start);

    return NULL;
}

void DCLL::insertAtLast(int data)
{
    node *newNode = new node;
    newNode->data = data;

    if (start == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        start = newNode;
    }
    else
    {

        newNode->next = start;
        newNode->prev = start->prev;
        start->prev->next = newNode;
        start->prev = newNode;
    }
}
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

void DCLL::display()
{
    node *temp = start;
    if (!start)
    {
        cout << "Empty";
        return;
    }
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != start);
}

int main()
{
    DCLL DC;

    DC.insertAtStart(4);
    DC.insertAtStart(3);
    DC.insertAtStart(2);
    DC.insertAtStart(1);
    DC.insertAtStart(0);
    DC.insertAtStart(-1);
    DC.insertAtLast(5);
    DC.insertAtLast(6);
    DC.deleteFirst();
    DC.display();

    return 0;
}