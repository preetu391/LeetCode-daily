#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    if (prices.size() == 1)
        return 0;
    int ans = 0, idx = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < prices[idx])
        {
            idx = i;
            continue;
        }
        ans = max(ans, prices[i] - prices[idx]);
    }
    return ans;
}

int main()
{
    return 0;
}