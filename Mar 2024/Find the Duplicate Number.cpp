#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        if (nums.size() == 1)
            return -1;
        if (nums.size() == 2 && nums[0] == nums[1])
            return nums[0];
        else if (nums.size() == 2 && nums[0] != nums[1])
            return -1;
        int slow = 0;
        int fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
                break;
        }
        fast = 0;
        while (fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};