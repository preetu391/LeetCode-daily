#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{
    int start = 1, end = *max_element(piles.begin(), piles.end()), ans = INT_MAX;
    while (start <= end)
    {
        int curr_speed = start + (end - start) / 2;
        if (isFeasible(piles, curr_speed, h))
        {
            ans = min(ans, curr_speed);
            end = curr_speed - 1;
        }
        else
        {
            start = curr_speed + 1;
        }
    }
    return ans;
}
bool isFeasible(vector<int> &piles, int curr_speed, int h)
{
    long long hours = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        hours += piles[i] / curr_speed;
        if (piles[i] % curr_speed)
            hours++;
    }
    return hours <= h;
}

int main()
{
    return 0;
}