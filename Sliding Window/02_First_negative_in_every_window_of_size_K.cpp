#include <bits/stdc++.h>
using namespace std;

// Brute Force 1
class Solution
{
public:
    vector<int> FirstNegativeInteger(vector<int> &arr, int k)
    {

        vector<int> ans;
        for (int i = 0; i <= arr.size() - k; i++)
        {
            bool found = false;
            for (int j = i; j < i + k; j++)
            {
                if (arr[j] < 0)
                {
                    ans.push_back(arr[j]);
                    found = true;
                    break;
                }
            }
            if (!found)
                ans.push_back(0);
        }
        return ans;
    }
};

// Brute Force 2

class Solution
{
public:
    vector<int> FirstNegativeInteger(vector<int> &arr, int k)
    {

        vector<int> ans;
        int i = 0, j = 0;
        while (j < arr.size())
        {
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                int temp = i;
                bool found = false;
                while (temp <= j)
                {
                    if (arr[temp] < 0)
                    {
                        ans.push_back(arr[temp]);
                        found = true;
                        break;
                    }
                    temp++;
                }
                if (!found)
                    ans.push_back(0);
                i++;
                j++;
            }
        }
        return ans;
    }
};

// optimised
class Solution
{
public:
    vector<int> FirstNegativeInteger(vector<int> &arr, int k)
    {

        vector<int> ans;
        deque<int> dq;
        int i = 0, j = 0;
        while (j < arr.size())
        {
            if (arr[j] < 0)
                dq.push_back(arr[j]);
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {

                if (dq.empty())
                    ans.push_back(0);
                else
                {
                    ans.push_back(dq.front());
                    if (arr[i] < 0) // or arr[i] == dq.front()
                        dq.pop_front();
                }
                j++;
                i++;
            }
        }
        return ans;
    }
};