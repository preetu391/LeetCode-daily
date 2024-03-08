#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        map<int, int> mp;
        int max_freq = 0, count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] == max_freq)
            {
                count += max_freq;
            }
            else if (mp[nums[i]] > max_freq)
            {
                max_freq = mp[nums[i]];
                count = max_freq;
            }
        }
        return count;
    }
};