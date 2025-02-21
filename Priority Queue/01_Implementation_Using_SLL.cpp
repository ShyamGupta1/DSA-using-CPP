/*
Define a class PriorityQueue with node type pointer start as member variable.
Implement PriorityQueue using singly linked list.
*/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    int pno; // Priority Number
};
class PriorityQueue
{
private:
    node *start;

public:
    PriorityQueue() : start(NULL) {}
};

int main()
{
    return 0;
}