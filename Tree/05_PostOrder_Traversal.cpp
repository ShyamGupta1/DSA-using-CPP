// In question 1, define a method for postorder traversing of BST

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

protected:
    void preorderrec(node *);
    void postorderrec(node *);

public:
    BST() : root(NULL) {}
    bool isEmpty();
    void insert(int);
    void preorder();
    void postorder();
};



void BST::postorderrec(node *ptr)
{
    if (ptr)
    {
        postorderrec(ptr->left);
        postorderrec(ptr->right);
        cout << ptr->data << " ";
    }
}
void BST::postorder()
{
    postorderrec(root);
}

void BST::preorderrec(node *ptr)
{
    if (ptr)
    {
        cout << ptr->data << " ";
        preorderrec(ptr->left);
        preorderrec(ptr->right);
    }
}
void BST::preorder()
{
    preorderrec(root);
}

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