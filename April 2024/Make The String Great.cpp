#include <bits/stdc++.h>
#include <string>
using namespace std;

// Approach 2 Code
class Solution
{
public:
    string makeGood(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            ans += s[i];
            while (ans.size() > 0 && abs(s[i + 1] - ans.back()) == 32)
            {
                ans.pop_back();
                i++;
            }
        }
        return ans;
    }
};

// Approach 3 Code
class Solution2
{
public:
    string makeGood(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (ans.size() == 0 || tolower(s[i]) != tolower(ans.back()) || s[i] == ans.back())
            {
                ans += s[i];
            }
            else
            {
                ans.pop_back();
            }
        }
        return ans;
    }
};