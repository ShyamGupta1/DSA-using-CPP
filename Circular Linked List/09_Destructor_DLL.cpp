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
    ~CLL();
    void insertAtStart(int);
    void insertAtEnd(int);
    node *search(int);
    void insertAfter(node *, int);
    void deleteFirst();
    void deleteLast();
    void deleteSpecificNode(int);
    void display();
};

CLL::~CLL()
{
    while (last)
    {
        deleteFirst();
    }
}

void CLL::deleteSpecificNode(int data)
{
    if (last)
    {
        node *temp = last->next;
        if (last == last->next && last->data == data)
        {
            delete last;
            last = NULL;
            return;
        }
        if (last->data == data)
        {

            while (temp->next != last)
                temp = temp->next;
            temp->next = last->next;
            delete last;
            last = temp;
        }
        else
        {
            if (temp->data == data)
            {
                last->next = temp->next;
                delete temp;
                return;
            }
            do
            {

                if (temp->next->data == data)
                {
                    node *toDelete = temp->next;
                    temp->next = temp->next->next;
                    delete toDelete;
                    break;
                }
                temp = temp->next;
            } while (temp != last);
        }
    }
}

void CLL::deleteLast()
{
    if (last)
    {
        if (last->next == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            node *temp = last->next;

            while (temp->next != last)
                temp = temp->next;
            temp->next = last->next;
            delete last;
            last = temp;
        }
    }
}

void CLL::deleteFirst()
{
    if (last)
    {
        if (last->next == last)
        {
            delete last;
            last = NULL;
        }
        else
        {
            node *temp = last->next;
            last->next = last->next->next;
            delete temp;
        }
    }
}

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
    else
        cout << "Empty";
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
    C.~CLL();
    C.display();
    return 0;
}