#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int prev_end = points[0][1];
        int ans = 1;
        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > prev_end)
            {
                ans++;
                prev_end = points[i][1];
            }
            else
            {
                prev_end = min(points[i][1], prev_end);
            }
        }
        return ans;
    }
};