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
};

int main()
{
    return 0;
}