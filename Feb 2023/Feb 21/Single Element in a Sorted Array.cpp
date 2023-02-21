#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int l = 0, h = n - 1, mid;
    if (n == 1)
        return nums[0];
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (mid > 0 && mid < n - 1 && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];
        if (mid == 0 && nums[mid] != nums[mid + 1])
            return nums[mid];
        if (mid == n - 1 && nums[mid] != nums[mid - 1])
            return nums[mid];
        if ((mid % 2 == 0) && (nums[mid] == nums[mid - 1]) || (mid % 2 == 1) && (nums[mid] == nums[mid + 1]))
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return 0;
}

int main()
{
    return 0;
}