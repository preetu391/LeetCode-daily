#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int n = nums.size();
    if (target < nums[0])
    {
        return 0;
    }
    if (target > nums[n - 1])
    {
        return n;
    }
    int low = 0, high = n - 1, mid = -1, ans;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    return 0;
}