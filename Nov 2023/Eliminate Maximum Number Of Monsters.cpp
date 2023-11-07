#include <bits/stdc++.h>
int eliminateMaximum(vector<int> &dist, vector<int> &speed)
{
    int t = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < dist.size(); i++)
    {
        pq.push((dist[i] % speed[i] == 0) ? (dist[i] / speed[i]) : (dist[i] / speed[i]) + 1);
    }
    while (!pq.empty())
    {
        if (pq.top() > t)
            pq.pop();
        else
            break;
        t++;
    }
    return t;
}
void main()
{
    return;
}
