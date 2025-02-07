// Define a class CLL to implement Circular linked list data structure with member variable last pointer of type node.

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
};

int main()
{
    CLL C;
    return 0;
}