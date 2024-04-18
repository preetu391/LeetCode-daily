#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (((i + dx[k]) >= 0) && ((i + dx[k]) < n) && ((j + dy[k]) >= 0) && ((j + dy[k]) < m))
                        {
                            if (grid[i + dx[k]][j + dy[k]] == 0)
                                ans++;
                        }
                        else if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};