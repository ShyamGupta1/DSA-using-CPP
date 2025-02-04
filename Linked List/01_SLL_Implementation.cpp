/*
Define a class SLL to implement singly linked list data structure with member
variable start pointer of type node.
*/

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
};

int main()
{
    SLL S;

    return 0;
}
