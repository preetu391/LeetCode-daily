#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int count = 0;
        mp[0] = -1;
        int maxi = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                count--;
            else
                count++;
            if (mp.find(count) != mp.end())
                maxi = max(maxi, i - mp[count]);
            else
                mp[count] = i;
        }
        return maxi;
    }
};