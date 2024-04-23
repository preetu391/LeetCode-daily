#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans;
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
            {
                q.push(i);
                indegree[i]--;
            }
        }
        while (!q.empty())
        {
            int s = q.size();
            ans.clear();
            for (int i = 0; i < s; i++)
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for (auto child : graph[curr])
                {
                    indegree[child]--;
                    if (indegree[child] == 1)
                        q.push(child);
                }
            }
        }
        return ans;
    }
};