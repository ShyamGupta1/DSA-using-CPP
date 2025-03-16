#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {

        if (!head || !head->next)
            return;
        stack<ListNode *> st;

        // Find Middle using slow fast
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *secondHalf = slow->next;
        slow->next = NULL;
        // Insert the second half in stack
        while (secondHalf)
        {
            st.push(secondHalf);
            secondHalf = secondHalf->next;
        }

        ListNode *temp = head;
        while (!st.empty())
        {
            ListNode *dummy = st.top();
            st.pop();
            dummy->next = temp->next;
            temp->next = dummy;
            temp = dummy->next;
        }
    }
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {

        if (!head || !head->next)
            return;

        // Find Middle using slow fast
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *secondHalf = slow->next;
        slow->next = NULL;

        // Reverse Second Half
        ListNode *temp = secondHalf;
        ListNode *prev = NULL;
        ListNode *curr = secondHalf;
        while (curr)
        {
            curr = temp->next;
            temp->next = prev;
            prev = temp;
            temp = curr;
        }
        secondHalf = prev;

        temp = head;
        while (secondHalf)
        {
            ListNode *dummy = secondHalf;
            secondHalf = secondHalf->next;
            dummy->next = temp->next;
            temp->next = dummy;
            temp = dummy->next;
        }
    }
};