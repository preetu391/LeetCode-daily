#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int mx = 0;
        for (auto num : nums)
        {
            mx = max(mx, num);
        }
        long long left = 0, right = 0, cnt = 0, ans = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == mx)
                cnt++;
            while (cnt >= k)
            {
                ans += (long long)(nums.size() - right);
                if (nums[left] == mx)
                {
                    cnt--;
                }
                left++;
            }
        }
        return ans;
    }
};