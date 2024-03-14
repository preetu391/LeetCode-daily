#include <bits/stdc++.h>
using namespace std;

//solution in which we are removing trailing zeroes
class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int i = 0, j = 0, count = 0, sum = 0;
        while (j < nums.size())
        {
            sum += nums[j];
            while (i < j && sum > goal)
            {
                sum -= nums[i];
                i++;
            }
            if (sum == goal)
            {
                int k = i;
                while (k < j && nums[k] == 0)
                {
                    count++;
                    k++;
                }
                count++;
            }
            j++;
        }
        return count;
    }
};

//solution to calculate using the atmost(n) logic
class Solution2
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return atmost_subarr_with_goal(nums, goal) - atmost_subarr_with_goal(nums, goal - 1);
    }
    int atmost_subarr_with_goal(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;
        int sum = 0, i = 0, count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while (sum > goal)
            {
                sum -= nums[i++];
            }
            count += (j - i + 1);
        }
        return count;
    }
};