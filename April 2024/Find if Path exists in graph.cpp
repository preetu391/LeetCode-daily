#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        queue<int> q;
        vector<bool> visited(n, false);
        vector<vector<int>> graph(n);
        q.push(source);
        visited[source] = true;
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (node == destination)
                return true;
            vector<int> adj_nodes = graph[node];
            for (int i = 0; i < adj_nodes.size(); i++)
            {
                if (!visited[adj_nodes[i]])
                {
                    q.push(adj_nodes[i]);
                    visited[adj_nodes[i]] = true;
                }
            }
        }
        return false;
    }
};