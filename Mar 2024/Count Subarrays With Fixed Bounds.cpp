#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long res = 0, lastInvalidId = -1, latestMinId = -1, latestMaxId = -1, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] < minK || nums[i] > maxK)
                lastInvalidId = i;
            if (nums[i] == minK)
                latestMinId = i;
            if (nums[i] == maxK)
                latestMaxId = i;
            res += max((long long)0, min(latestMinId, latestMaxId) - lastInvalidId);
        }
        return res;
    }
};