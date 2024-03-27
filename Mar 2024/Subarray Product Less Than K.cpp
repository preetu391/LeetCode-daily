#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int ans = 0, product = 1, left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            product *= nums[i];
            while (product >= k)
            {
                product /= nums[left];
                left++;
            }
            ans += i - left + 1;
        }
        return ans;
    }
};