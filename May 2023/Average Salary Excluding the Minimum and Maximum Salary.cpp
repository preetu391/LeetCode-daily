#include <bits/stdc++.h>
using namespace std;

double average(vector<int> &salary)
{
    double ans;
    int n = salary.size() - 2;
    sort(salary.begin(), salary.end());
    for (int i = 1; i < salary.size() - 1; i++)
    {
        ans += salary[i];
    }
    ans = ans / n;
    return ans;
}

int main()
{
    return 0;
}