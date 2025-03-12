// Brute Force T.C. -> O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {

        int pos = 0;
        int neg = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] < 0)
                neg++;
            else if (nums[i])
                pos++;
        return max(pos, neg);
    }
};

// Using Binary Search T.C. -> O(log(n))

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {

        int n = nums.size();
        int start = 0, end = n - 1;
        int neg = -1;
        int pos = -1;

        // Last Occurrence of a negative number
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] < 0)
            {
                neg = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }

        // First Occurrence of a positive number
        start = 0;
        end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] > 0)
            {
                pos = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        if (pos == -1 and neg == -1)
            return 0;
        else if (pos == -1)
            pos = 0, neg = neg + 1;
        else if (neg == -1)
            neg = 0, pos = n - pos;
        else
            neg = neg + 1, pos = n - pos;

        return max(pos, neg);
    }
};

// Using STLs T.C. -> O(log(n))

class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        auto it = upper_bound(nums.begin(), nums.end(), 0);
        int pos = nums.end() - it;
        it = lower_bound(nums.begin(), nums.end(), 0);
        int neg = it - nums.begin();
        return max(pos, neg);
    }
};