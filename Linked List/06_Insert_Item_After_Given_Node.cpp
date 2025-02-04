// In question 1, define a method to insert a data into the list after the specified node of the list.

// In question 1, define a method to search a node with the given item.

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
    node *search(int);
    void insertAfter(node *, int);
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

void SLL::insertAfter(node *insert, int data)
{
    if (insert != NULL)
    {
        node *newNode = new node;
        newNode->data = data;
        newNode->next = insert->next;
        insert->next = newNode;
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
    S.insetAtStart(3);
    S.insetAtStart(2);
    S.insetAtStart(1);
    S.insertAtEnd(4);
    S.insertAfter(S.search(4), 5);
    S.display();
    return 0;
}
