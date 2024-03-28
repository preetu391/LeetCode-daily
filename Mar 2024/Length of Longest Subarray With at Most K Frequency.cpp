#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        map<int, int> mp;
        int maxx = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            while (mp[nums[i]] > k)
            {
                mp[nums[left]]--;
                left++;
            }
            maxx = max(maxx, i - left + 1);
        }
        return maxx;
    }
};