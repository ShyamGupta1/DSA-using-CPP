#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Using Map T.C. -> O(n)   S.C -> O(n)

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        unordered_map<Node *, Node *> mp;
        Node *temp = head;
        Node *ans = NULL;
        Node *dummy = NULL;
        while (temp)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = NULL;
            mp[temp] = newNode;
            if (!dummy)
            {
                dummy = newNode;
                ans = newNode;
            }
            else
            {
                dummy->next = newNode;
                dummy = newNode;
            }
            temp = temp->next;
        }
        // Traverse Both List
        temp = head;
        Node *tempnew = ans;
        while (temp)
        {
            if (temp->random)
                tempnew->random = mp[temp->random];
            temp = temp->next;
            tempnew = tempnew->next;
        }
        return ans;
    }
};

// Optimised T.C. ->O(n) S.C. -> O(1)

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        if (!head)
            return head;
        Node *temp = head;
        while (temp)
        {
            Node *newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }

        temp = head;

        while (temp)
        {
            if (temp->random != NULL)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        Node *nayaHead = head->next;
        Node *temp1 = nayaHead;
        Node *puranaHead = head;
        Node *temp2 = puranaHead;

        while (temp1->next != NULL)
        {
            temp2->next = temp2->next->next;
            temp1->next = temp1->next->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp2->next = NULL;
        return nayaHead;
        ;
    }
};