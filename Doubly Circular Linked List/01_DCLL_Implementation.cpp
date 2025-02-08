#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;

public:
    node() : prev(NULL), data(0), next(NULL) {}
};

class DCLL
{
private:
    node *start;

public:
    DCLL() : start(NULL) {}
};

int main()
{
    DCLL DC;

    return 0;
}