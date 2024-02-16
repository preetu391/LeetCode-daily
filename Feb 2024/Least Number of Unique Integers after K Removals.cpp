#include <bits/stdc++.h>
#include <queue>
#include <map>

using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        map<int, int> mp;
        for (auto ele : arr)
            mp[ele]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        while (k > 0)
        {
            pair<int, int> top = pq.top();
            pq.pop();
            if (k >= top.first)
            {
                k -= top.first;
            }
            else
            {
                k = 0;
                pq.push({top.first - k, top.second});
            }
        }
        return pq.size();
    }
};