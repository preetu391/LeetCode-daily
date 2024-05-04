#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int cnt = 0;
        int i = 0, j = people.size() - 1;
        while (i <= j)
        {
            if (people[i] + people[j] <= limit)
            {
                cnt++;
                i++;
                j--;
            }
            else
            {
                j--;
                cnt++;
            }
        }
        return cnt;
    }
};