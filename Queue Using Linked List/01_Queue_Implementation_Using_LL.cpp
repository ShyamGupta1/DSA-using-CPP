#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};
class Queue
{
private:
    node *front, *rear;

public:
    Queue() : front(NULL), rear(NULL) {}
};

int main()
{
    return 0;
}