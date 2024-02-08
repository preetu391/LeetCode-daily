#include <bits/stdc++.h>
using namespace std;

// Using recursion
// TC: O(n^n/2)
class Solution_recursion
{
public:
    int numSquares(int n)
    {
        if (n <= 0)
            return 0;
        int ans = n;
        for (int i = 1; i * i <= n; i++)
        {
            int sq = i * i;
            ans = min(ans, 1 + numSquares(n - sq));
        }
        return ans;
    }
};

// Using DP
// TC: O(n^3/2)
class Solution_dp
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = i;
            for (int j = 1; j * j <= i; j++)
            {
                int sq = j * j;
                if (i - sq >= 0)
                    dp[i] = min(dp[i], 1 + dp[i - sq]);
            }
        }
        return dp[n];
    }
};