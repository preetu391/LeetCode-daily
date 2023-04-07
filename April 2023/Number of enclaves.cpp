#include <bits/stdc++.h>
using namespace std;

int numEnclaves(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 1)
            {
                q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }
    int y[] = {0, 1, 0, -1};
    int x[] = {1, 0, -1, 0};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + y[i];
            int ncol = col + x[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && vis[i][j] == 0)
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    return 0;
}