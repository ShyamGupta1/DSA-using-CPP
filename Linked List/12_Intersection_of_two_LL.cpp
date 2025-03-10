#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute Force T.C. -> O(m*n)   S.C. -> O(1)

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *first = headA;
        ListNode *second = headB;
        while (first)
        {
            second = headB;
            while (second)
            {
                if (first == second)
                    return first;
                second = second->next;
            }
            first = first->next;
        }
        return NULL;
    }
};

// Using Hashing
// T.C. -> O(m + n) Iterating over both list
// S.C. -> O(n) Storing list 1 element in set

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        if (!headA || !headB)
            return NULL;
        unordered_set<ListNode *> search;
        ListNode *temp = headA;

        // Insert All the elements in set
        while (temp)
        {
            search.insert(temp);
            temp = temp->next;
        }
        // Iterate LL2 and find search for the node in set
        temp = headB;
        while (temp)
        {
            if (search.find(temp) != search.end())
                return temp;
            temp = temp->next;
        }
        return NULL;
    }
};

// Using Difference in length

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        if (!headA || !headB)
            return NULL;
        ListNode *first = headA;
        ListNode *second = headB;
        int size1 = 0;
        int size2 = 0;

        while (first || second)
        {
            if (first)
            {
                size1++;
                first = first->next;
            }
            if (second)
            {
                size2++;
                second = second->next;
            }
        }

        int diff = abs(size1 - size2);

        if (size1 >= size2)
        {
            first = headA;
            second = headB;
        }
        else
        {
            first = headB;
            second = headA;
        }
        while (first && diff--)
            first = first->next;
        while (first && second)
        {
            if (first == second)
                return first;
            first = first->next;
            second = second->next;
        }
        return NULL;
    }
};

// Optimised T.C. -> O(m + n) S.C. -> O(1)

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        ListNode *first = headA;
        ListNode *second = headB;

        while (first != second) // Either they will meet or both become NULL.
        {
            if (first == NULL)
                first = headB;
            else
                first = first->next;

            if (second == NULL)
                second = headA;
            else
                second = second->next;
        }
        return first;
    }
};