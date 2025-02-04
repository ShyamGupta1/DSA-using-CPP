// In question 1, define a method to insert a data into the list at the beginning.

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
};

void SLL::insetAtStart(int data)
{
    node *newnode = new node;
    newnode->data = data;
    newnode->next = start;
    start = newnode;
}

int main()
{
    SLL S;

    return 0;
}
