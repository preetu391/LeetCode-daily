#include <bits/stdc++.h>
using namespace std;

int minimumDeviation(vector<int> &nums)
{
    priority_queue<int> pq;
    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2)
            nums[i] *= 2;
        pq.push(nums[i]);
        mini = min(mini, nums[i]);
    }
    int ans = INT_MAX;
    while (1)
    {
        int mx = pq.top();
        pq.pop();
        ans = min(mx - mini, ans);
        if (mx % 2)
            break;
        mx /= 2;
        mini = min(mini, mx);
        pq.push(mx);
    }
    return ans;
}

int main()
{
    return 0;
}