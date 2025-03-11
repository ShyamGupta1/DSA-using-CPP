#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Node *addOne(Node *head)
    {

        if (!head)
            return head;
        Node *temp = head;
        Node *prev = NULL;
        Node *dummy = head;

        while (temp)
        {
            dummy = temp->next;
            temp->next = prev;
            prev = temp;
            temp = dummy;
        }

        temp = prev;

        while (temp)
        {
            if (temp->data < 9)
            {
                temp->data++;
                break;
            }
            else
                temp->data = 0;
            temp = temp->next;
        }

        temp = prev;
        dummy = prev;
        prev = NULL;

        while (temp)
        {
            dummy = temp->next;
            temp->next = prev;
            prev = temp;
            temp = dummy;
        }

        head = prev;

        if (!head->data)
        {
            Node *newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};