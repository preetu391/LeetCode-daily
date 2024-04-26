#include <bits/stdc++.h>
using namespace std;

// Recursive solution
class Solution_recursion
{
public:
    int recur(vector<vector<int>> &grid, int i, int j)
    {
        if (i == grid.size())
            return 0;
        int ans = INT_MAX;
        for (int k = 0; k < grid[0].size(); k++)
        {
            if (j == k)
                continue;
            ans = min(ans, recur(grid, i + 1, k) + grid[i][j]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 1)
            return grid[0][0];
        int ans = INT_MAX;
        for (int j = 0; j < n; j++)
            ans = min(ans, recur(grid, 0, j));
        return ans;
    }
};

// Tabulation solution
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 1)
            return grid[0][0];
        vector<vector<int>> dp(n, vector<int>(n));
        for (int j = 0; j < n; j++)
            dp[0][j] = grid[0][j];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int ans = INT_MAX;
                for (int k = 0; k < n; k++)
                {
                    if (j == k)
                        continue;
                    ans = min(ans, dp[i - 1][k] + grid[i][j]);
                }
                dp[i][j] = ans;
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};