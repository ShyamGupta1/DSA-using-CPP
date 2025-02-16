#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rightSmaller(vector<int> &nums)
    {
        vector<int> ans;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (st.size() == 0)
                ans.push_back(-1);
            else if (st.size() > 0 && st.top() < nums[i])
                ans.push_back(st.top());
            else if (st.size() > 0 && st.top() >= nums[i])
            {
                while (!st.empty() && st.top() >= nums[i])
                    st.pop();
                if (st.empty())
                    ans.push_back(-1);
                else
                    ans.push_back(st.top());
            }
            st.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    vector<int> input = {4, 5, 2, 10, 8};
    Solution obj;
    vector<int> result = obj.rightSmaller(input);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}