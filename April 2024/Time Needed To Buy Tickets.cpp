#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int ans = 0;
        for (int i = 0; i < tickets.size(); i++)
        {
            if (i <= k)
            {
                if (tickets[i] <= tickets[k])
                {
                    ans += tickets[i];
                }
                else
                {
                    ans += tickets[k];
                }
            }
            else
            {
                if (tickets[i] < tickets[k])
                {
                    ans += tickets[i];
                }
                else
                {
                    ans += tickets[k] - 1;
                }
            }
        }
        return ans;
    }
};