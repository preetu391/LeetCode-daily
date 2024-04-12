#include <bits/stdc++.h>
using namespace std;

// using prefix and suffix array
class Solution1
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> pref(n), suff(n);
        pref[0] = height[0];
        int ans = 0;
        suff[n - 1] = height[n - 1];
        for (int i = 1; i < n; i++)
        {
            pref[i] = max(height[i], pref[i - 1]);
            suff[n - 1 - i] = max(height[n - 1 - i], suff[n - i]);
        }
        for (int i = 1; i < n - 1; i++)
        {
            ans += min(pref[i], suff[i]) - height[i];
        }
        return ans;
    }
};
// constant space solution
class Solution2
{
public:
    int trap(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        int maxleft = 0, maxright = 0;
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= maxleft)
                    maxleft = height[left];
                else
                    ans += maxleft - height[left];
                left++;
            }
            else
            {
                if (height[right] >= maxright)
                    maxright = height[right];
                else
                    ans += maxright - height[right];
                right--;
            }
        }
        return ans;
    }
};