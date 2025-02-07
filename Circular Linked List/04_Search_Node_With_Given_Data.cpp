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
};

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
    }
    else
    {
        newNode->next = newNode;
        last = newNode;
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
int main()
{
    CLL C;
    return 0;
}