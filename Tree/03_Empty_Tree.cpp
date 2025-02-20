// In question 1, define a method to check if the tree is empty.

#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

class BST
{
private:
    node *root;

public:
    BST() : root(NULL) {}
    bool isEmpty();
};

bool BST::isEmpty()
{
    return root == NULL;
}

int main()
{
    return 0;
}