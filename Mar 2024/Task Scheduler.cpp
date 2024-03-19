#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26, 0);
        for (int i = 0; i < tasks.size(); i++)
        {
            freq[tasks[i] - 'A']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int idle = (freq[0] - 1) * n;
        for (int i = 1; i < 26; i++)
        {
            idle -= min(freq[i], freq[0] - 1);
        }
        return tasks.size() + max(0, idle);
    }
};