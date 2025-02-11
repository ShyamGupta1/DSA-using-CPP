// In question 1, define a destructor to deallocates memory for all the nodes in the linked list.

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
    SLL(SLL &);
    ~SLL();
    void insetAtStart(int);
    void insertAtEnd(int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    node *search(int);
    void display();
    SLL &operator=(SLL &);
};

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

node *SLL::search(int data)
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

void SLL::deleteNode(int data)
{
    node *copy, *temp = start;
    if (start)
    {
        if (temp->data == data)
        {
            start = start->next;
            delete temp;
        }
        else
        {
            while (temp->next != NULL)
            {
                if (temp->next->data == data)
                {
                    copy = temp->next;
                    temp->next = temp->next->next;
                    delete copy;
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

SLL::~SLL()
{
    while (start)
        deleteFirst();
}

SLL::SLL(SLL &S)
{
    start = NULL;
    node *temp = S.start;
    node *dummy = start;
    if (temp)
    {
        while (temp != NULL)
        {
            node *newNode = new node;
            newNode->data = temp->data;
            newNode->next = NULL;
            if (start == NULL)
            {
                start = newNode;
                dummy = start;
            }
            else
            {
                dummy->next = newNode;
                dummy = newNode;
            }
            temp = temp->next;
        }
    }
}

SLL &SLL::operator=(SLL &S)
{
    if (this != &S)
    {
        if (start)
        {
            delete[] start;
            start = NULL;
        }
        node *temp = S.start;
        node *dummy = start;
        while (temp != NULL)
        {
            node *newNode = new node;
            newNode->data = temp->data;
            newNode->next = NULL;
            if (start)
            {
                dummy->next = newNode;
                dummy = newNode;
            }
            else
            {
                start = newNode;
                dummy = newNode;
            }
            temp = temp->next;
        }
    }
    return *this;
}
int main()
{
    SLL S;
    S.insetAtStart(1);
    S.insertAtEnd(3);
    S.insertAtEnd(4);
    S.insertAtEnd(5);
    SLL copy1, copy2;
    copy1 = copy2 = S;

    copy1.display();
    cout << endl;
    copy2.display();

    return 0;
}
