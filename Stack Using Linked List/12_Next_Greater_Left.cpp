#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> previousLargerElement(vector<int> &nums)
    {
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < nums.size(); i++)
        {
            if (st.size() == 0)
                ans.push_back(-1);
            else if (st.size() > 0 && st.top() > nums[i])
                ans.push_back(st.top());
            else
            {
                while (st.size() > 0 && st.top() <= nums[i])
                    st.pop();
                if (st.size() == 0)
                    ans.push_back(-1);
                else
                    ans.push_back(st.top());
            }
            st.push(nums[i]);
        }
        return ans;
    }
};

int main()
{
    vector<int> input = {1, 3, 2, 4};
    Solution obj;
    vector<int> result = obj.previousLargerElement(input);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    return 0;
}