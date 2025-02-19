/*
Define a class Deque with node type pointers front and rear as member variables.
Implement queue using doubly linked list.
*/

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
};
class Deque
{
private:
    node *front;
    node *rear;

public:
    Deque() : front(NULL), rear(NULL) {}
};

int main()
{
    return 0;
}