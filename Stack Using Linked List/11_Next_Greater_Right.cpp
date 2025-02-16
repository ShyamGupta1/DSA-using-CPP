// WAP to find the next greater element for each element of the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &nums)
    {

        vector<int> ans;
        stack<int> st;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (st.empty())
                ans.push_back(-1);

            else if (!st.empty() && st.top() > nums[i])
                ans.push_back(st.top());

            else if (!st.empty() && st.top() <= nums[i])
            {
                while (!st.empty() && st.top() <= nums[i])
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
    vector<int> a = {6, 8, 0, 1, 3};

    Solution obj;

    vector<int> result = obj.nextLargerElement(a);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}
