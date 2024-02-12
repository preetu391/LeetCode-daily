#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (cnt == 0)
            {
                candidate = nums[i];
                cnt = 1;
            }
            else if (nums[i] == candidate)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        int cnt2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == candidate)
            {
                cnt2++;
            }
        }
        return cnt2 >= (nums.size() / 2) ? candidate : -1;
    }
};