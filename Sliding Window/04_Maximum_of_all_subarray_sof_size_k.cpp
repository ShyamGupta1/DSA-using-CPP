#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        int i = 0;
        int j = 0;
        deque<int> dq;
        vector<int> ans;
        while (j < nums.size())
        {
            while (!dq.empty() && dq.back() < nums[j])
                dq.pop_back();
            dq.push_back(nums[j]);

            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                ans.push_back(dq.front());
                if (!dq.empty() && dq.front() == nums[i])
                    dq.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};