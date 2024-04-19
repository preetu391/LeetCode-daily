#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int noofisland = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    noofisland++;
                    dfs(grid, i, j);
                }
            }
        }
        return noofisland;
    }
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int r = grid.size();
        int c = grid[0].size();
        if (i < 0 || j < 0 || i >= r || j >= c)
            return;
        if (grid[i][j] == '0')
            return;
        if (grid[i][j] == '2')
            return;
        if (grid[i][j] == '1')
        {
            grid[i][j] = '2';
            dfs(grid, i, j + 1);
            dfs(grid, i, j - 1);
            dfs(grid, i - 1, j);
            dfs(grid, i + 1, j);
        }
    }
};