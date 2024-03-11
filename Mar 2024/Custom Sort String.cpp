#include <bits/stdc++.h>
#include <map>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        map<char, int> mp;
        for (char c : order)
            mp[c]++;
        string extra = "";
        for (char c : s)
        {
            if (mp[c] == 0)
                extra += c;
            else
                mp[c]++;
        }
        string ans = "";
        for (char c : order)
        {
            while (mp[c] > 1)
            {
                ans += c;
                mp[c]--;
            }
        }
        return ans + extra;
    }
};

// Using comparator in C++
class Solution2
{
public:
    static string str;
    static bool cmp(char c1, char c2)
    {
        return (str.find(c1) < str.find(c2));
    }
    string customSortString(string order, string s)
    {
        str = order;
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
string Solution2 ::str;