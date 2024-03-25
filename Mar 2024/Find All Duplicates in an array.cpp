#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            int id = abs(nums[i]) - 1;
            if (nums[id] < 0)
                ans.push_back(abs(nums[i]));
            else
            {
                nums[id] *= (-1);
            }
        }
        return ans;
    }
};