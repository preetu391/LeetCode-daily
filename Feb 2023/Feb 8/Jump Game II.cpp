#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return 0;
    vector<int> dp(n, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= nums[i] && i + j < n; j++)
        {
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }
    return dp[n - 1];
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    jump(v);
    return 0;
}