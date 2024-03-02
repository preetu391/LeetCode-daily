#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int i = n - 1;
        vector<int> res(n);
        while (left <= right)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                res[i] = nums[left] * nums[left];
                left++;
            }
            else
            {
                res[i] = nums[right] * nums[right];
                right--;
            }
            i--;
        }
        return res;
    }
};