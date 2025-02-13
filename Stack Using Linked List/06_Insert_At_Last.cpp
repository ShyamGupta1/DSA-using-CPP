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

protected:
    void insertLast(int);

public:
    Stack() : top(NULL) {}
    void push(int);
    int peek();
    int pop();
    bool isEmpty();
    ~Stack();
};

bool Stack::isEmpty()
{
    return top==NULL;
}

void Stack::insertLast(int data)
{
    node *temp, *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    if (top == NULL)
        top = newNode;
    else
    {
        temp = top;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

Stack::~Stack()
{
    while (top)
        pop();
}

int Stack::pop()
{
    if (top == NULL)
        throw 1;
    node *temp = top;
    int data = temp->data;
    top = temp->next;
    delete temp;
    return data;
}

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