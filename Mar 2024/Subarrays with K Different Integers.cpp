#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution
{
public:
    int atmostk(vector<int> &nums, int k)
    {
        int left = 0, ans = 0;
        map<int, int> m;
        for (int right = 0; right < nums.size(); right++)
        {
            m[nums[right]]++;
            while (m.size() > k)
            {
                m[nums[left]]--;
                if (m[nums[left]] == 0)
                    m.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return (atmostk(nums, k) - atmostk(nums, k - 1));
    }
};