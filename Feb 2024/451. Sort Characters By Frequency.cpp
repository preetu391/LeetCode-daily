#include <bits/stdc++.h>
using namespace std;
#include <queue>

// Using priority_queue
// TC: O(nlogn)
class Solution1
{
public:
    string frequencySort(string s)
    {
        string ans = "";
        unordered_map<char, int> mp;
        for (char c : s)
        {
            mp[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            ans += string(curr.first, curr.second);
        }
        return ans;
    }
};

// Using bucket sort
// TC: O(n+n+1) == O(n)
class Solution2
{
public:
    string frequencySort(string s)
    {
        string ans = "";
        int n = s.size();
        unordered_map<char, int> mp;
        for (char c : s)
        {
            mp[c]++;
        }
        vector<vector<char>> buckets(n + 1);
        for (auto it : mp)
        {
            buckets[it.second].push_back(it.first);
        }
        for (int i = n; i > 0; --i)
        {
            for (auto ch : buckets[i])
            {
                ans += string(i, ch);
            }
        }
        return ans;
    }
};