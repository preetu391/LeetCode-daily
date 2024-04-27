#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution
{
public:
    int recur(string ring, string key, int pt1, int pt2, vector<vector<int>> &dp)
    {
        int n = ring.size();
        int m = key.size();
        if (pt2 >= m)
            return 0;
        if (dp[pt1][pt2] != -1)
            return dp[pt1][pt2];
        int steps = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (ring[i] == key[pt2])
            {
                steps = min(steps, min(abs(i - pt1), n - abs(i - pt1)) + 1 + recur(ring, key, i, pt2 + 1, dp));
            }
        }
        return dp[pt1][pt2] = steps;
    }
    int findRotateSteps(string ring, string key)
    {
        int n = ring.size();
        int m = key.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return recur(ring, key, 0, 0, dp);
    }
};