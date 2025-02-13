#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node() : data(0), next(NULL) {}
};

class Stack
{
private:
    node *top;

public:
    Stack() : top(NULL) {}
    void push(int);
    int peek();
};

int Stack::peek()
{
    if (top == NULL)
        throw 1;
    return top->data;
}
void Stack::push(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

int main()
{
    Stack S;

    return 0;
}