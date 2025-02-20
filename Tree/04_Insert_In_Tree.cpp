// In question 1, define a method to insert a new element in the BST.

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
    void insert(int);
};

void BST::insert(int data)
{
    node *ptr;
    node *newNode = new node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (root == NULL)
        root = newNode;
    else
    {
        ptr = root;
        while (ptr->data != newNode->data)
        {
            if (newNode->data < ptr->data) // Left Subtree
            {
                if (ptr->left != NULL)
                    ptr = ptr->left;
                else
                {
                    ptr->left = newNode;
                    break;
                }
            }
            else // (newNode->data > ptr->data) --> Right Subtree
            {
                if (ptr->right != NULL)
                    ptr = ptr->right;
                else
                {
                    ptr->right = newNode;
                    break;
                }
            }
        }
        if (ptr->data == newNode->data)
            delete newNode;
    }
}

bool BST::isEmpty()
{
    return root == NULL;
}

int main()
{
    return 0;
}