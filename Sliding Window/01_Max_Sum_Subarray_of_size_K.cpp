#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSumSubarray(vector<int> &arr, int k)
    {

        int maxSum = INT_MIN;
        int sum = 0;
        int i = 0, j = 0;
        while (j < arr.size())
        {
            sum += arr[j];
            if (j - i + 1 < k)
                j++;
            else if (j - i + 1 == k)
            {
                maxSum = max(maxSum, sum);
                sum = sum - arr[i];
                i++;
                j++;
            }
        }
        return maxSum;
    }
};