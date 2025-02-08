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
    void display();
};

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
    DC.display();

    return 0;
}