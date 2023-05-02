#include <bits/stdc++.h>
using namespace std;

int arraySign(vector<int> &nums)
{
    int x = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            x++;
        }
        else if (nums[i] == 0)
        {
            ans = 1;
        }
    }
    if (ans)
    {
        return 0;
    }
    else
    {
        if (x % 2 == 0)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

int main()
{
    return 0;
}