#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), bt(n);
        int max_len = 1, ind = 0;
        for (int i = 0; i < n; i++)
        {
            bt[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    bt[i] = j;
                }
            }
            if (dp[i] > max_len)
            {
                max_len = dp[i];
                ind = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[ind]);
        while (bt[ind] != ind)
        {
            ind = bt[ind];
            ans.push_back(nums[ind]);
        }
        return ans;
    }
};