#include <bits/stdc++.h>
using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans;
    int i = 0, j = nums.size() / 2;
    while (i < nums.size() / 2 && j < nums.size())
    {
        ans.push_back(nums[i]);
        ans.push_back(nums[j]);
        i++;
        j++;
    }
    return ans;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    shuffle(v);
    return 0;
}