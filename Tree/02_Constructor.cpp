// In question 1, define a constructor to initialise root pointer with NULL.

#include <iostream>
using namespace std;

class node
{
public:
    node *left;
    int data;
    node *right;
};

class BST
{
private:
    node *root;

public:
    BST() : root(NULL) {}
};

int main()
{
    return 0;
}