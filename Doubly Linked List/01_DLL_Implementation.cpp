/*
Define a class DLL to implement singly linked list data structure with member
variable start pointer of type node.
*/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;
    node() : data(0), next(NULL), prev(NULL) {}
};
class DLL
{
private:
    node *start;

public:
    DLL() : start(NULL) {}
    
};
int main()
{
    DLL D;

    return 0;
}