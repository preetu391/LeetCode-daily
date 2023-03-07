#include <bits/stdc++.h>
using namespace std;

long long minimumTime(vector<int> &time, int totalTrips)
{
    long long low = 1, high = 1LL * (*min_element(time.begin(), time.end())) * totalTrips, ans = LONG_MAX;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (isFeasible(time, mid, totalTrips))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
bool isFeasible(vector<int> &time, long long mid, int totalTrips)
{
    long long ans = 0;
    for (int i = 0; i < time.size(); i++)
    {
        ans += mid / time[i];
    }
    return ans >= totalTrips;
}

int main()
{
    return 0;
}