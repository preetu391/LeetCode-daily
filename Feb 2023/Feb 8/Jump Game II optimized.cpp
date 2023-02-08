#include <bits/stdc++.h>
using namespace std;

int jump(vector<int> &nums)
{
    int jumps = 0, n = nums.size(), currEnd = 0, currFar = 0;

    for (int i = 0; i < n; i++)
    {
        currFar = max(currFar, i + nums[i]);

        if (i == currEnd && i != n - 1)
        {
            jumps++;
            currEnd = currFar;
        }
    }
    return jumps;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    jump(v);
    return 0;
}